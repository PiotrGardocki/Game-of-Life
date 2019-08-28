#pragma once

#include <vector>

class CellsGrid
{
public:
	virtual std::vector<bool>::reference getCell(size_t column, size_t row) = 0;
	virtual std::vector<bool>::const_reference getCell(size_t column, size_t row) const = 0;

	virtual void setCell(int column, int row, bool alive) = 0;
	virtual void turnCellOn(int column, int row) = 0;
	virtual void turnCellOff(int column, int row) = 0;

	virtual size_t getColumnsNum() const = 0;
	virtual size_t getRowsNum() const = 0;
};
