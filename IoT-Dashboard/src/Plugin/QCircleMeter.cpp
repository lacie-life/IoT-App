#include "Plugin/QCircleMeter.h"

QCircleMeter::QCircleMeter(QQuickItem *parent)
    : QQuickPaintedItem{ parent }
    , m_unfilledColor { DEFAULT_UNFILLED_COLOR }
    , m_filledColor { DEFAULT_FILLED_COLOR }
    , m_bottomColor { DEFAULT_BOTTOM_COLOR }
    , m_centerColor { DEFAULT_CENTER_COLOR }
    , m_thickness{ 20 }
    , m_data { 0 }
{

}

void QCircleMeter::paint(QPainter *painter)
{
    // Prepare color to draw
    QBrush unfilled(m_unfilledColor);   // first layer
    QBrush filled(m_filledColor);       // second layer
    QBrush bottom(m_bottomColor);       // third layer
    QBrush center(m_centerColor);       // last layer

    painter->setPen(Qt::NoPen); // no outline
    painter->setRenderHints(QPainter::Antialiasing, true);

    // Draw the first layer of object
    painter->setBrush(unfilled);
    painter->drawEllipse(boundingRect().REDUCE_SIZE(1));

    painter->setBrush(filled);
    painter->drawPie(boundingRect().REDUCE_SIZE(1),
                     210*16,
                     static_cast<int>(240*16 * m_data/100) * -1);

    // Draw the third layer
    painter->setBrush(bottom);
    painter->drawPie(boundingRect().REDUCE_SIZE(1),
                     210*16,
                     120*16);

    // Draw the last layer
    painter->setBrush(center);
    painter->drawEllipse(boundingRect().REDUCE_SIZE((width() * m_thickness / 200)));    // = radius * (100-thickness) %
                                                                                        // = reduce(width / 2 * thickness %)
}

QColor QCircleMeter::centerColor() const
{
    return m_centerColor;
}

QColor QCircleMeter::bottomColor() const
{
    return m_bottomColor;
}

QColor QCircleMeter::unfilledColor() const
{
    return m_unfilledColor;
}

QColor QCircleMeter::filledColor() const
{
    return m_filledColor;
}

int QCircleMeter::data() const
{
    return m_data;
}

int QCircleMeter::thickness() const
{
    return m_thickness;
}

void QCircleMeter::setCenterColor(QColor centerColor)
{
    if (m_centerColor == centerColor)
        return;

    m_centerColor = centerColor;
    emit centerColorChanged(m_centerColor);
}

void QCircleMeter::setBottomColor(QColor bottomColor)
{
    if (m_bottomColor == bottomColor)
        return;

    m_bottomColor = bottomColor;
    emit bottomColorChanged(m_bottomColor);
}

void QCircleMeter::setUnfilledColor(QColor unfilledColor)
{
    if (m_unfilledColor == unfilledColor)
        return;

    m_unfilledColor = unfilledColor;
    emit unfilledColorChanged(m_unfilledColor);
}

void QCircleMeter::setFilledColor(QColor filledColor)
{
    if (m_filledColor == filledColor)
        return;

    m_filledColor = filledColor;
    emit filledColorChanged(m_filledColor);
}

void QCircleMeter::setData(int data)
{
    if (data == m_data)
        return;

    if (data >= 100) data = 100;
    if (data <= 0) data = 0;

    m_data = data;
    update();
    emit dataChanged(m_data);
}

void QCircleMeter::setThickness(int thickness)
{
    if (m_thickness == thickness)
        return;

    if (thickness >= 50) thickness = 50;
    if (thickness <= 10) thickness = 10;
    m_thickness = thickness;
    emit thicknessChanged(m_thickness);
}
