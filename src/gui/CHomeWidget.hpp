#ifndef CMAINPAGE_HPP
#define CMAINPAGE_HPP

#include <QWidget>
#include <QTimer>
#include <QRectF>

#include "CPuzzleManager.hpp"
#include <QLinearGradient>

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

    //void addBackground( const PuzzleInfo &new_bg);

private slots:
    void on_m_start_button_clicked();

    void on_m_credits_button_clicked();

    void slot_refreshBackground();

    void slot_switchBackground();

private:
    void genBackground();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    Ui::CHomeWidget *ui;

    QTimer *m_bg_refresh_timer;	// timer for refresh background (when switching)
    QTimer *m_bg_switch_timer;	// timer for switch background

    QRectF m_rects[3][3];
    //QList<PuzzleInfo> m_backgrounds;
    QList<QColor> m_backgrounds;
    QColor m_color;
    ColorVector m_color_vector;
    ColorVector m_color_delta;

    int m_bg_index;

    int m_refresh_cnt;	//refresh rate

    static const int BACKGROUND_SWITCH_INTERVAL = 3000;	// interval in ms
};

#endif // CMAINPAGE_HPP
