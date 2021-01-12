#include "../hdr/AppEngine.h"

AppEngine::AppEngine(QObject *parent)
    : QObject{ parent }
{
    m_context = m_engine.rootContext();
}

// all context properties from cpp is set in this method
void AppEngine::prepareApplication()
{
    m_context->setContextProperty("CONST", CONST_MODEL);


}

void AppEngine::runApplication()
{
    m_engine.load(CONST_MODEL->MAIN_QML_URL());

}
