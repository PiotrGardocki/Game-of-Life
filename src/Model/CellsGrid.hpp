#pragma once

#include <vector>

class CellsGrid
{
public:
	virtual std::vector<bool>::reference getCell(size_t column, size_t row) = 0;
	virtual std::vector<bool>::const_reference getCell(size_t column, size_t row) const = 0;
};
