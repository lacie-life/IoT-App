#include "../hdr/AppEngine.h"

AppEngine::AppEngine(QObject *parent)
    : QObject{ parent }
{
    m_context = m_engine.rootContext();
}

// all context properties from cpp is set in this method
void AppEngine::prepareApplication()
{
    // register class
    qmlRegisterType<QCircleMeter>("QmlCustomItem", 1, 0, "QCircleMeter");

    // set context properties
    m_context->setContextProperty("CONST", CONST_MODEL);


}

void AppEngine::runApplication()
{
    m_engine.load(MAIN_SCREEN);

}
