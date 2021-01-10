#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QQmlContext>

class Test : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString color READ color WRITE setColor NOTIFY colorChanged)
    QString m_color;
    QQmlContext *m_context;

public:
    explicit Test(QObject *parent = nullptr);
    Test(QQmlContext *context);

    QString color() const;

public slots:
    void setColor(QString color);
    void testSignal(QString data); // de tren QML dung duoc ham cua c++ thi ham do phai la public slots hoac Q_INVOKABLE
    // 2 ham tren deu laf publick slots, tuc la m goi thoai mai tren QML
    // hoac nhu nay
    Q_INVOKABLE void testFunctionCpp(QString color); // nho co kieu return, tu khi co cai macro kia t toan quen me no kieu return
signals:
    void colorChanged();
    void sendColorToQml(QString color);
};

#endif // TEST_H
