#ifndef CPUZZLEWIDGET_H
#define CPUZZLEWIDGET_H

#include <QWidget>
#include <QGraphicsScene>

#include "CPuzzleManager.hpp"
#include "CPuzzleRectItem.hpp"

#include <QList>

typedef QList<CPuzzleRectItem*> RectItemList;

namespace Ui{
class CPuzzleWidget;
}

class CPuzzleWidget : public QWidget
{
	Q_OBJECT
public:
	explicit CPuzzleWidget(QWidget *parent = nullptr);
    ~CPuzzleWidget();

    void resizeRects();
    void clearRectList();

	void setPuzzleInfo( const PuzzleInfo &puzzle_new);
	PuzzleInfo getPuzzleInfo( ) const;

protected:
    void resizeEvent(QResizeEvent *event);

private:
    Ui::CPuzzleWidget *m_ui;
    QGraphicsScene *m_scene;

	PuzzleInfo	m_puzzle;

    RectItemList m_rect_list;
    int m_level;

};

#endif // CPUZZLEWIDGET_H
