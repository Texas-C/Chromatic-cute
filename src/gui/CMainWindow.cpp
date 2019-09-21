#include "CMainWindow.hpp"
#include "ui_CMainWindow.h"
#include <QSettings>

CMainWindow::CMainWindow(QWidget *parent) :
	QMainWindow(parent),
    m_ui(new Ui::CMainWindow)
{
    m_ui->setupUi(this);

    this->loadSettings();
    connect( m_ui->m_page_game, &CPuzzleWidget::signal_puzzleSolved,
             this,	&CMainWindow::slot_nextPuzzle);
}

CMainWindow::~CMainWindow()
{
    this->saveSettings();

    delete m_ui;
}

void CMainWindow::loadSettings()
{
    QSettings setting;

    m_puzzle_index = setting.value("LastPuzzleIndex", 0).toInt();

    m_ui->m_page_game->setPuzzleInfo( m_puzzle_manager.getPuzzle( m_puzzle_index) );
}

void CMainWindow::saveSettings()
{
    QSettings setting;

    setting.setValue("LastPuzzleIndex", m_puzzle_index);
}

void CMainWindow::slot_nextPuzzle()
{
    m_ui->m_page_game->setPuzzleInfo( m_puzzle_manager.getPuzzle( ++m_puzzle_index) );
}

void CMainWindow::on_spinBox_valueChanged(int arg1)
{
    m_puzzle_index = arg1;
    m_ui->m_page_game->setPuzzleInfo( m_puzzle_manager.getPuzzle( m_puzzle_index) );
}
