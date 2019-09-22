#ifndef CMAINPAGE_HPP
#define CMAINPAGE_HPP

#include <QWidget>
#include <QTimer>

namespace Ui {
class CHomeWidget;
}

class CHomeWidget : public QWidget
{
    Q_OBJECT

signals:
    void signal_requestStart();
    void signal_requestCreditsPage();

public:
    explicit CHomeWidget(QWidget *parent = nullptr);
    ~CHomeWidget() override;

    const QColor& color() const;
    void setColor( QColor new_color);

private slots:
    void on_m_start_button_clicked();

    void on_m_credits_button_clicked();

    //void slot_switchBackground();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::CHomeWidget *ui;

    QColor m_color;
    QTimer *m_timer;

    static const int BACKGROUND_SWITCH_INTERVAL = 3000;	// interval in ms
};

#endif // CMAINPAGE_HPP
