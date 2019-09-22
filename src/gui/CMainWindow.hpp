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
    void slot_nextPuzzle( int level );
    void slot_jumpLevel ( int level );

    void slot_toHomePage();
    void slot_startGame();
    void slot_toCreditsPage();


private:
    Ui::CMainWindow *m_ui;

    int m_puzzle_index;
    int m_puzzle_current_index;
    CPuzzleManager m_puzzle_manager;
};

#endif // MAINWINDOW_H
