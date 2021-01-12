#ifndef CONSTANT_DEF_H
#define CONSTANT_DEF_H

#include <QObject>
#include <QString>
#include <QUrl>
#include <QColor>
#include <QMutex>

#ifndef MACRO_DEFINE
#define MACRO_DEFINE

#define DEF_STRING(name, value) Q_PROPERTY(QString name READ name NOTIFY dataUpdated) \
    public: QString name() const { return value; }

#define DEF_INT(name, value) Q_PROPERTY(int name READ name CONSTANT) \
    public: int name() const { return value; }

#define DEF_FLOAT(name, value) Q_PROPERTY(double name READ name CONSTANT) \
    public: double name() const { return value; }

#define DEF_BOOL(name, value) Q_PROPERTY(bool name READ name CONSTANT) \
    public: bool name() const { return value; }

#define DEF_TYPE(type, name, value) Q_PROPERTY(type name READ name CONSTANT) \
    public: type name() const { return value; }

#endif

#define CONST_MODEL Constants_Def::instance()

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
    DEF_INT(MAX_WIDTH, 640)
    DEF_INT(MAX_HEIGHT, 480)

    // constant URL
    DEF_TYPE(QUrl, MAIN_QML_URL, QStringLiteral("qrc:/Qml/main.qml"))

    // constant color
    DEF_TYPE(QColor, SWITCH_OFF_COLOR, "#ADADAD")
    DEF_TYPE(QColor, SWITCH_ON_COLOR, "#00CCD9")
    DEF_TYPE(QColor, SWITCH_BTN_NOOD, "#F0F0F0")
};

#endif // CONSTANT_DEF_H
