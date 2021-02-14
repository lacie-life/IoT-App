#include "AppModel.h"
#include "AppEnums.h"
#include "Screen_Def.h"
#include <QDebug>

//AppModel* AppModel::m_instance = nullptr;
//QMutex AppModel::m_lock;

#define db qDebug()

AppModel::AppModel(QObject *parent)
    : QObject(parent)
    , m_currentScreen {SCR_DEF->QML_SEARCH()}
{
}

//AppModel *AppModel::getInstance()
//{
//    m_lock.lock();
//    if (nullptr != m_instance)
//    {
//        m_instance = new AppModel();
//    }
//    m_lock.unlock();
//    return m_instance;
//}

QString AppModel::currentScreen() const
{
    return m_currentScreen;
}

void AppModel::setCurrentScreen(QString currentScreen)
{
    if (m_currentScreen == currentScreen)
        return;

    m_currentScreen = currentScreen;
    emit currentScreenChanged(m_currentScreen);
}

void AppModel::qmlTriggerHandler(int event)
{
    switch (event) {
    case static_cast<int>(AppEnums::UserClickSearch):
        setCurrentScreen(SCR_DEF->QML_SEARCH());
        break;
    case static_cast<int>(AppEnums::UserClickHome):
        setCurrentScreen(SCR_DEF->QML_HOME());
        break;
    case static_cast<int>(AppEnums::UserClickControl):
    case static_cast<int>(AppEnums::UserClickMap):
    case static_cast<int>(AppEnums::UserClickAccount):
    default:
        break;
    }
}


