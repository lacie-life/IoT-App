#include "test.h"
#include <QDebug>

Test::Test(QObject *parent) : QObject(parent)
{

}

Test::Test(QQmlContext *context) :
    m_color{"red"}
  , m_context{context}
{
    m_context->setContextProperty("MyColor", this);
    // da set doan nay roi thi ko can set tiep nua
    // tru khi m set 1 lisst leen va list day thay doi thi can set lai de update
    // sau nay co co hoi thi t noi
}

QString Test::color() const
{
    return m_color;
}

void Test::setColor(QString color)
{
    if (m_color == color)
        return;

    m_color = color;
    emit colorChanged();
}

void Test::testSignal(QString data)
{
    qDebug() << data;
}

void Test::testFunctionCpp(QString color)
{
    qDebug() << "C++ day: data day : " << color;
    emit sendColorToQml(color);
    // dung tu khoa emit de ban signal cho tuong minh, khong dung cung duoc, nhung nen dung de bao h search cai la ra
    // ctrl shift F
    // emit
    // the la tim duoc tat ca signal m ban

    // day, vi du t co mai ham nay
    // ! thang QML se dung cai ham nay,
    // cai ham nay lai ban ra 1 signal
    // mot thang qml nao do lai bat duoc cai signal nay
}
