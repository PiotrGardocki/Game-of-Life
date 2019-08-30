#pragma once

#include <QtWidgets/QMainWindow>

#include <Model/DynamicCellsGrid.hpp>

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);

private:
	DynamicCellsGrid grid;
};
