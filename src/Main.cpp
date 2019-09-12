#include <QApplication>
#include "CPuzzleManager.hpp"
#include <QDebug>

int main (int argc, char *argv[])
{
	QApplication app(argc, argv);

	CPuzzleManager level_manager;

	return app.exec();
}
