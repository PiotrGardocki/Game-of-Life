#include "GridWidget.hpp"

#include <Model/CellsUpdater.hpp>
#include <Model/CellsReader.hpp>

#include <QPainter>
#include <QPaintEvent>

GridWidget::GridWidget(CellsGrid& grid)
	: grid(grid)
{
}

void GridWidget::updateOneStep()
{
	CellsUpdater updater(&grid);
	updater.updateOneStep();
	repaint();
}

void GridWidget::paintEvent(QPaintEvent* event)
{
	CellsReader reader(&grid);

	QPainter painter(this);
	painter.setPen(Qt::gray);

	QSize cellSize(7, 7);
	QPoint startPoint = event->rect().topLeft();

	for (size_t column = 0; column < grid.getColumnsNum(); ++column)
	{
		for (size_t row = 0; row < grid.getRowsNum(); ++row)
		{
			bool isCellAlive = reader.isCellAlive(column, row);
			if (isCellAlive)
				painter.setBrush({ Qt::white });
			else
				painter.setBrush({ Qt::black });

			QPoint cellPoint = startPoint + QPoint(column * (cellSize.width()), row * (cellSize.height()));
			QRect cellRect(cellPoint, cellSize);
			painter.drawRect(cellRect);
		}
	}
}
