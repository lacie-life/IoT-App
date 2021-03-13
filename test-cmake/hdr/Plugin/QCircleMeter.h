#ifndef QCIRCLEMETER_H
#define QCIRCLEMETER_H

#include <QQuickPaintedItem>
#include <QColor>
#include <QBrush>
#include <QPen>
#include <QPainter>

#define REDUCE_SIZE(pixel) adjusted(pixel, pixel, -pixel, -pixel)

#define DEFAULT_UNFILLED_COLOR  qRgba(249, 180,  51, 1)
#define DEFAULT_FILLED_COLOR    qRgba (21, 197, 244, 1)
#define DEFAULT_BOTTOM_COLOR    qRgba( 60,  60,  60, 1)
#define DEFAULT_CENTER_COLOR    qRgba(255, 255, 255, 1)

class QCircleMeter : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QColor centerColor READ centerColor WRITE setCenterColor NOTIFY centerColorChanged)
    Q_PROPERTY(QColor bottomColor READ bottomColor WRITE setBottomColor NOTIFY bottomColorChanged)
    Q_PROPERTY(QColor unfilledColor READ unfilledColor WRITE setUnfilledColor NOTIFY unfilledColorChanged)
    Q_PROPERTY(QColor filledColor READ filledColor WRITE setFilledColor NOTIFY filledColorChanged)
    Q_PROPERTY(bool border READ border WRITE setBorder NOTIFY borderChanged)
    Q_PROPERTY(QColor borderColor READ borderColor WRITE setBorderColor NOTIFY borderColorChanged)
    Q_PROPERTY(int thickness READ thickness WRITE setThickness NOTIFY thicknessChanged)

    Q_PROPERTY(int data READ data WRITE setData NOTIFY dataChanged)


    QColor m_unfilledColor;
    QColor m_filledColor;
    QColor m_bottomColor;
    QColor m_centerColor;
    bool m_border;
    QColor m_borderColor;
    int m_thickness;

    int m_data;


public:
    explicit QCircleMeter(QQuickItem *parent = nullptr);

    void paint(QPainter *painter) override;

    QColor unfilledColor() const;
    QColor filledColor() const;
    QColor bottomColor() const;
    QColor centerColor() const;
    bool border() const;
    QColor borderColor() const;

    int thickness() const;
    int data() const;

public slots:
    void setUnfilledColor(QColor unfilledColor);
    void setFilledColor(QColor filledColor);
    void setBottomColor(QColor bottomColor);
    void setCenterColor(QColor centerColor);
    void setThickness(int thickness);

    void setData(int data);

    void setBorder(bool border);

    void setBorderColor(QColor borderColor);

signals:
    void centerColorChanged(QColor centerColor);
    void bottomColorChanged(QColor bottomColor);
    void unfilledColorChanged(QColor unfilledColor);
    void filledColorChanged(QColor filledColor);
    void dataChanged(qreal data);
    void thicknessChanged(int thickness);
    void borderChanged(bool border);
    void borderColorChanged(QColor borderColor);
};

#endif // QCIRCLEMETER_H
