#include "../hdr/AppEngine.h"
#include "../hdr/Model/Constants_Def.h"
#include "../hdr/View/Screen_Def.h"
#include "../hdr/Plugin/QCircleMeter.h"
#include "../hdr/Plugin/QChart.h"
#include "../hdr/Model/AppEnums.h"

ScreenDef* ScreenDef::m_instance = nullptr;
QMutex ScreenDef::m_lock;
Constants_Def* Constants_Def::m_instance = nullptr;
QMutex Constants_Def::m_lock;

AppEngine::AppEngine(QObject *parent)
    : QObject{ parent }
{
    m_context = m_engine.rootContext();
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

    m_context->setContextProperty("AppModel", MODEL);

}

void AppEngine::runApplication()
{
    m_engine.load(SCR_DEF->QML_APP());
}
