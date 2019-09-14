#include "CPuzzleWidget.hpp"
#include "ui_CPuzzleWidget.h"

#include <QPainter>
#include <QDebug>

int pos2index( int x, int y, int size)
{    return x * size + y; }

CPuzzleWidget::CPuzzleWidget(QWidget *parent) : QWidget(parent),
    m_ui(new Ui::CPuzzleWidget),
    m_scene( new QGraphicsScene()),
    m_level(0)
{
    m_ui->setupUi(this);
    m_ui->m_puzzle_view->setScene( m_scene );

	m_puzzle.m_size = 0;

    this->setLevel( m_level );
}

CPuzzleWidget::~CPuzzleWidget()
{
    this->clearRectList();
    delete m_ui;
    delete m_scene;
}


//------------------ cleanup

void CPuzzleWidget::clearRectList()
{
    if( !m_rect_list.size())
    {
        RectItemList::iterator it;

        for( it = m_rect_list.begin(); it != m_rect_list.end(); ++it)
            delete (*it);

        m_rect_list.clear();
    }

}

//------------------ level

void CPuzzleWidget::setLevel(const int level)
{
    m_level = level;
    this->setPuzzleInfo( m_puzzle_manager.getPuzzle( level ) );
}

int CPuzzleWidget::getLevel() const
{	return m_level;	}

//------------------ puzzle

void CPuzzleWidget::setPuzzleInfo(const PuzzleInfo &puzzle_new)
{
    m_puzzle = puzzle_new;	// new puzzle info

    qreal	mini_width = std::min( this->width(), this->height() );
    QSizeF	rect_size( mini_width / m_puzzle.m_size, mini_width / m_puzzle.m_size);
    QPointF rect_left_top(0, 0);

    // rect left_top point
    if( this->width() > this->height())
        rect_left_top.setX( rect_left_top.x() - mini_width + this->width());
    else
        rect_left_top.setY( rect_left_top.y() - mini_width + this->height());

    // each rect size
    mini_width /= m_puzzle.m_size;

    this->clearRectList();

	for(int i = 0; i < m_puzzle.m_size; ++i)
	{
        for(int j = 0; j < m_puzzle.m_size; ++j)
		{
            QPointF top_left( rect_left_top.x() + mini_width * i, rect_left_top.y() + mini_width * j);
            CPuzzleRectItem* p = new CPuzzleRectItem();

            p->setRect( QRectF( top_left, rect_size) );
            p->setColor( Qt::black);

            m_scene->addItem( p );
            m_rect_list.append( p );
		}
	}

    m_rect_list[ pos2index(0, 0, m_puzzle.m_size) ]->setColor( m_puzzle.m_colors[0] );
    m_rect_list[ pos2index(0, m_puzzle.m_size - 1, m_puzzle.m_size) ]->setColor( m_puzzle.m_colors[1] );
    m_rect_list[ pos2index(m_puzzle.m_size - 1, m_puzzle.m_size - 1, m_puzzle.m_size) ]->setColor( m_puzzle.m_colors[2] );
    m_rect_list[ pos2index(m_puzzle.m_size - 1, 0, m_puzzle.m_size) ]->setColor( m_puzzle.m_colors[3] );
}

PuzzleInfo CPuzzleWidget::getPuzzleInfo() const
{
	return m_puzzle;
}

//------------------
