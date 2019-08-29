#include "MainWindow.hpp"
#include <QtWidgets/QApplication>

#include "Model/CellsGrid.hpp"

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	return a.exec();
}
