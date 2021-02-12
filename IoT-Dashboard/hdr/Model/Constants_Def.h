#ifndef CONSTANT_DEF_H
#define CONSTANT_DEF_H

#include <QObject>
#include <QString>
#include <QUrl>
#include <QColor>
#include <QMutex>

#ifndef MACRO_DEFINE
#define MACRO_DEFINE

#define DEF_VAR(type, name, value) Q_PROPERTY(type name READ name NOTIFY dataUpdate) \
    public: type name() { return value; }

#define DEF_CONST(type, name, value) Q_PROPERTY(type name READ name CONSTANT) \
    public: type name() const { return value; }

#endif

#define DEFS Constants_Def::instance()
#define DELETE_DEFS Constants_Def::DestroyInstance()

class Constants_Def : public QObject
{
    Q_OBJECT

    static Constants_Def* m_instance;
    static QMutex m_lock;

signals:
    void dataUpdated();

public:
    static Constants_Def* instance()
    {
        m_lock.lock();
        if (nullptr == m_instance)
        {
            m_instance = new Constants_Def();
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
    explicit Constants_Def(QObject* parent = nullptr)
        : QObject{ parent }
    { }
    ~Constants_Def() {}
    Constants_Def(const Constants_Def&) = delete;
    bool operator= (const Constants_Def&) = delete ;


    // define property
    // general
    DEF_CONST(int, MAX_WIDTH, 640)
    DEF_CONST(int, MAX_HEIGHT, 480)

    // constant color
    DEF_CONST(QColor, SWITCH_OFF_COLOR, "#ADADAD")
    DEF_CONST(QColor, SWITCH_ON_COLOR, "#00CCD9")
    DEF_CONST(QColor, SWITCH_BTN_NOOD, "#F0F0F0")

    // QChart define
    DEF_CONST(int, DRAW_OFFSET, 10)
};

#endif // CONSTANT_DEF_H
