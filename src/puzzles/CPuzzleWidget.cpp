#include "ui_CPuzzleWidget.h"

#include "CPuzzleWidget.hpp"
#include "ColorVector.hpp"

#include <QPainter>
#include <algorithm>	// random_shuffle

#include <QDebug>

const QList<QString> CPuzzleWidget::passed_message = {"Brilliant", "Excellent", "Magnificent", "Splendid", "Spectacular", "Wonderful", "Nice >w<"};

int rectItemListCompare( RectItemList &A, RectItemList &B)
{
    RectItemList::iterator it1, it2;

    int cnt = 0;

    if(A.size() != B.size())
        return -1;

    for( it1 = A.begin(), it2 = B.begin(); it1 != A.end() && it2 != B.end(); ++it1, ++it2)
        cnt += ( *(*it1) != *(*it2) );

    return cnt;
}

// check point on squre conrner
bool checkPositionOnCorner( int x, int y, int size)
{
    if( (x == 0) || (x == size))
        return (y == 0) || (y == size);
    return false;
}

int pos2index( int x, int y, int size)
{
    return x * size + y;
}

//--------------------------------------------------------------------------
// Puzzle widget
CPuzzleWidget::CPuzzleWidget(QWidget *parent) : QWidget(parent),
    m_ui(new Ui::CPuzzleWidget),
    m_scene( new QGraphicsScene()),
    m_last_rect_item(nullptr)
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

void CPuzzleWidget::addNewLevel(int solved_level_index)
{
    m_ui->m_level_list->addItem( QString("Level ") + QString::number(solved_level_index + 1), solved_level_index);
}

void CPuzzleWidget::jumpToLastLevel()
{
    m_ui->m_level_list->setCurrentIndex( m_ui->m_level_list->count() - 1);
}

void CPuzzleWidget::initLevel()
{	m_ui->m_level_list->setCurrentIndex( -1 );	}

//------------------ cleanup

void CPuzzleWidget::clearRectList()
{

    RectItemList::iterator it;

    for( it = m_rect_list.begin(); it != m_rect_list.end(); ++it)
    {
        disconnect( *it, &CPuzzleRectItem::signal_selected,
                 this, &CPuzzleWidget::slot_handleSelectedItem);
        delete (*it);
    }

    for( it = m_rect_list_answer.begin(); it != m_rect_list_answer.end(); ++it)
        delete (*it);

    m_rect_list.clear();
    m_rect_list_answer.clear();
    m_scene->clear();
}

void CPuzzleWidget::shuffleRectList()
{
    QList<QColor> tmp_list;
    QList<QColor>::iterator it;

    for(int i = 0; i < m_puzzle.m_size; ++i)
        for(int j = 0; j < m_puzzle.m_size; ++j)
            if( !checkPositionOnCorner(i, j, m_puzzle.m_size - 1) )
                tmp_list.append( m_rect_list[ pos2index(i, j, m_puzzle.m_size)]->getColor());

    std::random_shuffle( tmp_list.begin(), tmp_list.end());

    it = tmp_list.begin();
    for(int i = 0; i < m_puzzle.m_size; ++i)
        for(int j = 0; j < m_puzzle.m_size; ++j)
            if( !checkPositionOnCorner(i, j, m_puzzle.m_size - 1) )
                m_rect_list[ pos2index(i, j, m_puzzle.m_size)]->setColor( *it++ );

    if( rectItemListCompare( m_rect_list, m_rect_list_answer) <= 2)
        this->shuffleRectList();	// keep shuffle while m_rect_list equal to answer;
}

//------------------ puzzle

void CPuzzleWidget::resizeRects()
{
    if( m_rect_list.size() != (m_puzzle.m_size * m_puzzle.m_size))
        return;

    RectItemList::iterator it = m_rect_list.begin();

    qreal rect_width = qreal(m_ui->m_puzzle_view->width()) / m_puzzle.m_size;
    qreal rect_height = qreal(m_ui->m_puzzle_view->height()) / m_puzzle.m_size;

    QSizeF	rect_size( rect_width, rect_height);

    qDebug() << "View Size:" << m_ui->m_puzzle_view->width() << m_ui->m_puzzle_view->height();
    qDebug() << "Rect Size:" << rect_width << rect_height;

    for(int i = 0; i < m_puzzle.m_size && it != m_rect_list.end(); ++i)
    {
        for(int j = 0; j < m_puzzle.m_size && it != m_rect_list.end(); ++j)
        {
            QPointF top_left( rect_width * i, rect_height * j);

            (*it)->setRect( QRectF( top_left, rect_size) );
            ++it;
        }
    }
}

void CPuzzleWidget::setPuzzleInfo(const PuzzleInfo &puzzle_new)
{
    m_ui->m_puzzle_status->setText("");
    m_ui->m_next_button->setVisible(false);

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
            CPuzzleRectItem* p_answer = new CPuzzleRectItem();
            ColorVector tmp;

            tmp = v_tl + v1 * j + v2 * i;

            p->setColor( tmp.toQColor() );
            p_answer->setColor( tmp.toQColor());

            connect( p, &CPuzzleRectItem::signal_selected,
                     this, &CPuzzleWidget::slot_handleSelectedItem);

            m_scene->addItem( p );
            m_rect_list.append( p );
            m_rect_list_answer.append( p_answer );
        }
    }


    // disable rectangle which on the widgets's corner
    m_rect_list[ pos2index(0, 0, m_puzzle.m_size) ]->enableClick(false);
    m_rect_list[ pos2index(0, m_puzzle.m_size - 1, m_puzzle.m_size) ]->enableClick(false);
    m_rect_list[ pos2index(m_puzzle.m_size - 1, m_puzzle.m_size - 1, m_puzzle.m_size) ]->enableClick(false);
    m_rect_list[ pos2index(m_puzzle.m_size - 1, 0, m_puzzle.m_size) ]->enableClick(false);

    // shuffle rect list
    this->shuffleRectList();

    // resize
    this->resizeRects();
}

PuzzleInfo CPuzzleWidget::getPuzzleInfo() const
{
    return m_puzzle;
}

//------------------

void CPuzzleWidget::resizeEvent(QResizeEvent *event)
{
    if( this->m_puzzle.m_size )	//has puzzle
        this->resizeRects();

    QWidget::resizeEvent(event);
}

void CPuzzleWidget::swapItem(CPuzzleRectItem *new_item)
{
    if( m_last_rect_item == nullptr)
    {
        m_last_rect_item = new_item;
    }
    else	//swap color & reset rectangle item
    {
        QColor tmp_color = m_last_rect_item->getColor();
        m_last_rect_item->setColor( new_item->getColor());
        new_item->setColor( tmp_color );

        new_item->reset();
        m_last_rect_item->reset();

        m_last_rect_item = nullptr;

        if( judge() )	//passed
        {
            m_ui->m_puzzle_status->setText( CPuzzleWidget::passed_message[ rand() % (CPuzzleWidget::passed_message.size())]);
            m_ui->m_next_button->setVisible(true);
            emit this->signal_puzzleSolved( m_puzzle.m_level );
        }
    }
}

bool CPuzzleWidget::judge()
{
    return rectItemListCompare( m_rect_list, m_rect_list_answer) == 0;
}

void CPuzzleWidget::slot_handleSelectedItem( CPuzzleRectItem *item)
{
    this->swapItem( item );
}

void CPuzzleWidget::on_m_back_button_clicked()
{
    emit this->signal_requestBackToHome();
}

void CPuzzleWidget::on_m_level_list_currentIndexChanged(int index)
{
	emit this->signal_requestLevel(index);
}

void CPuzzleWidget::on_m_next_button_clicked()
{
    m_ui->m_level_list->setCurrentIndex( m_puzzle.m_level);
}
