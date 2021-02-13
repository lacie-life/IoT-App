#ifndef SCREEN_DEF_H
#define SCREEN_DEF_H

#include <QObject>
#include <QString>
#include <QMutex>
#include <QDebug>

#ifndef SCREEN_DEF_MACROS
#define SCREEN_DEF_MACROS

#define DEF_SCREEN(screenName, link) Q_PROPERTY(QString screenName READ screenName CONSTANT) \
    public: QString screenName() const { return QString(link); }

#endif

#define SCR_DEF ScreenDef::getInstance()
#define DELETE_SCR_DEF ScreenDef::DestroyInstance()

class ScreenDef : public QObject
{
    Q_OBJECT
    static ScreenDef* m_instance;
    static QMutex m_lock;
public:
    static ScreenDef* getInstance()
    {
        m_lock.lock();
        if (nullptr == m_instance)
        {
            m_instance = new ScreenDef;
        }
        m_lock.unlock();
        return m_instance;
    }

    static void DestroyInstance()
    {
        m_lock.lock();
        if (nullptr != m_instance)
        {
            delete m_instance;
        }
        m_instance = nullptr;
        m_lock.unlock();
    }

private:
    ScreenDef(QObject* parent = nullptr)
        : QObject(parent) {}
    ~ScreenDef() {}
    ScreenDef(const ScreenDef&) = delete;
    void operator =(const ScreenDef&) = delete;

    // define screen goes here
    DEF_SCREEN(QML_MAIN_APP, "qrc:/qml/main.qml")
    DEF_SCREEN(QML_MAIN_SCREEN, "qrc:/qml/MainScreen.qml")
    DEF_SCREEN(QML_TEST, "qrc:/qml/TestScreen.qml")

    // detail screen
    DEF_SCREEN(QML_HOME, "qrc:/qml/Screen/HomeScreen.qml")
    DEF_SCREEN(QML_SEARCH, "qrc:/qml/Screen/SearchScreen.qml")
};

#endif // SCREEN_DEF_H
