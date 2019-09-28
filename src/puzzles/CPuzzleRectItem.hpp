#ifndef CPUZZLERECTITEM_H
#define CPUZZLERECTITEM_H

#include <QObject>

#include <QGraphicsItem>
#include <QPainter>
#include <QRectF>
#include <QColor>

//! CPuzzleRectItem: item for puzzle's rectangle
class CPuzzleRectItem : public QObject, public QGraphicsItem
{
    Q_OBJECT

signals:
    void signal_selected( CPuzzleRectItem *rect_item);

public:
    explicit CPuzzleRectItem( QObject *parent = nullptr);

    virtual QRectF boundingRect() const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

    void setRect( const QRectF &rect);
    QRectF getRect() const;

    void setColor( const QColor &color);
    QColor getColor() const;

    void enableClick(bool flag = true);

    virtual void mousePressEvent( QGraphicsSceneMouseEvent *event) override;

    void reset();

    bool operator == (const CPuzzleRectItem &other_item) const;
    bool operator != (const CPuzzleRectItem &other_item) const;

private:
	QRectF m_rect;
	QColor m_color;
    qreal m_size_gain;

    bool m_flag_selected;
    bool m_flag_enable_click;
};

#endif // CPUZZLERECTITEM_H
