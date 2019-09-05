#pragma once

#include "CellsGrid.hpp"

class DynamicCellsGrid : public CellsGrid
{
public:
	DynamicCellsGrid() = default;
	DynamicCellsGrid(size_t columns, size_t rows);

	std::vector<bool>::reference getCell(int column, int row) override;
	std::vector<bool>::const_reference getCell(int column, int row) const override;

	void setCell(int column, int row, bool alive) override;
	void turnCellOn(int column, int row) override;
	void turnCellOff(int column, int row) override;
	void flipCell(int column, int row) override;

	size_t getColumnsNum() const override;
	size_t getRowsNum() const override;

private:
	void adaptGridSize(int column, int row);

	void appendRowsAtTop(size_t num);
	void appendRowsAtBottom(size_t num);
	void appendColumnsAtLeft(size_t num);
	void appendColumnsAtRight(size_t num);

private:
	std::vector<std::vector<bool>> cells;  // columns<rows>
};
