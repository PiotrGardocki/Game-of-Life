#include <catch2/catch.hpp>
#include <Model/CellsReader.hpp>
#include <Model/DynamicCellsGrid.hpp>

TEST_CASE("CellsReader properly communicates with CellsGrid", "[Model][CellsReader]")
{
	DynamicCellsGrid grid(6, 4);
	CellsReader reader(&grid);

	for (size_t column = 0; column < 6; ++column)
		for (size_t row = 0; row < 4; ++row)
			CHECK_FALSE(reader.isCellAlive(column, row));

	grid.turnCellOn(3, 2);
	grid.turnCellOn(1, 0);
	grid.turnCellOn(2, 1);

	CHECK(reader.isCellAlive(3, 2));
	CHECK(reader.isCellAlive(1, 0));
	CHECK(reader.isCellAlive(2, 1));
}
