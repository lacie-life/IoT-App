#ifndef APPMODEL_H
#define APPMODEL_H

#include <QObject>
#include <QMutex>

class AppModel : public QObject
{
    Q_OBJECT
public:
    static AppModel *getInstance();

private:
    AppModel(QObject* parent = nullptr);
    AppModel(const AppModel& ) = delete;
    void operator =(const AppModel& ) = delete;

    static AppModel* m_instance;
    static QMutex m_lock;
};

#endif // APPMODEL_H
