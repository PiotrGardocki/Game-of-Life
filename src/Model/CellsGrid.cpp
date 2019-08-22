#include "CellsGrid.hpp"

CellsGrid::CellsGrid(size_t columns, size_t rows)
	: cells(columns * rows, false)
	, columns(columns)
{
}

void CellsGrid::setCell(size_t column, size_t row, bool alive)
{
	cells.at(internalIndex(column, row)) = alive;
}

void CellsGrid::turnCellOn(size_t column, size_t row)
{
	setCell(column, row, true);
}

void CellsGrid::turnCellOff(size_t column, size_t row)
{
	setCell(column, row, true);
}

bool CellsGrid::isCellAlive(size_t column, size_t row) const
{
	return cells.at(internalIndex(column, row));
}

size_t CellsGrid::getColumnsNum() const
{
	return columns;
}

size_t CellsGrid::getRowsNum() const
{
	return cells.size() / columns;
}

size_t CellsGrid::internalIndex(size_t column, size_t row) const
{
	return row * columns + column;
}
