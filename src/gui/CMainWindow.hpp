#ifndef CMAINWINDOW_H
#define CMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class CMainWindow;
}

class CMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit CMainWindow(QWidget *parent = nullptr);
	~CMainWindow();

private:
	Ui::CMainWindow *ui;
};

#endif // MAINWINDOW_H
