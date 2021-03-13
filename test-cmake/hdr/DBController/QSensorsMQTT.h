#ifndef SENSORSMQTT_H
#define SENSORSMQTT_H

#include <QObject>
#include <QVector>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QFile>

#include <QMqttClient>

const std::string device_path = "devices.json";
const std::string broker_path = "broker.json";

struct SensorNode{
    QString topic_data;
    QString topic_control;
    QString token;
    QString mac_address;
};

class QSensorsMQTT : public QObject
{
    Q_OBJECT
public:
    QSensorsMQTT();
    ~QSensorsMQTT();

    int initBrokerHost();
    int loadSensorsParamenters(int index = 0);
    void publish(SensorNode node, QString mess);
    void subcrib(SensorNode node);

    QVector<QString> brokerHosts;
    QVector<SensorNode> sensorsNode;

private:
    QMqttClient *m_client;
    int m_current_device;
    QString m_current_sub;
    QString m_current_pub;

    void connectMQTT(QString brokerName, qint16 port);

};

#endif // SENSORSMQTT_H
