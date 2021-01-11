#ifndef CONSTANT_DEF_H
#define CONSTANT_DEF_H

#include <QObject>



#define CONSTANT Constants_Def::instance()

class Constants_Def : public QObject
{
    Q_OBJECT
    explicit Constants_Def(QObject* parent = nullptr);
    Constants_Def(Constants_Def &_Other) = delete;
    bool operator= (Constants_Def &_Other) = delete ;

    static Constants_Def* m_instance;
public:
    static Constants_Def* instance();
    ~Constants_Def();
};

#endif // CONSTANT_DEF_H
