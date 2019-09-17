#include "CPuzzleRectItem.hpp"
#include <QDebug>

const qreal RECT_SIZE_GAIN = 0.10;

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

QColor CPuzzleRectItem::getColor() const
{	return m_color;	}

//---- events handle
void CPuzzleRectItem::mousePressEvent( QGraphicsSceneMouseEvent *event)
{
    m_flag_selected = !m_flag_selected;

    // set transform center
    QPointF top_left = this->boundingRect().topLeft();
    QPointF bottom_right = this->boundingRect().bottomRight();
    this->setTransformOriginPoint( (top_left.x() + bottom_right.x()) / 2.0, (top_left.y() + bottom_right.y()) / 2.0);

    // transform
    if( m_flag_selected )
        this->setScale( 1.00 - RECT_SIZE_GAIN );
    else
        this->setScale( 1.00 );

    this->setSelected( m_flag_selected );

    QGraphicsItem::mousePressEvent( event );
}


bool CPuzzleRectItem::operator==(const CPuzzleRectItem &other_item) const
{    return m_color == other_item.m_color;	}

bool CPuzzleRectItem::operator!=(const CPuzzleRectItem &other_item) const
{    return m_color != other_item.m_color;	}
