#ifndef CONSTANT_DEF_H
#define CONSTANT_DEF_H

#include <QObject>
#include <QString>
#include <QUrl>
#include <QColor>
#include <QMutex>
#include <QCoreApplication>

#ifndef MACRO_DEFINE
#define MACRO_DEFINE

#define DEF_VAR(type, name, value) Q_PROPERTY(type name READ name NOTIFY dataUpdate) \
    public: type name() { return value; }

#define DEF_CONST(type, name, value) Q_PROPERTY(type name READ name CONSTANT) \
    public: type name() const { return value; }

#endif

#define DEFS Constants_Def::instance()
#define DELETE_DEFS Constants_Def::DestroyInstance()

#ifndef BUILD_DIR
#define BUILD_DIR QCoreApplication::applicationDirPath()
#endif

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

    /******************************************* RESOURCE ************************************************/

    // QML

    // IMAGES
    DEF_CONST(QString, IMAGE_FOLDER , BUILD_DIR + "/share/res/")
    DEF_CONST(QString, SEARCH_IMG   , "search.svg"  )
    DEF_CONST(QString, HOME_IMG     , "home.svg"    )
    DEF_CONST(QString, CONTROL_IMG  , "control.svg" )
    DEF_CONST(QString, MAP_IMG      , "map.svg"     )
    DEF_CONST(QString, USER_IMG     , "user.svg"    )


    /********************************************** GENERAL **********************************************/
    DEF_CONST(int, MAX_WIDTH        , 1280  )
    DEF_CONST(int, MAX_HEIGHT       , 680   )
    DEF_CONST(int, MENU_BAR_WIDTH   , 80    )

    // search screen constant
    DEF_CONST(int, INPUT_BOX_WIDTH      , 1100  )
    DEF_CONST(int, INPUT_BOX_HEIGHT     , 60    )
    DEF_CONST(int, INPUT_BOX_TOP_MARGIN , 20    )

    // constant color
    DEF_CONST(QColor, SWITCH_OFF_COLOR, "#ADADAD")
    DEF_CONST(QColor, SWITCH_ON_COLOR , "#00CCD9")
    DEF_CONST(QColor, SWITCH_BTN_NOOD , "#F0F0F0")

    DEF_CONST(QColor, MENU_BAR_COLOR        , "#00AF2A")
    DEF_CONST(QColor, MENU_BAR_FOCUS_COLOR  , "#DDDDDD")
    DEF_CONST(QColor, BACK_GROUND_COLOR     , MENU_BAR_FOCUS_COLOR())

    DEF_CONST(QString, INVISIBLE       , "transparent")

    // QChart define
    DEF_CONST(int, DRAW_OFFSET, 10)
};

#endif // CONSTANT_DEF_H
