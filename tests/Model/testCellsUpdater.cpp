#include <catch2/catch.hpp>
#include <Model/DynamicCellsGrid.hpp>
#include <Model/CellsUpdater.hpp>

#include <fstream>

#include <iostream>

namespace
{
	void readGrid(std::ifstream& file, CellsGrid& grid)
	{
		for (size_t row = 0; row < grid.getRowsNum(); ++row)
		{
			for (size_t column = 0; column < grid.getColumnsNum(); ++column)
			{
				short alive;
				file >> alive;
				grid.setCell(column, row, static_cast<bool>(alive));
			}
		}
	}

	bool compareGrids(const CellsGrid& grid1, const CellsGrid& grid2)
	{
		if (grid1.getColumnsNum() != grid2.getColumnsNum())
			return false;
		if (grid1.getRowsNum() != grid2.getRowsNum())
			return false;

		for (size_t column = 0; column < grid1.getColumnsNum(); ++column)
			for (size_t row = 0; row < grid1.getRowsNum(); ++row)
				if (grid1.getCell(column, row) != grid2.getCell(column, row))
					return false;

		return true;
	}
}

TEST_CASE("CellsUpdater works properly", "[Model][CellsUpdater]")
{
	std::ifstream testCases("Model/CellsUpdaterCases.txt");
	if (!testCases.is_open())
		FAIL("CellsUpdaterCases.txt not found");

	size_t columns, rows;

	while (testCases >> columns >> rows)
	{
		DynamicCellsGrid originalGrid(columns, rows);
		DynamicCellsGrid expectedGridAfterUpdate(columns, rows);
		readGrid(testCases, originalGrid);
		readGrid(testCases, expectedGridAfterUpdate);

		CellsUpdater updater(&originalGrid);
		updater.updateOneStep();

		CHECK(compareGrids(originalGrid, expectedGridAfterUpdate));
	}
}
