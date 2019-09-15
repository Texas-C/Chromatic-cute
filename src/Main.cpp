#include <QApplication>
#include "CMainWindow.hpp"
#include <QDebug>

int main (int argc, char *argv[])
{
	QApplication app(argc, argv);
    app.setApplicationName("Chromatic-qt");
    app.setOrganizationName("Chromatic");

    CMainWindow main_window;
    main_window.show();

	return app.exec();
}
