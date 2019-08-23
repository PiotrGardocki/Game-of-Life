#pragma once

#include "CellsGrid.hpp"

class CellsReader
{
public:
	explicit CellsReader(const CellsGrid* cellsGrid = nullptr);
	bool isCellAlive(size_t column, size_t row) const;

private:
	const CellsGrid* cellsGrid = nullptr;
};
