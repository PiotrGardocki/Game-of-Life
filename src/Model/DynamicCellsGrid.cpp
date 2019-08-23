#include "DynamicCellsGrid.hpp"

DynamicCellsGrid::DynamicCellsGrid(size_t columns, size_t rows)
	: cells(columns, std::vector<bool>(rows, false))
{
}

std::vector<bool>::reference DynamicCellsGrid::getCell(size_t column, size_t row)
{
	return cells.at(column).at(row);
}

std::vector<bool>::const_reference DynamicCellsGrid::getCell(size_t column, size_t row) const
{
	return cells.at(column).at(row);
}

void DynamicCellsGrid::setCell(size_t column, size_t row, bool alive)
{
	auto columnsNum = getColumnsNum();
	auto rowsNum = getRowsNum();

	if (column < columnsNum && row < rowsNum)
	{
		getCell(column, row) = alive;
	}
}

void DynamicCellsGrid::turnCellOn(size_t column, size_t row)
{
	setCell(column, row, true);
}

void DynamicCellsGrid::turnCellOff(size_t column, size_t row)
{
	setCell(column, row, false);
}

size_t DynamicCellsGrid::getColumnsNum() const
{
	return cells.size();
}

size_t DynamicCellsGrid::getRowsNum() const
{
	return cells.size() ? cells.at(0).size() : 0;
}
