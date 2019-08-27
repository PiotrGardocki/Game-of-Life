#include <catch2/catch.hpp>
#include <Model/DynamicCellsGrid.hpp>

TEST_CASE("DynamicCellsGrid is properly constructed", "[Model][DynamicCellsGrid]")
{
	DynamicCellsGrid grid;
	size_t columns = 0;
	size_t rows = 0;
	SECTION("1")
	{
	}
	SECTION("2")
	{
		grid = DynamicCellsGrid(5, 4);
		columns = 5;
		rows = 4;
	}
	SECTION("3")
	{
		grid = DynamicCellsGrid(0, 0);
	}
	SECTION("4")
	{
		grid = DynamicCellsGrid(3, 3);
		columns = 3;
		rows = 3;
	}

	CHECK(grid.getColumnsNum() == columns);
	CHECK(grid.getRowsNum() == rows);

	for (size_t column = 0; column < columns; ++column)
		for (size_t row = 0; row < rows; ++row)
			CHECK_FALSE(grid.getCell(column, row));
}
