#include "CPuzzleWidget.hpp"
#include "ui_CPuzzleWidget.h"

#include <QPainter>

CPuzzleWidget::CPuzzleWidget(QWidget *parent) : QWidget(parent), ui(new Ui::CPuzzleWidget)
{
	m_puzzle.m_size = 0;
}

//------------------ puzzle

void CPuzzleWidget::setPuzzleInfo(const PuzzleInfo &puzzle_new)
{
	m_puzzle = puzzle_new;

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
