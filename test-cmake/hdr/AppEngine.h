#ifndef APPENGINE_H
#define APPENGINE_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "Model/AppEnums.h"
#include "Model/AppModel.h"

class AppEngine : public QObject
{
    Q_OBJECT
    QQmlContext* m_context;
    QQmlApplicationEngine m_engine;
public:
    explicit AppEngine(QObject *parent = nullptr);
    ~AppEngine();

    void prepareApplication();
    void runApplication();

signals:

};

#endif // APPENGINE_H
