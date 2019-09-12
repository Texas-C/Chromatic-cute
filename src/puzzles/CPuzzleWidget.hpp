#ifndef CPUZZLEWIDGET_H
#define CPUZZLEWIDGET_H

#include <QWidget>
#include <QPaintEvent>
#include "CPuzzleManager.hpp"

#include <QRect>
#include <QList>

typedef QList<QRect> RectList;
typedef QList<RectList> RectLists;

namespace Ui{
class CPuzzleWidget;
}

class CPuzzleWidget : public QWidget
{
	Q_OBJECT
public:
	explicit CPuzzleWidget(QWidget *parent = nullptr);

	void setPuzzleInfo( const PuzzleInfo &puzzle_new);
	PuzzleInfo getPuzzleInfo( ) const;

protected:

signals:

public slots:

private:
	Ui::CPuzzleWidget *ui;

	PuzzleInfo	m_puzzle;
	RectLists	m_rect_mps;
};

#endif // CPUZZLEWIDGET_H
