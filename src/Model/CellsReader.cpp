#include "CellsReader.hpp"

CellsReader::CellsReader(const CellsGrid* cellsGrid)
	: cellsGrid(cellsGrid)
{
}

bool CellsReader::isCellAlive(size_t column, size_t row) const
{
	return static_cast<bool>(cellsGrid->getCell(column, row));
}
