#ifndef APPENGINE_H
#define APPENGINE_H

#include <QObject>
#include "Model/Constants_Def.h"

class AppEngine : public QObject
{
    Q_OBJECT
public:
    explicit AppEngine(QObject *parent = nullptr);

signals:

};

#endif // APPENGINE_H
