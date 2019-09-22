#ifndef CCREDITSWIDGET_HPP
#define CCREDITSWIDGET_HPP

#include <QWidget>

namespace Ui {
class CCreditsWidget;
}

class CCreditsWidget : public QWidget
{
    Q_OBJECT
signals:
    void signal_requestBackToHome();

public:
    explicit CCreditsWidget(QWidget *parent = nullptr);
    ~CCreditsWidget();

private slots:
    void on_m_button_back_clicked();

private:
    Ui::CCreditsWidget *ui;
};

#endif // CCREDITSWIDGET_HPP
