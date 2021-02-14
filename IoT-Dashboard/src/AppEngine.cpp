#include "AppEngine.h"
#include "Constants_Def.h"
#include "Screen_Def.h"
#include "QCircleMeter.h"
#include "QChart.h"
#include "AppEnums.h"

ScreenDef* ScreenDef::m_instance = nullptr;
QMutex ScreenDef::m_lock;
Constants_Def* Constants_Def::m_instance = nullptr;
QMutex Constants_Def::m_lock;

AppEngine::AppEngine(QObject *parent)
    : QObject{ parent }
    , m_model { new AppModel() }
{
    m_context = m_engine.rootContext();
    QQmlEngine::setObjectOwnership(m_model, QQmlEngine::CppOwnership);
}

AppEngine::~AppEngine()
{
//    DELETE_DEFS;
//    DELETE_SCR_DEF;

}

// all context properties from cpp is set in this method
void AppEngine::prepareApplication()
{
    // register class
    qmlRegisterType<QCircleMeter>("QmlCustomItem", 1, 0, "QCircleMeter");
    qmlRegisterType<QChart>("QmlCustomItem", 1, 0, "QChart");
    qmlRegisterUncreatableType<AppEnums>("QmlCustomItem", 1, 0, "ENUMS", "Uncreatable");

    // set context properties
    m_context->setContextProperty("CONST", DEFS);
    m_context->setContextProperty("SCREEN", SCR_DEF);

    m_context->setContextProperty("AppModel", m_model);

}

void AppEngine::runApplication()
{
    m_engine.load(SCR_DEF->QML_APP());
}
