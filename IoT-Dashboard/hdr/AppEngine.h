#ifndef APPENGINE_H
#define APPENGINE_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "Model/Constants_Def.h"

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
