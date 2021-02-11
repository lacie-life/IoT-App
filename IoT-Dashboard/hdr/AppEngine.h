#ifndef APPENGINE_H
#define APPENGINE_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "Constants_Def.h"
#include "Screen_Def.h"
#include "QCircleMeter.h"
#include "QChart.h"
#include "QChart_Enums.h"

class AppEngine : public QObject
{
    Q_OBJECT
    QQmlContext* m_context;
    QQmlApplicationEngine m_engine;
public:
    explicit AppEngine(QObject *parent = nullptr);
    void prepareApplication();
    void runApplication();

signals:

};

#endif // APPENGINE_H
