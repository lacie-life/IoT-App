#include "AppModel.h"
#include "Screen_Def.h"
#include <QDebug>

AppModel* AppModel::m_instance = nullptr;
QMutex AppModel::m_lock;

#define db qDebug()

AppModel::AppModel(QObject *parent)
    : QObject(parent)
    , m_currentScreenID {static_cast<int>(AppEnums::HomeScreen)}
{
}

AppModel *AppModel::getInstance()
{
    m_lock.lock();
    if (nullptr == m_instance)
    {
        m_instance = new AppModel();
    }
    m_lock.unlock();
    return m_instance;
}

int AppModel::currentScreenID() const
{
    return m_currentScreenID;
}

void AppModel::qmlEventHandler(int event)
{
    switch (event) {
    case static_cast<int>(AppEnums::UserClickSearch):
        setCurrentScreenID(AppEnums::SearchScreen);
        break;
    case static_cast<int>(AppEnums::UserClickHome):
        setCurrentScreenID(AppEnums::HomeScreen);
        break;
    case static_cast<int>(AppEnums::UserClickControl):
    case static_cast<int>(AppEnums::UserClickMap):
    case static_cast<int>(AppEnums::UserClickAccount):
    default:
        // default case
        break;
    }
}

void AppModel::setCurrentScreenID(int currentScreenID)
{
    if (m_currentScreenID == currentScreenID)
        return;

    m_currentScreenID = currentScreenID;
    emit currentScreenIDChanged(m_currentScreenID);
}


