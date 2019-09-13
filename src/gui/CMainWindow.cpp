#include "CMainWindow.hpp"
#include "ui_CMainWindow.h"

CMainWindow::CMainWindow(QWidget *parent) :
	QMainWindow(parent),
    m_ui(new Ui::CMainWindow)
{
    m_ui->setupUi(this);
}

CMainWindow::~CMainWindow()
{
    delete m_ui;
}
