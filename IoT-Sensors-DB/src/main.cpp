#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "qmongodb.h"
#include <iostream>
#include <QDebug>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    QMongoDB test;
    test.initHosting();
    qDebug() << test.Nodes.size();
    for (int i = 0; i < test.Nodes.size(); i++){
        qDebug() << i << "-" << test.Nodes.at(i).database << "-" << test.Nodes.at(i).collection;
    }

    return app.exec();
}
