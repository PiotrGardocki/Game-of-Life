#include "MainWindow.hpp"

#include <View/GridWidget.hpp>

#include <QVBoxLayout>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, grid(7, 5)
{
	QWidget* centralWidget = new QWidget(this);
	setCentralWidget(centralWidget);

	QVBoxLayout* layout = new QVBoxLayout;
	centralWidget->setLayout(layout);

	GridWidget* gridWidget = new GridWidget(grid);
	layout->addWidget(gridWidget);

	QPushButton* button = new QPushButton("Update");
	layout->addWidget(button);

	connect(button, &QPushButton::clicked, gridWidget, &GridWidget::updateOneStep);
}
