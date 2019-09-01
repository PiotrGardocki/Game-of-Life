#include "MainWindow.hpp"

#include <View/GridWidget.hpp>

#include <QVBoxLayout>
#include <QHBoxLayout>
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

	QWidget* buttons = new QWidget(this);
	layout->addWidget(buttons);
	QHBoxLayout* buttonsLayout = new QHBoxLayout;
	buttons->setLayout(buttonsLayout);

	QPushButton* button = new QPushButton("Update");
	buttonsLayout->addWidget(button);
	QPushButton* zoomIn = new QPushButton("+");
	buttonsLayout->addWidget(zoomIn);
	QPushButton* zoomOut = new QPushButton("-");
	buttonsLayout->addWidget(zoomOut);

	connect(button, &QPushButton::clicked, gridWidget, &GridWidget::updateOneStep);
	connect(zoomIn, &QPushButton::clicked, gridWidget, &GridWidget::zoomIn);
	connect(zoomOut, &QPushButton::clicked, gridWidget, &GridWidget::zoomOut);
}
