#include "CellsUpdater.hpp"

CellsUpdater::CellsUpdater(CellsGrid* cellsGrid)
	: cellsGrid(cellsGrid)
{
}

void CellsUpdater::updateOneStep()
{
	auto columns = cellsGrid->getColumnsNum();
	auto rows = cellsGrid->getRowsNum();
	std::vector<unsigned short> neighboursCounter(columns * rows, 0);

	auto index = [columns](size_t column, size_t row) { return column + row * columns; };

	for (size_t column = 0; column < columns; ++column)
		for (size_t row = 0; row < rows; ++row)
			neighboursCounter.at(index(column, row)) = aliveNeighbours(column, row);

	for (size_t column = 0; column < columns; ++column)
		for (size_t row = 0; row < rows; ++row)
		{
			auto cell = cellsGrid->getCell(column, row);
			auto aliveNeighbours = neighboursCounter.at(index(column, row));

			if (cell)
			{
				if (aliveNeighbours < 2 || aliveNeighbours > 3)
					cell = false;
			}
			else
			{
				if (aliveNeighbours == 3)
					cell = true;
			}
		}
}

unsigned short CellsUpdater::aliveNeighbours(size_t column, size_t row)
{
	auto columns = cellsGrid->getColumnsNum() - 1;
	auto rows = cellsGrid->getRowsNum() - 1;
	auto aliveCount = 0;

	if (column > 0 && row > 0 &&		  cellsGrid->getCell(column - 1, row - 1))
		++aliveCount;
	if (row > 0 &&						  cellsGrid->getCell(column, row - 1))
		++aliveCount;
	if (column < columns && row > 0 &&	  cellsGrid->getCell(column + 1, row - 1))
		++aliveCount;
	if (column < columns &&				  cellsGrid->getCell(column + 1, row))
		++aliveCount;
	if (column < columns && row < rows && cellsGrid->getCell(column + 1, row + 1))
		++aliveCount;
	if (row < rows &&					  cellsGrid->getCell(column, row + 1))
		++aliveCount;
	if (column > 0 && row < rows &&		  cellsGrid->getCell(column - 1, row + 1))
		++aliveCount;
	if (column > 0 &&					  cellsGrid->getCell(column - 1, row))
		++aliveCount;

	return aliveCount;
}
