#include "CPuzzleRectItem.hpp"

const qreal RECT_SIZE_GAIN = 0.01;

CPuzzleRectItem::CPuzzleRectItem() : m_size_gain(0.0), m_flag_selected(false)
{
	this->setAcceptTouchEvents( true );
}

//---- pure virtual functions
QRectF CPuzzleRectItem::boundingRect() const
{
	return m_rect;
}

void CPuzzleRectItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->setBrush( QBrush( m_color ) );
    painter->setPen( QPen(m_color ));

    // size gained when "selected"
    if( m_flag_selected )
        m_size_gain = m_rect.width() * RECT_SIZE_GAIN;	// rect size gain when selected
    else
        m_size_gain = 0.0;

    painter->drawRect( QRectF( m_rect.topLeft() - QPointF( m_size_gain, m_size_gain),
                               m_rect.bottomRight() + QPointF( m_size_gain, m_size_gain)) );
    //painter->drawRect( m_rect );
}

//---- properties
void CPuzzleRectItem::setRect( const QRectF &rect)
{	m_rect = rect;	}

QRectF CPuzzleRectItem::getRect() const
{	return m_rect;	}

void CPuzzleRectItem::setColor(const QColor &color)
{	m_color = color;	}

//---- events handle
void CPuzzleRectItem::mousePressEvent( QGraphicsSceneMouseEvent *event)
{
    m_flag_selected = !m_flag_selected;

    QGraphicsItem::mousePressEvent( event );
}
