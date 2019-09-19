#ifndef CPUZZLEWIDGET_H
#define CPUZZLEWIDGET_H

/*! CPuzzleWidget is a main widget for display puzzle */

#include <QWidget>
#include <QGraphicsScene>

#include "CPuzzleManager.hpp"
#include "CPuzzleRectItem.hpp"

#include <QList>

typedef QList<CPuzzleRectItem*> RectItemList;

// 0 for equl, positive for difference, negative for differentsize
int rectItemListCompare( RectItemList &A, RectItemList &B);

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

    void swapItem( CPuzzleRectItem *new_item);

protected:
    void resizeEvent(QResizeEvent *event) override;

private:
    Ui::CPuzzleWidget *m_ui;
    QGraphicsScene *m_scene;

	PuzzleInfo	m_puzzle;

    RectItemList m_rect_list;
    RectItemList m_rect_list_answer;	// a copy of m_rect_list, save final answer here

    CPuzzleRectItem *m_last_rect_item;

    int m_level;

};

// callback function for judge answer
void callbackJudge( CPuzzleWidget &puzzle_widget);

#endif // CPUZZLEWIDGET_H
