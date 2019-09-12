#ifndef CPUZZLERECTITEM_H
#define CPUZZLERECTITEM_H

#include <QGraphicsItem>
#include <QPainter>
#include <QRectF>
#include <QColor>

class CPuzzleRectItem : public QGraphicsItem
{
public:
	explicit CPuzzleRectItem();

	QRectF boundingRect() const override;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

private:
	QRectF m_rect;
	QColor m_color;
};

#endif // CPUZZLERECTITEM_H
