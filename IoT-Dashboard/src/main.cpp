#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "Hdr/AppEngine.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    AppEngine appEngine;
    appEngine.prepareApplication();
    appEngine.runApplication();

    return app.exec();
}
