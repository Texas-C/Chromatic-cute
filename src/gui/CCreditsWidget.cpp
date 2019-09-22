#include "src/gui/CCreditsWidget.hpp"
#include "ui_CCreditsWidget.h"

CCreditsWidget::CCreditsWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CCreditsWidget)
{
    ui->setupUi(this);
}

CCreditsWidget::~CCreditsWidget()
{
    delete ui;
}

void CCreditsWidget::on_m_button_back_clicked()
{
    emit this->signal_requestBackToHome();
}
