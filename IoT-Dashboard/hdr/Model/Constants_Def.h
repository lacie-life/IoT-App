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

class Constants_Def : public QObject
{
    Q_OBJECT

    explicit Constants_Def(QObject* parent = nullptr);
    Constants_Def(Constants_Def &_Other) = delete;
    bool operator= (Constants_Def &_Other) = delete ;

    static Constants_Def* m_instance;
    static QMutex m_lock;

signals:
    void dataUpdated();

public:
    static Constants_Def* instance();
    ~Constants_Def();

    // define property
private:
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
