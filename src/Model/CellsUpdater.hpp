#pragma once

#include "CellsGrid.hpp"

class CellsUpdater
{
public:
	explicit CellsUpdater(CellsGrid* cellsGrid = nullptr);

	void updateOneStep();

private:
	unsigned short aliveNeighbours(size_t column, size_t row);

private:
	CellsGrid* cellsGrid = nullptr;
};
