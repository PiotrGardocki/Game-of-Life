#pragma once

#include <QtWidgets/QWidget>

#include <Model/CellsGrid.hpp>

class GridWidget : public QWidget
{
	Q_OBJECT

public:
	explicit GridWidget(CellsGrid& grid);

public slots:
	void updateOneStep();

protected:
	void paintEvent(QPaintEvent* event) override;

private:
	CellsGrid& grid;
};
