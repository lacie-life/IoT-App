#ifndef APPMODEL_H
#define APPMODEL_H

#include <QObject>
#include <QString>
#include <QMutex>

//#define MODEL AppModel::getInstance()

class AppModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString currentScreen READ currentScreen WRITE setCurrentScreen NOTIFY currentScreenChanged)
public:
//    static AppModel *getInstance();
    AppModel(QObject* parent = nullptr);

    void setCurrentScreen(QString currentScreen);
public slots:
    QString currentScreen() const;
    void qmlTriggerHandler(int event);

signals:
    void currentScreenChanged(QString currentScreen);

private:
//    AppModel(const AppModel& ) = delete;
//    void operator =(const AppModel& ) = delete;

//    static AppModel* m_instance;
//    static QMutex m_lock;
    QString m_currentScreen;
};

#endif // APPMODEL_H
