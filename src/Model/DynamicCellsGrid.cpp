#include "DynamicCellsGrid.hpp"

DynamicCellsGrid::DynamicCellsGrid(size_t columns, size_t rows)
	: cells(columns, std::vector<bool>(rows, false))
{
}

std::vector<bool>::reference DynamicCellsGrid::getCell(int column, int row)
{
	adaptGridSize(column, row);
	
	if (column < 0)
		column = 0;
	if (row < 0)
		row = 0;

	return cells.at(column).at(row);
}

std::vector<bool>::const_reference DynamicCellsGrid::getCell(int column, int row) const
{
	return cells.at(column).at(row);
}

void DynamicCellsGrid::setCell(int column, int row, bool alive)
{
	auto cell = getCell(column, row);
	cell = alive;
}

void DynamicCellsGrid::turnCellOn(int column, int row)
{
	setCell(column, row, true);
}

void DynamicCellsGrid::turnCellOff(int column, int row)
{
	setCell(column, row, false);
}

void DynamicCellsGrid::flipCell(int column, int row)
{
	auto cell = getCell(column, row);
	cell.flip();
}

size_t DynamicCellsGrid::getColumnsNum() const
{
	return cells.size();
}

size_t DynamicCellsGrid::getRowsNum() const
{
	return cells.size() ? cells.at(0).size() : 0;
}

void DynamicCellsGrid::adaptGridSize(int column, int row)
{
	auto columnsNum = static_cast<int>(getColumnsNum());
	auto rowsNum = static_cast<int>(getRowsNum());

	if (column < 0)
		appendColumnsAtLeft(-column);
	else if (column >= columnsNum)
		appendColumnsAtRight(column - columnsNum + 1);
	
	if (row < 0)
		appendRowsAtTop(-row);
	else if (row >= rowsNum)
		appendRowsAtBottom(row - rowsNum + 1);
}

void DynamicCellsGrid::appendRowsAtTop(size_t num)
{
	auto columnsNum = getColumnsNum();
	for (size_t column = 0; column < columnsNum; ++column)
		for (size_t i = 0; i < num; ++i)
		{
			auto& col = cells.at(column);
			col.insert(col.cbegin(), false);
		}
}

void DynamicCellsGrid::appendRowsAtBottom(size_t num)
{
	auto columnsNum = getColumnsNum();
	for (size_t column = 0; column < columnsNum; ++column)
		for (size_t i = 0; i < num; ++i)
			cells.at(column).push_back(false);
}

void DynamicCellsGrid::appendColumnsAtLeft(size_t num)
{
	for (size_t i = 0; i < num; ++i)
		cells.emplace(cells.cbegin(), getRowsNum(), false);
}

void DynamicCellsGrid::appendColumnsAtRight(size_t num)
{
	for (size_t i = 0; i < num; ++i)
	cells.emplace_back(getRowsNum(), false);
}
