#include "CHomeWidget.hpp"
#include "ui_CHomeWidget.h"

#include "ColorVector.hpp"

#include <QPainter>
#include <QPropertyAnimation>

#define REFRESH_CNT 20

CHomeWidget::CHomeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CHomeWidget),
    m_bg_refresh_timer( new QTimer()),
    m_bg_switch_timer( new QTimer()),
    m_bg_index(0)
{

    ui->setupUi(this);

    // background list
    m_backgrounds.append( QColor( 0, 0, 0) );
    m_backgrounds.append( QColor( 72, 28, 32) );
    m_backgrounds.append( QColor( 0, 148, 128) );
    m_backgrounds.append( QColor( 0, 48, 64) );
    m_backgrounds.append( QColor( 0, 72, 100) );
    m_backgrounds.append( QColor( 128, 94, 84) );
    m_color = m_backgrounds[0];
    m_color_vector = ColorVector(m_color);

    connect( m_bg_refresh_timer, &QTimer::timeout,
             this, &CHomeWidget::slot_refreshBackground);

    connect( m_bg_switch_timer, &QTimer::timeout,
             this, &CHomeWidget::slot_switchBackground);

    m_bg_refresh_timer->setInterval(50);
    m_bg_switch_timer->setInterval(3000);

    m_bg_switch_timer->start();
}

CHomeWidget::~CHomeWidget()
{
    delete m_bg_refresh_timer;
    delete ui;
}

//----
//void CHomeWidget::addBackground(const PuzzleInfo &new_bg)
//{    m_backgrounds.append( new_bg );}

//---- button action:
void CHomeWidget::on_m_start_button_clicked()
{
    emit this->signal_requestStart();
}

void CHomeWidget::on_m_credits_button_clicked()
{
    emit this->signal_requestCreditsPage();
}

//---- background switching & refreshing
void CHomeWidget::slot_refreshBackground()
{
    if( m_refresh_cnt > 0 )	//do refresh each step here:
    {
        m_color_vector = m_color_vector + m_color_delta;
        m_refresh_cnt--;
        this->update();
    }
    else	// refresh end
    {
        m_bg_refresh_timer->stop();
        m_bg_switch_timer->start();
    }
}

void CHomeWidget::slot_switchBackground()
{
    // refresh start -- config
    m_refresh_cnt = REFRESH_CNT;
    this->genBackground();

    m_color_vector = ColorVector( m_color );
    m_color_delta = ColorVector( m_backgrounds[m_bg_index]) -
                      ColorVector(m_color);
    m_color_delta = m_color_delta / REFRESH_CNT;

    m_bg_switch_timer->stop();
    m_bg_refresh_timer->start();
}

//---- background

void CHomeWidget::genBackground()
{
    m_bg_index = (m_bg_index + 1) % m_backgrounds.size();
}

//---- paint:
void CHomeWidget::paintEvent( QPaintEvent *event)
{
    QPainter painter(this);
    m_color = m_color_vector.toQColor();

    painter.setBrush( m_color );
    painter.setPen( m_color );
    painter.drawRect( this->rect() );

    QWidget::paintEvent(event);
}
