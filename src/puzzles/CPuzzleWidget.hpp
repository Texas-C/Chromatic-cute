#ifndef CPUZZLEWIDGET_H
#define CPUZZLEWIDGET_H

#include <QWidget>
#include <QGraphicsScene>

#include "CPuzzleManager.hpp"
#include "CPuzzleRectItem.hpp"

#include <QList>

typedef QList<CPuzzleRectItem*> RectItemList;

bool rectItemListCompare( RectItemList &A, RectItemList &B);

namespace Ui{
class CPuzzleWidget;
}

class CPuzzleWidget : public QWidget
{
	Q_OBJECT
public:
	explicit CPuzzleWidget(QWidget *parent = nullptr);
    ~CPuzzleWidget() override;

    void resizeRects();
    void clearRectList();

	void setPuzzleInfo( const PuzzleInfo &puzzle_new);
	PuzzleInfo getPuzzleInfo( ) const;

protected:
    void resizeEvent(QResizeEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;

private:
    Ui::CPuzzleWidget *m_ui;
    QGraphicsScene *m_scene;

	PuzzleInfo	m_puzzle;

    RectItemList m_rect_list;
    RectItemList m_rect_list_answer;	// a copy of m_rect_list, save final answer here

    int m_level;

};

#endif // CPUZZLEWIDGET_H
