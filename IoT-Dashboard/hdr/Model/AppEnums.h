#ifndef APPENUMS_H
#define APPENUMS_H

#include <QObject>
#include <QHash>

class AppEnums : public QObject
{
    Q_OBJECT
    Q_ENUMS(Chart)
    Q_ENUMS(EasingType)
    Q_ENUMS(ScreenType)

public:
    enum Chart
    {
        NoGrid = 0,
        XGrid,
        YGrid,
        Grid,
    };

    enum EasingType
    {
        Linear = 0,
        InOutSine,
    };

    enum ScreenType
    {
        SearchScreen = 0,
        HomeScreen,
        ControlScreen,
        MapScreen,
        UserScreen,
    };
};



#endif // APPENUMS_H
