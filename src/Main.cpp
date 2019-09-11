#include <QApplication>
#include "CLevelManager.hpp"
#include <QDebug>

int main (int argc, char *argv[])
{
	QApplication app(argc, argv);

	CLevelManager level_manager;

	return app.exec();
}
