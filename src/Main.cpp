#include <QApplication>
#include "CMainWindow.hpp"
#include <QDebug>

int main (int argc, char *argv[])
{
	QApplication app(argc, argv);
    app.setApplicationName("Chromatic-cute");
    app.setOrganizationName("Chromatic-cute");

    CMainWindow main_window;
    main_window.show();

	return app.exec();
}
