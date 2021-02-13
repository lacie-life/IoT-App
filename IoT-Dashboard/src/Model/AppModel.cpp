#include "AppModel.h"

AppModel* AppModel::m_instance = nullptr;
QMutex AppModel::m_lock;

AppModel *AppModel::getInstance()
{
    if (nullptr != m_instance)
    {
        m_instance = new AppModel;
    }
    return m_instance;
}

AppModel::AppModel(QObject *parent)
    : QObject(parent) {}
