#include "GridWidget.hpp"

#include <Model/CellsUpdater.hpp>
#include <Model/CellsReader.hpp>

#include <QPainter>
#include <QPaintEvent>

std::vector<GridWidget::ZoomOption> GridWidget::zoomOptions = { {1,0}, {2,0}, {4,0}, {6,1}, {7,1} };
std::vector<int> GridWidget::intervalOptions = { 1000, 500, 250, 125, 60, 30, 15 };

GridWidget::GridWidget(CellsGrid& grid)
	: grid(grid)
	, currentZoomOption(3)
	, timer(new QTimer(this))
{
	connect(timer, &QTimer::timeout, this, &GridWidget::updateOneStep);
}

void GridWidget::updateOneStep()
{
	CellsUpdater updater(&grid);
	updater.updateOneStep();
	repaint();
}

void GridWidget::startClock()
{
	timer->start(intervalOptions.at(currentIntervalIndex));
}

void GridWidget::stopClock()
{
	timer->stop();
}

void GridWidget::speedUp()
{
	if (currentIntervalIndex < intervalOptions.size() - 1)
	{
		++currentIntervalIndex;
		if (timer->isActive())
			startClock();
	}
}

void GridWidget::slowDown()
{
	if (currentIntervalIndex > 0)
	{
		--currentIntervalIndex;
		if (timer->isActive())
			startClock();
	}
}

void GridWidget::zoomIn()
{
	if (currentZoomOption < zoomOptions.size() - 1)
	{
		++currentZoomOption;
		repaint();
	}
}

void GridWidget::zoomOut()
{
	if (currentZoomOption > 0)
	{
		--currentZoomOption;
		repaint();
	}
}

void GridWidget::paintEvent(QPaintEvent* event)
{
	CellsReader reader(&grid);

	QPainter painter(this);

	auto border = getBorderSize();
	auto cell = getCellSize();

	auto rect = event->rect();
	auto maxColumns = rect.width() / (border + cell);
	auto maxRows = rect.height() / (border + cell);

	QPen pen;
	if (border)
	{
		pen.setWidth(border);
		pen.setColor(Qt::gray);
	}
	else
		pen.setStyle(Qt::PenStyle::NoPen);

	painter.setPen(pen);

	QSize cellSize(cell + border, cell + border);
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

	painter.setBrush({ Qt::black });
	for (size_t column = 0; column < grid.getColumnsNum(); ++column)
	{
		for (auto row = grid.getRowsNum(); row < maxRows; ++row)
		{
			QPoint cellPoint = startPoint + QPoint(column * (cellSize.width()), row * (cellSize.height()));
			QRect cellRect(cellPoint, cellSize);
			painter.drawRect(cellRect);
		}
	}
	for (auto column = grid.getColumnsNum(); column < maxColumns; ++column)
	{
		for (size_t row = 0; row < grid.getRowsNum(); ++row)
		{
			QPoint cellPoint = startPoint + QPoint(column * (cellSize.width()), row * (cellSize.height()));
			QRect cellRect(cellPoint, cellSize);
			painter.drawRect(cellRect);
		}
	}
	for (auto column = grid.getColumnsNum(); column < maxColumns; ++column)
	{
		for (auto row = grid.getRowsNum(); row < maxRows; ++row)
		{
			QPoint cellPoint = startPoint + QPoint(column * (cellSize.width()), row * (cellSize.height()));
			QRect cellRect(cellPoint, cellSize);
			painter.drawRect(cellRect);
		}
	}
}

void GridWidget::mousePressEvent(QMouseEvent* event)
{
	mousePressed = true;
	handleCellInput(event);
}

void GridWidget::mouseReleaseEvent(QMouseEvent* event)
{
	mousePressed = false;
}

void GridWidget::mouseMoveEvent(QMouseEvent* event)
{
	handleCellInput(event);
}

void GridWidget::handleCellInput(QMouseEvent* event)
{
	auto position = event->pos();
	auto cellWidth = getCellSize() + getBorderSize();

	size_t column = position.x() / cellWidth;
	size_t row = position.y() / cellWidth;

	//grid.flipCell(column, row);
	grid.turnCellOn(column, row);

	repaint();
}

int GridWidget::getCellSize() const
{
	return zoomOptions.at(currentZoomOption).cellSize;
}

int GridWidget::getBorderSize() const
{
	return zoomOptions.at(currentZoomOption).borderSize;
}
