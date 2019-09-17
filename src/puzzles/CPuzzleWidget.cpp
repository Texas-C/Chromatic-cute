#include "CPuzzleWidget.hpp"
#include "ui_CPuzzleWidget.h"

#include <QPainter>
#include <QDebug>

//-----
int pos2index( int x, int y, int size)
{    return x * size + y; }

// Puzzle widget
CPuzzleWidget::CPuzzleWidget(QWidget *parent) : QWidget(parent),
    m_ui(new Ui::CPuzzleWidget),
    m_scene( new QGraphicsScene())
{
    m_ui->setupUi(this);
    m_ui->m_puzzle_view->setScene( m_scene );

	m_puzzle.m_size = 0;
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
        {
            //m_scene->removeItem( *it );
            delete (*it);
        }

        m_rect_list.clear();
    }

    m_scene->clear();
}

//------------------ puzzle

void CPuzzleWidget::resizeRects()
{
    if( m_rect_list.size() != (m_puzzle.m_size * m_puzzle.m_size))
        return;

    RectItemList::iterator it = m_rect_list.begin();

    qreal rect_width = m_ui->m_puzzle_view->width() / m_puzzle.m_size;
    qreal rect_height = m_ui->m_puzzle_view->height() / m_puzzle.m_size;

    QSizeF	rect_size( rect_width, rect_height);

    for(int i = 0; i < m_puzzle.m_size; ++i)
    {
        for(int j = 0; j < m_puzzle.m_size; ++j)
        {
            QPointF top_left( rect_width * i, rect_height * j);

            (*it)->setRect( QRectF( top_left, rect_size) );
            ++it;
        }
    }
}

void CPuzzleWidget::setPuzzleInfo(const PuzzleInfo &puzzle_new)
{
    m_puzzle = puzzle_new;
    m_ui->m_puzzle_name_label->setText( m_puzzle.m_name );

    // clear rect list
    this->clearRectList();

    // setup color:
    ColorVector v_tl = m_puzzle.m_colors[0];	//top left
    ColorVector v1 = ColorVector( m_puzzle.m_colors[1]) - v_tl;
    ColorVector v2 = ColorVector( m_puzzle.m_colors[3]) - v_tl;
    v1 = v1 / m_puzzle.m_size;
    v2 = v2 / m_puzzle.m_size;

	for(int i = 0; i < m_puzzle.m_size; ++i)
	{
        for(int j = 0; j < m_puzzle.m_size; ++j)
		{
            CPuzzleRectItem* p = new CPuzzleRectItem();
            ColorVector tmp = v_tl + v1 * j + v2 * i;

            p->setColor( tmp.toQColor() );

            m_scene->addItem( p );
            m_rect_list.append( p );
		}
	}

    this->resizeRects();

    /*
    m_rect_list[ pos2index(0, 0, m_puzzle.m_size) ]->setColor( m_puzzle.m_colors[0] );
    m_rect_list[ pos2index(0, m_puzzle.m_size - 1, m_puzzle.m_size) ]->setColor( m_puzzle.m_colors[1] );
    m_rect_list[ pos2index(m_puzzle.m_size - 1, m_puzzle.m_size - 1, m_puzzle.m_size) ]->setColor( m_puzzle.m_colors[2] );
    m_rect_list[ pos2index(m_puzzle.m_size - 1, 0, m_puzzle.m_size) ]->setColor( m_puzzle.m_colors[3] );
    */
}

PuzzleInfo CPuzzleWidget::getPuzzleInfo() const
{
	return m_puzzle;
}

//------------------

void CPuzzleWidget::resizeEvent(QResizeEvent *event)
{
    this->resizeRects();
    QWidget::resizeEvent(event);
}
