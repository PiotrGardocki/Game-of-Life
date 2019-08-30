#include "MainWindow.hpp"

#include <View/GridWidget.hpp>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, grid(7, 5)
{
	GridWidget* widget = new GridWidget(grid);
	setCentralWidget(widget);
}
