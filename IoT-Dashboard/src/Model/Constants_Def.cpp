#include "../../Hdr/Model/Constants_Def.h"

Constants_Def* Constants_Def::m_instance = nullptr;
QMutex Constants_Def::m_lock;

Constants_Def::Constants_Def(QObject *parent)
    : QObject{ parent }
{

}

Constants_Def *Constants_Def::instance()
{
    m_lock.lock();
    if (nullptr == m_instance)
    {
        m_instance = new Constants_Def();
    }
    m_lock.unlock();
    return m_instance;
}

Constants_Def::~Constants_Def()
{
    if (nullptr == m_instance)
    {
        delete m_instance;
        m_instance = nullptr;
    }
}
