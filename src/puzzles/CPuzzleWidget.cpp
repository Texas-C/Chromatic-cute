#include "CPuzzleWidget.hpp"
#include "ui_CPuzzleWidget.h"

#include <QPainter>

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
    delete m_scene;
    delete m_ui;
}

//------------------ puzzle

void CPuzzleWidget::setPuzzleInfo(const PuzzleInfo &puzzle_new)
{
	m_puzzle = puzzle_new;

    qreal	mini_width = std::min( this->width(), this->height() );
    QSizeF	rect_size( mini_width, mini_width);
    QPointF rect_left_top(0, 0);

    // rect left_top point
    if( this->width() > this->height())
        rect_left_top.setX( rect_left_top.x() + mini_width );
    else
        rect_left_top.setY( rect_left_top.y() + mini_width );

	if( !m_rect_mps.empty() )
		m_rect_mps.clear();

	for(int i = 0; i < m_puzzle.m_size; ++i)
	{
		m_rect_mps.push_back( RectList() );
		for(int j = 0; j < m_puzzle.m_size; ++j)
		{
			m_rect_mps[i].push_back( QRect() );
		}
	}
}

PuzzleInfo CPuzzleWidget::getPuzzleInfo() const
{
	return m_puzzle;
}

//------------------
