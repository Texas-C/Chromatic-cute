#include "CPuzzleRectItem.hpp"
#include <QDebug>

const qreal RECT_SIZE_GAIN = 0.05;

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

    painter->drawRect( m_rect );
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

    if( m_flag_selected )
        this->setScale( 0.95 );
    else
        this->setScale( 1.00 );

    this->setSelected( m_flag_selected );

    QGraphicsItem::mousePressEvent( event );
}
