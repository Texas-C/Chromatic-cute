#include "CPuzzleRectItem.hpp"
#include <QDebug>
#include <QMouseEvent>

const qreal RECT_SIZE_GAIN = 0.10;

CPuzzleRectItem::CPuzzleRectItem( QObject *parent) : QObject(parent),
    m_size_gain(0.0),
    m_flag_selected(false),
    m_flag_enable_click(true)
{
    this->setFlag( QGraphicsItem::ItemIsSelectable );
    this->setAcceptTouchEvents( true );
}

void CPuzzleRectItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush( QBrush( m_color ) );
    painter->setPen( QPen(m_color ));

    painter->drawRect( this->boundingRect() );
}

void CPuzzleRectItem::setColor(const QColor &color)
{
    m_color = color;
}

QColor CPuzzleRectItem::getColor() const
{
    return m_color;
}

void CPuzzleRectItem::enableClick(bool flag)
{	m_flag_enable_click = flag;	}

//---- events handle
void CPuzzleRectItem::mousePressEvent( QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent( event );

    if( m_flag_enable_click)
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

        emit this->signal_selected( this );
    }

}

void CPuzzleRectItem::reset()
{
    m_flag_selected = false;
    this->setScale(1.00);
}

bool CPuzzleRectItem::operator==(const CPuzzleRectItem &other_item) const
{
    return m_color == other_item.m_color;
}

bool CPuzzleRectItem::operator!=(const CPuzzleRectItem &other_item) const
{
    return m_color != other_item.m_color;
}
