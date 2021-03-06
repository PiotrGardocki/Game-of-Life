#include "MainWindow.hpp"

#include <View/GridWidget.hpp>

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
	, grid(7, 5)
{
	setMinimumHeight(200);

	QWidget* centralWidget = new QWidget(this);
	setCentralWidget(centralWidget);

	QVBoxLayout* layout = new QVBoxLayout;
	centralWidget->setLayout(layout);

	GridWidget* gridWidget = new GridWidget(grid);
	layout->addWidget(gridWidget, 1);

	QWidget* buttons = new QWidget(this);
	layout->addWidget(buttons);
	QHBoxLayout* buttonsLayout = new QHBoxLayout;
	buttons->setLayout(buttonsLayout);

	QWidget* buttons2 = new QWidget(this);
	layout->addWidget(buttons2);
	QHBoxLayout* buttonsLayout2 = new QHBoxLayout;
	buttons2->setLayout(buttonsLayout2);

	QPushButton* button = new QPushButton("Update");
	buttonsLayout->addWidget(button);
	QPushButton* zoomIn = new QPushButton("+");
	buttonsLayout->addWidget(zoomIn);
	QPushButton* zoomOut = new QPushButton("-");
	buttonsLayout->addWidget(zoomOut);

	QPushButton* clockStart = new QPushButton("Start Clock");
	buttonsLayout2->addWidget(clockStart);
	QPushButton* clockStop = new QPushButton("Stop Clock");
	buttonsLayout2->addWidget(clockStop);
	QPushButton* speedUp = new QPushButton("Speed Up");
	buttonsLayout2->addWidget(speedUp);
	QPushButton* slowDown = new QPushButton("Slow Down");
	buttonsLayout2->addWidget(slowDown);

	connect(button, &QPushButton::clicked, gridWidget, &GridWidget::updateOneStep);
	connect(zoomIn, &QPushButton::clicked, gridWidget, &GridWidget::zoomIn);
	connect(zoomOut, &QPushButton::clicked, gridWidget, &GridWidget::zoomOut);
	connect(clockStart, &QPushButton::clicked, gridWidget, &GridWidget::startClock);
	connect(clockStop, &QPushButton::clicked, gridWidget, &GridWidget::stopClock);
	connect(speedUp, &QPushButton::clicked, gridWidget, &GridWidget::speedUp);
	connect(slowDown, &QPushButton::clicked, gridWidget, &GridWidget::slowDown);
}
