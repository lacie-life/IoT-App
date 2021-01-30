#ifndef SENSORSMQTT_H
#define SENSORSMQTT_H

#include <QObject>
#include <QVector>

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

    QVector<QString> brokerHosts;
    QVector<SensorNode> sensorsNode;

};

#endif // SENSORSMQTT_H
