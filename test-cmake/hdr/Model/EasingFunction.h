#ifndef EASINGFUNCTION_H
#define EASINGFUNCTION_H

#include <QtMath>

#ifndef DEFINE_CONST
#define DEFINE_CONST
#define Q_PI 3.141592654
#endif

#define EASE EasingFunction::instance()

class EasingFunction
{
    static EasingFunction* m_instance;

    EasingFunction();
    EasingFunction(const EasingFunction&) = delete;
    void operator= (const EasingFunction&) = delete;

public:
    static EasingFunction *instance();
    ~EasingFunction();

    // in
    qreal func_InBounce(qreal x);
    qreal func_InSine(qreal x);
    qreal func_InQuad(qreal x);
    qreal func_InQuint(qreal x);
    qreal func_InQuart(qreal x);
    qreal func_InCubic(qreal x);
    qreal func_InExpo(qreal x);
    qreal func_InCirc(qreal x);
    qreal func_InBack(qreal x);
    qreal func_InElasic(qreal x);

    // out
    qreal func_OutBounce(qreal x);
    qreal func_OutSine(qreal x);
    qreal func_OutQuad(qreal x);
    qreal func_OutQuint(qreal x);
    qreal func_OutQuart(qreal x);
    qreal func_OutCubic(qreal x);
    qreal func_OutExpo(qreal x);
    qreal func_OutCirc(qreal x);
    qreal func_OutBack(qreal x);
    qreal func_OutElasic(qreal x);


    // in out
    qreal func_InOutBounce(qreal x);
    qreal func_InOutSine(qreal x);
    qreal func_InOutQuad(qreal x);
    qreal func_InOutQuint(qreal x);
    qreal func_InOutQuart(qreal x);
    qreal func_InOutCubic(qreal x);
    qreal func_InOutExpo(qreal x);
    qreal func_InOutCirc(qreal x);
    qreal func_InOutBack(qreal x);
    qreal func_InOutElasic(qreal x);

private:
    void modify(qreal& number);


};

#endif // EASINGFUNCTION_H
