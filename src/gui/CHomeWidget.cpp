#include "CHomeWidget.hpp"
#include "ui_CHomeWidget.h"

#include <QPainter>
#include <QPropertyAnimation>

CHomeWidget::CHomeWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CHomeWidget),
    m_timer( new QTimer())
{

    ui->setupUi(this);
}

CHomeWidget::~CHomeWidget()
{
    delete m_timer;
    delete ui;
}

const QColor& CHomeWidget::color() const
{	return m_color;}

void CHomeWidget::setColor(QColor new_color )
{
    m_color = new_color;
    update();
}

void CHomeWidget::on_m_start_button_clicked()
{
    emit this->signal_requestStart();
}

void CHomeWidget::on_m_credits_button_clicked()
{
    emit this->signal_requestCreditsPage();
}

void CHomeWidget::paintEvent( QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush( QBrush(QColor(m_color) ) );
    painter.setPen( QPen( QColor(m_color)) );

    painter.drawRect( this->rect() );
    QWidget::paintEvent(event);
}
