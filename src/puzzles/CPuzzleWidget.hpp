#ifndef CPUZZLEWIDGET_H
#define CPUZZLEWIDGET_H

#include <QWidget>
#include "CPuzzleManager.hpp"

#include <QGraphicsScene>

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
    ~CPuzzleWidget();

	void setPuzzleInfo( const PuzzleInfo &puzzle_new);
	PuzzleInfo getPuzzleInfo( ) const;

protected:

private:
    Ui::CPuzzleWidget *m_ui;

	PuzzleInfo	m_puzzle;
	RectLists	m_rect_mps;

    QGraphicsScene *m_scene;
};

#endif // CPUZZLEWIDGET_H
