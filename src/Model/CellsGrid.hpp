#pragma once

#include <vector>

class CellsGrid
{
public:
	CellsGrid(size_t columns, size_t rows);

	void setCell(size_t column, size_t row, bool alive);
	void turnCellOn(size_t column, size_t row);
	void turnCellOff(size_t column, size_t row);

	bool isCellAlive(size_t column, size_t row) const;

	size_t getColumnsNum() const;
	size_t getRowsNum() const;

private:
	size_t internalIndex(size_t column, size_t row) const;

private:
	std::vector<bool> cells;
	size_t columns;
};
