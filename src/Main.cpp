#include <QApplication>
#include "CMainWindow.hpp"
#include <QDebug>

int main (int argc, char *argv[])
{
	QApplication app(argc, argv);

    CMainWindow main_window;
    main_window.show();

	return app.exec();
}
