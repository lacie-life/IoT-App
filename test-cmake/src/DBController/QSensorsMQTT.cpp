#include "../../hdr/DBController/QSensorsMQTT.h"

QSensorsMQTT::QSensorsMQTT(){}

QSensorsMQTT::~QSensorsMQTT(){}

int QSensorsMQTT::initBrokerHost()
{
    QFile f(broker_path.c_str());
    f.open(QIODevice::ReadOnly | QIODevice::Text);
    QString val = f.readAll();
    QJsonArray array = QJsonDocument::fromJson(val.toUtf8()).array();
    for(int i = 0; i < array.size(); i++){
        QJsonObject t_obj = array[i].toObject();
        brokerHosts.push_back(t_obj["hostname"].toString());
//        qDebug()<< i << "-" <<hostnames[i];
    }
    return 0;
}

int QSensorsMQTT::loadSensorsParamenters()
{
    QFile file(device_path.c_str());
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString val = file.readAll();
    file.close();
    QJsonArray a = QJsonDocument::fromJson(val.toUtf8()).array();

    for (int i = 0; i < a.count(); ++i) {
        QJsonValue v = a[i];
        SensorNode node;
        node.topic_data = v["topic-sensor"].toString();
        node.topic_control = v["topic-control"].toString();
        node.token = v["token"].toString();
        node.mac_address = v["mac_address"].toString();
        sensorsNode.push_back(node);
    }
    return 0;
}

void QSensorsMQTT::publish(SensorNode node, QString mess)
{
    m_current_pub = node;
    m_client->publish(node.topic_control, mess.toUtf8());
}

void QSensorsMQTT::subcrib(SensorNode node)
{
    m_client->unsubscribe(m_current_sub.topic_data);
    m_current_device = node;
    m_current_sub = node;
    auto sub = m_client->subscribe(m_current_sub.topic_data, quint8(2));
    if (!sub){
        qDebug() << "Could not subcribe. Is there avalid connection?";
    }
}

void QSensorsMQTT::connectMQTT(QString brokerName, qint16 port)
{
    m_client = new QMqttClient();
    m_client->setHostname(brokerName);
    m_client->setPort(port);
    m_client->connectToHost();
}
