#ifndef APPMODEL_H
#define APPMODEL_H

#include <QObject>
#include <QString>
#include <QMutex>
#include "AppEnums.h"

//#define MODEL AppModel::getInstance()

class AppModel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int currentScreenID READ currentScreenID WRITE setCurrentScreenID NOTIFY currentScreenIDChanged)
public:
//    static AppModel *getInstance();
    AppModel(QObject* parent = nullptr);
    Q_INVOKABLE void qmlTriggerHandler(int event);

    int currentScreenID() const;

public slots:
    void setCurrentScreenID(int currentScreenID);

signals:
    void currentScreenIDChanged(int currentScreenID);

private:
//    AppModel(const AppModel& ) = delete;
//    void operator =(const AppModel& ) = delete;

//    static AppModel* m_instance;
//    static QMutex m_lock;
    int m_currentScreenID;
};

#endif // APPMODEL_H
