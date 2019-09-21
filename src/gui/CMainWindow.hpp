#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include <QMainWindow>
#include "CPuzzleManager.hpp"

namespace Ui {
class CMainWindow;
}

class CMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit CMainWindow(QWidget *parent = nullptr);
	~CMainWindow();

    void loadSettings();
    void saveSettings();

private slots:
    void slot_nextPuzzle();

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::CMainWindow *m_ui;

    int m_puzzle_index;
    CPuzzleManager m_puzzle_manager;
};

#endif // MAINWINDOW_H
