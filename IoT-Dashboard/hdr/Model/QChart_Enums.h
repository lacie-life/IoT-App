#ifndef QCHART_ENUMS_H
#define QCHART_ENUMS_H

#include <QObject>

class QChart_Enums : public QObject
{
    Q_OBJECT
    Q_ENUMS(Chart)
    Q_ENUMS(EasingType)

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

        InOutSine,      // 1
//        OutSine,
//        InSine,

//        InOutBack,      // 4
//        OutBack,
//        InBack,

//        InOutQuad,      // 7
//        OutQuad,
//        InQuad,

//        InOutCirc,      // 10
//        OutCirc,
//        InCirc,

//        InOutExpo,      // 13
//        OutExpo,
//        InExpo,

//        InOutElastic,   // 16
//        OutElastic,
//        InElastic,

//        InOutCubic,     // 19
//        OutCubic,
//        InCubic,

//        InOutQuint,     // 22
//        OutQuint,
//        InQuint,

//        InOutQuart,     // 25
//        OutQuart,
//        InQuart,

//        InOutBounce,    // 28
//        OutBounce,
//        InBounce,
    };
};

#endif // QCHART_ENUMS_H
