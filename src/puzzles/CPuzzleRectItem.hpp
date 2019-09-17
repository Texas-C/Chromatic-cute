#ifndef CPUZZLERECTITEM_H
#define CPUZZLERECTITEM_H

#include <QGraphicsItem>
#include <QPainter>
#include <QRectF>
#include <QColor>

//! CPuzzleRectItem: item for puzzle's rectangle
class CPuzzleRectItem : public QGraphicsItem
{
public:
	explicit CPuzzleRectItem();

	QRectF boundingRect() const override;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

    void setRect( const QRectF &rect);
    QRectF getRect() const;

    void setColor( const QColor &color);
    QColor getColor() const;

    void mousePressEvent( QGraphicsSceneMouseEvent *event) override;

    bool operator == (const CPuzzleRectItem &other_item) const;
    bool operator != (const CPuzzleRectItem &other_item) const;

private:
	QRectF m_rect;
	QColor m_color;
    qreal m_size_gain;

    bool m_flag_selected;
};

#endif // CPUZZLERECTITEM_H
