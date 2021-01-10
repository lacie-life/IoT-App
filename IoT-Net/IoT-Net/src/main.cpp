
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "test.h"
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QCoreApplication::addLibraryPath("./");

    QQmlApplicationEngine engine;

    Test test(engine.rootContext());

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    //QObject* rootItem = engine.rootObjects().at(0)->findChild<QObject*>("MyChild");  find cai quan que bo me di
    // m se thay co 2 kieu show window tu c++ la QQuickView vaf QQmlAppEngine
    // QQuickView show duoc 1 window nen no chi tra ve 1 rootObject
    // QQmlAppEngine show duoc nhieu file qml cung luc nen no tra ve mot list QObject, nen de lay cai rootItem thi phai at(0) de lay cai dau tien, du list co moi 1 phan tu

    // the gio lay duoc item roi thi lam gi
    // connect cai signal item do ban ra voi 1 public slots tren c++ ma dung
    // hmm deo duoc
    // de t
    //QObject::connect(rootItem, SIGNAL(testQml(QString)), &test, SLOT(testSignal(QString)));   connect cai bd
    // vai lon day deo tim thay
    // boi vi co nhieu object cung ten thi phai
    //vai lon nhi
    // thoi khong sao
    // trong truong hop nay van la phai dung den bi thuat cao cap


    // OK
    // va m rut ra duoc bai hoc gi o day khong
    // do chinh la dung bao gio ban cai signal cu lon tu QML ve C++
    // deo ai lam vay ca

    // cach de dang nhat do la setContextProperty len ma dung
    // tao 1 Object tren c++
    // setContextProperty
    // va goi ham cua cai Object day nhu bt

    // nhin t lam mau 1 lan thoi day nay

    // ve co ban thi dau tien can tao 1 class trong C++
    // roi setContextProperty
    // xong tren QML se goi cai nay?
    // dung r
    // ham goi duoc phai la public slots hoac Q_INVOKABLE
    // the la cai signal trong qml va signal trong C++ can tach rieng ra a?

    // tach cai gi
    // y m la sao
    //
    return app.exec();
}
