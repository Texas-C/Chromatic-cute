#include "CPuzzleRectItem.hpp"

CPuzzleRectItem::CPuzzleRectItem()
{
	this->setAcceptTouchEvents( true );
}

QRectF CPuzzleRectItem::boundingRect() const
{
	return m_rect;
}

void CPuzzleRectItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->setBrush( QBrush( m_color ) );
	painter->drawRect( m_rect );
}
