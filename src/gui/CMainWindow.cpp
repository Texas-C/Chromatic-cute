#include "CMainWindow.hpp"
#include "ui_CMainWindow.h"
#include <QSettings>

CMainWindow::CMainWindow(QWidget *parent) :
	QMainWindow(parent),
    m_ui(new Ui::CMainWindow)
{
    m_ui->setupUi(this);

    //m_ui->spinBox->setRange(0, m_puzzle_index );
    connect( m_ui->m_page_game, &CPuzzleWidget::signal_puzzleSolved,
             this,	&CMainWindow::slot_nextPuzzle);

    connect( m_ui->m_page_game, &CPuzzleWidget::signal_requestBackToHome,
             this, &CMainWindow::slot_toHomePage);

    connect( m_ui->m_page_game, &CPuzzleWidget::signal_requestLevel,
             this, &CMainWindow::slot_jumpLevel);


    connect( m_ui->m_page_home, &CHomeWidget::signal_requestStart,
             this,	&CMainWindow::slot_startGame);

    connect( m_ui->m_page_home, &CHomeWidget::signal_requestCreditsPage,
             this, &CMainWindow::slot_toCreditsPage);



    connect( m_ui->m_page_credits, &CCreditsWidget::signal_requestBackToHome,
             this, &CMainWindow::slot_toHomePage);

    this->loadSettings();
}

CMainWindow::~CMainWindow()
{
    this->saveSettings();

    delete m_ui;
}

//---- settings ----
void CMainWindow::loadSettings()
{
    QSettings setting;

    m_puzzle_current_index = m_puzzle_index = setting.value("LastPuzzleIndex", 0).toInt();

    for(int i = 0; i <= m_puzzle_index; ++i)
        m_ui->m_page_game->addNewLevel( i );
}

void CMainWindow::saveSettings()
{
    QSettings setting;

    setting.setValue("LastPuzzleIndex", m_puzzle_index);
}

//---- slots ----
void CMainWindow::slot_nextPuzzle(int level)
{
    if( level > m_puzzle_index)
    {
        m_puzzle_index = level;
        m_ui->m_page_game->addNewLevel( m_puzzle_index );
    }
}

void CMainWindow::slot_jumpLevel( int level )
{
    m_ui->m_page_game->setPuzzleInfo( m_puzzle_manager.getPuzzle( level) );
}

void CMainWindow::slot_toHomePage()
{
    m_ui->m_stacked_widget->setCurrentIndex(0);
}

void CMainWindow::slot_startGame()
{
    m_ui->m_stacked_widget->setCurrentIndex( 1 );
    m_ui->m_page_game->jumpToLastLevel();
}

void CMainWindow::slot_toCreditsPage()
{
    m_ui->m_stacked_widget->setCurrentIndex( 2 );
}
