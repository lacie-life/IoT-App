#include "QChart.h"
#include "Constants_Def.h"
#include <QDebug>
#include <QtMath>
#include <QPainterPath>

#define db qDebug()

QChart::QChart(QQuickItem *parent)
    : QQuickPaintedItem(parent)
    , m_xAxis{"xAxis"}
    , m_yAxis{"yAxis"}
    , m_axisThickness{5}
    , m_lineThickness{1}
    , m_dotThickness{6}
    , m_xAxisDiv{5}
    , m_yAxisDiv{5}
    , m_gridMode{AppEnums::NoGrid}
    , m_backgroundColor{DEFAULT_BG_COLOR}
    , m_dotColor{DEFAULT_DOT_COLOR}
    , m_axisColor{DEFAULT_AXIS_COLOR}
    , m_lineColor{DEFAULT_LINE_COLOR}
    , m_xMax{100}
    , m_xMin{0}
    , m_yMax{100}
    , m_yMin{0}
    , m_easingType{AppEnums::Linear}

{
}

void QChart::paint(QPainter *painter)
{
    QBrush brushBackground(m_backgroundColor);
    QBrush brushAxis(m_axisColor);
    QBrush brushLine(m_lineColor);
    QBrush brushDot(m_dotColor);

    painter->setPen(Qt::NoPen);
    painter->setRenderHints(QPainter::Antialiasing, true);

    // Draw background
    painter->setBrush(brushBackground);
    painter->drawRect(boundingRect());

    // Draw Axis
    painter->setPen(QPen(brushAxis, m_axisThickness));
    painter->drawLine(boundingRect().x()
                      , boundingRect().y()
                      , boundingRect().x()
                      , boundingRect().y() + boundingRect().height());      // yAxis
    painter->drawLine(boundingRect().x()
                      , boundingRect().y() + boundingRect().height()
                      , boundingRect().x() + boundingRect().width()
                      , boundingRect().y() + boundingRect().height());      // xAxis

    // Draw grid if needed
    if (static_cast<int>(AppEnums::Grid) == m_gridMode
            || static_cast<int>(AppEnums::XGrid) == m_gridMode
            || static_cast<int>(AppEnums::YGrid) == m_gridMode)
    {
        painter->setPen(QPen(brushAxis, 1));
        painter->setOpacity(0.5);
        if ( (m_xAxisDiv > 1 && boundingRect().width() > 50)
                && (static_cast<int>(AppEnums::XGrid) == m_gridMode
                    || static_cast<int>(AppEnums::Grid) == m_gridMode)) // draw xGrid
        {
            qreal distance = (boundingRect().width() - 20) / (m_xAxisDiv);
            for (int i = 0; i <= m_xAxisDiv; i++)
            {
                painter->drawLine(boundingRect().x() + distance * i + DEFS->CHART_DRAW_OFFSET()
                                  , boundingRect().y() + boundingRect().height()
                                  , boundingRect().x() + distance * i + DEFS->CHART_DRAW_OFFSET()
                                  , boundingRect().y());                        //draw xAxis
            }
        }
        if ((m_yAxis > 1 && boundingRect().height() > 50)
                && (static_cast<int>(AppEnums::YGrid) == m_gridMode
                    || static_cast<int>(AppEnums::Grid) == m_gridMode)) // draw yGrid
        {
            qreal distance = (boundingRect().height() - 10) / m_yAxisDiv;
            for (int i = 1; i <= m_yAxisDiv; i++)
            {
                painter->drawLine(boundingRect().x()
                                  , boundingRect().y() + boundingRect().height() - distance * i
                                  , boundingRect().x() + boundingRect().width()
                                  , boundingRect().y() + boundingRect().height() - distance * i);       // draw yAxis
            }
        }
    }

    painter->setPen(Qt::NoPen);
    painter->setOpacity(1);

    // draw dot and line
    if (m_listData.count() > 0)                             // if there are more than or at least one point, then draw it
    {
        qreal distance = (boundingRect().width() - 20) / m_xAxisDiv;

        if (m_listData.count() > 1)                         // if there are more than or at least two points, then draw line
        {
            painter->setPen(QPen(brushLine, m_lineThickness));
            for (int i = 0; i < m_listData.count() - 1; i++)
            {
                drawEasingPath(painter
                               , m_easingType
                               , QPointF(boundingRect().x() + distance * i + DEFS->CHART_DRAW_OFFSET()
                                         , m_mappedList[i])
                               , QPointF(boundingRect().x() + distance * (i + 1) + DEFS->CHART_DRAW_OFFSET()
                                         , m_mappedList[i + 1])
                               , distance
                               , 100);
            }
        }

        painter->setBrush(brushDot);
        painter->setPen(Qt::NoPen);
        for (int i = 0; i < m_listData.count(); i++)
        {
            painter->drawEllipse(QPointF(boundingRect().x() + distance * i + DEFS->CHART_DRAW_OFFSET()
                                         , m_mappedList[i])
                                 , m_dotThickness
                                 , m_dotThickness);                                     // draw dot
        }
    }
}

void QChart::drawEasingPath(QPainter *painter
                            , int easingType
                            , const QPointF& p1, const QPointF& p2
                            , qreal distance
                            , int sample)
{
    if (sample > 100) sample = 100;
    if (sample < 50) sample = 50;
    switch (easingType)
    {
    case static_cast<int>(AppEnums::InOutSine):
    {
        QPointF xp1, xp2;
        qreal dy = p2.y() - p1.y();
        qreal x;
        qreal dx = 1.0 / sample;
        for (int i = 0; i < sample; i++)
        {
            x = i / (1.0 * sample);

            xp1 = QPointF(p1.x() + (x * distance)
                          , EASE->func_InOutSine(x) * dy + p1.y());
            xp2 = QPointF(p1.x() + ((x + dx) * distance)
                          , EASE->func_InOutSine(x + dx) * dy + p1.y());
            painter->drawLine(xp1, xp2);
        }
    }
        break;
    case static_cast<int>(AppEnums::Linear):    // fall through default case
    default:
    {
        painter->drawLine(p1, p2);
    }
        break;
    }
}

QString QChart::xAxis() const
{
    return m_xAxis;
}

QString QChart::yAxis() const
{
    return m_yAxis;
}

int QChart::axisThickness() const
{
    return m_axisThickness;
}

qreal QChart::xMax() const
{
    return m_xMax;
}

qreal QChart::xMin() const
{
    return m_xMin;
}

qreal QChart::yMax() const
{
    return m_yMax;
}

qreal QChart::yMin() const
{
    return m_yMin;
}

int QChart::easingType() const
{
    return m_easingType;
}

QColor QChart::backgroundColor() const
{
    return m_backgroundColor;
}

QColor QChart::dotColor() const
{
    return m_dotColor;
}

QColor QChart::axisColor() const
{
    return m_axisColor;
}

QColor QChart::lineColor() const
{
    return m_lineColor;
}

int QChart::lineThickness() const
{
    return m_lineThickness;
}

int QChart::dotThickness() const
{
    return m_dotThickness;
}

int QChart::xAxisDiv() const
{
    return m_xAxisDiv;
}

int QChart::yAxisDiv() const
{
    return m_yAxisDiv;
}

int QChart::gridMode() const
{
    return m_gridMode;
}

void QChart::setXAxis(QString xAxis)
{
    if (m_xAxis == xAxis)
        return;

    m_xAxis = xAxis;
    emit xAxisChanged(m_xAxis);
}

void QChart::setYAxis(QString yAxis)
{
    if (m_yAxis == yAxis)
        return;

    m_yAxis = yAxis;
    emit yAxisChanged(m_yAxis);
}

void QChart::setAxisThickness(int axisThickness)
{
    if (m_axisThickness == axisThickness)
        return;

    m_axisThickness = axisThickness;
    emit axisThicknessChanged(m_axisThickness);
}

void QChart::setBackgroundColor(QColor backgroundColor)
{
    if (m_backgroundColor == backgroundColor)
        return;

    m_backgroundColor = backgroundColor;
    emit backgroundColorChanged(m_backgroundColor);
}

void QChart::setXMax(qreal xMax)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_xMax, xMax))
        return;

    m_xMax = xMax;
    emit xMaxChanged(m_xMax);
}

void QChart::setXMin(qreal xMin)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_xMin, xMin))
        return;

    m_xMin = xMin;
    emit xMinChanged(m_xMin);
}

void QChart::setYMax(qreal yMax)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_yMax, yMax))
        return;

    m_yMax = yMax;
    emit yMaxChanged(m_yMax);
}

void QChart::setYMin(qreal yMin)
{
    qWarning("Floating point comparison needs context sanity check");
    if (qFuzzyCompare(m_yMin, yMin))
        return;

    m_yMin = yMin;
    emit yMinChanged(m_yMin);
}

void QChart::appendToList(qreal x, qreal y)
{
    if (m_listData.count() > m_xAxisDiv)
    {
        m_listData.clear();
        m_mappedList.clear();
    }
    if (x > m_xMax) x = m_xMax;
    if (x < m_xMin) x = m_xMin;
    if (y > m_yMax) y = m_yMax;
    if (y < m_yMin) y = m_yMax;
    m_listData.append(Dot(x, y));
    m_mappedList.append(mapData(y));
    update();
}

void QChart::appendData(qreal data)
{
    appendToList(0, data);
}

void QChart::setEasingType(int easingType)
{
    if (m_easingType == easingType)
        return;

    m_easingType = easingType;
    emit easingTypeChanged(m_easingType);
}

Dot QChart::dataToChart(const Dot &_other, qreal distance, int index)
{
    Dot result;
    result.x = boundingRect().x() + distance * index;
    result.y = boundingRect().y() + ((m_yMax - _other.y) / (m_yMax - m_yMin) * (boundingRect().height() - 20));
    return result;
}

Dot QChart::dataToChart(qreal x, qreal y, qreal distance, int index)
{
    Q_UNUSED(x)
    Dot result;
    result.x = boundingRect().x() + distance * index;
    result.y = boundingRect().y() + ((m_yMax - y) / (m_yMax - m_yMin) * (boundingRect().height() - 20));
    return result;
}

qreal QChart::mapData(qreal y)
{
    qreal ry = boundingRect().y() + DEFS->CHART_DRAW_OFFSET()
            + ((m_yMax - y) / (m_yMax - m_yMin) * (boundingRect().height() - DEFS->CHART_DRAW_OFFSET()));
    return ry;
}

void QChart::setXAxisDiv(int xAxisDiv)
{
    if (m_xAxisDiv == xAxisDiv)
        return;

    m_xAxisDiv = xAxisDiv;
    emit xAxisDivChanged(m_xAxisDiv);
}

void QChart::setYAxisDiv(int yAxisDiv)
{
    if (m_yAxisDiv == yAxisDiv)
        return;

    m_yAxisDiv = yAxisDiv;
    emit yAxisDivChanged(m_yAxisDiv);
}

void QChart::setGridMode(int gridMode)
{
    if (m_gridMode == gridMode)
        return;

    m_gridMode = gridMode;
    emit gridModeChanged(m_gridMode);
}

void QChart::setDotColor(QColor dotColor)
{
    if (m_dotColor == dotColor)
        return;

    m_dotColor = dotColor;
    emit dotColorChanged(m_dotColor);
}

void QChart::setAxisColor(QColor axisColor)
{
    if (m_axisColor == axisColor)
        return;

    m_axisColor = axisColor;
    emit axisColorChanged(m_axisColor);
}

void QChart::setLineColor(QColor lineColor)
{
    if (m_lineColor == lineColor)
        return;

    m_lineColor = lineColor;
    emit lineColorChanged(m_lineColor);
}

void QChart::setLineThickness(int lineThickness)
{
    if (m_lineThickness == lineThickness)
        return;

    m_lineThickness = lineThickness;
    emit lineThicknessChanged(m_lineThickness);
}

void QChart::setDotThickness(int dotThickness)
{
    if (m_dotThickness == dotThickness)
        return;

    m_dotThickness = dotThickness;
    emit dotThicknessChanged(m_dotThickness);
}
