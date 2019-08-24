#pragma once

#include "CellsGrid.hpp"

class DynamicCellsGrid : public CellsGrid
{
public:
	DynamicCellsGrid() = default;
	DynamicCellsGrid(size_t columns, size_t rows);

	std::vector<bool>::reference getCell(size_t column, size_t row) override;
	std::vector<bool>::const_reference getCell(size_t column, size_t row) const override;

	void setCell(int column, int row, bool alive);
	void turnCellOn(int column, int row);
	void turnCellOff(int column, int row);

	size_t getColumnsNum() const override;
	size_t getRowsNum() const override;

private:
	void appendRowsAtTop(size_t num);
	void appendRowsAtBottom(size_t num);
	void appendColumnsAtLeft(size_t num);
	void appendColumnsAtRight(size_t num);

private:
	std::vector<std::vector<bool>> cells;  // columns<rows>
};
