#include "EasingFunction.h"

EasingFunction *EasingFunction::m_instance = nullptr;
EasingFunction::EasingFunction() {}

EasingFunction *EasingFunction::instance()
{
    if (nullptr == m_instance)
    {
        m_instance = new EasingFunction();
    }
    return m_instance;
}

EasingFunction::~EasingFunction()
{
    if (nullptr != m_instance)
    {
        delete m_instance;
    }
    m_instance = nullptr;
}

qreal EasingFunction::func_InBounce(qreal x)
{
    qreal y = 1 - func_OutBounce(1 - x);
    return y;
}

qreal EasingFunction::func_InSine(qreal x)
{
    modify(x);
    qreal y = 1 - qCos(x * Q_PI / 2);
    return y;
}

qreal EasingFunction::func_InQuad(qreal x)
{
    modify(x);
    qreal y = x*x;
    return y;
}

qreal EasingFunction::func_InQuint(qreal x)
{
    modify(x);
    qreal y = x*x*x*x;
    return y;
}

qreal EasingFunction::func_InQuart(qreal x)
{
    modify(x);
    qreal y = x*x*x*x;
    return y;
}

qreal EasingFunction::func_InCubic(qreal x)
{
    modify(x);
    qreal y = x*x*x;
    return y;
}

qreal EasingFunction::func_InExpo(qreal x)
{
    modify(x);
    qreal y;
    if (x == 0)
    {
        y = 0;
    }
    else
    {
        y = qPow(2, 10 * x - 10);
    }
    return y;
}

qreal EasingFunction::func_InCirc(qreal x)
{
    modify(x);
    qreal y = 1 - qSqrt(1 - qPow(x, 2));
    return y;
}

qreal EasingFunction::func_InBack(qreal x)
{
    modify(x);
    const qreal c1 = 1.70158;
    const qreal c2 = c1 + 1;

    qreal y = c2 * x * x * x - c1 * x * x;
    return y;
}

qreal EasingFunction::func_InElasic(qreal x)
{
    modify(x);
    const qreal c = (2 * Q_PI) / 3;
    qreal y;
    if (x == 0)
    {
        y = 0;
    }
    else if (x == 1)
    {
        y = 1;
    }
    else
    {
        y = -qPow(2, 10 * x - 10) * qSin((x * 10 - 10.75) * c);
    }
    return y;
}

qreal EasingFunction::func_OutBounce(qreal x)
{
    modify(x);
    const qreal n1 = 7.5625;
    const qreal d1 = 2.75;

    qreal y;
    if (x < (1 / d1))
    {
        y = n1 * x * x;
    }
    else if (x < (2 / d1))
    {
        qreal x1 = x - 1.5 / d1;
        y = n1 * x1 * x1 + 0.75;
    }
    else if (x < (2.5 / d1))
    {
        qreal x1 = x - 2.25 / d1;
        y = n1 * x1 * x1 + 0.9375;
    }
    else
    {
        qreal x1 = x - 2.625 / d1;
        y = n1 * x1 * x1 + 0.984375;
    }

    return y;
}

qreal EasingFunction::func_InOutSine(qreal x)
{
    modify(x);
    return qPow(qSin(Q_PI * x / 2), 2);
}

qreal EasingFunction::func_InOutBack(qreal x)
{
    modify(x);
    const qreal c1 = 1.70158;
    const qreal c2 = c1 + 1.525;

    qreal y;
    if (x < 0.5) y = (qPow(2*x, 2)*((c2 + 1)*2 * x - c2)) / 2;
    else
        y = (qPow(2*x - 2, 2)*((c2 + 1)*(x*2 - 2) + c2) + 2) / 2;

    return y;
}

qreal EasingFunction::func_InOutQuad(qreal x)
{
    modify(x);
    qreal y;
    if (x < 0.5) y = 2*x*x;
    else
        y = 1 - qPow(-2*x+2, 2)/2;
    return y;
}

qreal EasingFunction::func_InOutExpo(qreal x)
{
    modify(x);
    qreal y;
    if (x < 0.5) y = qPow(2, 20*x - 10) / 2;
    else
        y = (2 - qPow(2, -20*x + 10)) / 2;
    return y;
}

qreal EasingFunction::func_InOutBounce(qreal x)
{
    modify(x);
    qreal y;
    if (x < 0.5)
    {
        y = (1 - func_OutBounce(1 - 2*x)) / 2;
    }
    else
    {
        y = (1 + func_OutBounce(2*x - 1)) / 2;
    }
    return y;
}

void EasingFunction::modify(qreal& number)
{
    if (number > 1) number = 1;
    if (number < 0) number = 0;
}
