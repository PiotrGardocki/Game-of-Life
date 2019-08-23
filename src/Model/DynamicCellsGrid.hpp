#pragma once

#include "CellsGrid.hpp"

class DynamicCellsGrid : public CellsGrid
{
public:
	DynamicCellsGrid() = default;
	DynamicCellsGrid(size_t columns, size_t rows);

	virtual std::vector<bool>::reference getCell(size_t column, size_t row);
	virtual std::vector<bool>::const_reference getCell(size_t column, size_t row) const;

	void setCell(size_t column, size_t row, bool alive);
	void turnCellOn(size_t column, size_t row);
	void turnCellOff(size_t column, size_t row);

	size_t getColumnsNum() const;
	size_t getRowsNum() const;

private:
	std::vector<std::vector<bool>> cells;  // columns<rows>
};
