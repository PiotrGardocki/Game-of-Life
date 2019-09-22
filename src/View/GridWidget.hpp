#pragma once

#include <QtWidgets/QWidget>

#include <Model/CellsGrid.hpp>

class GridWidget : public QWidget
{
	Q_OBJECT

	struct ZoomOption
	{
		int cellSize;
		int borderSize;
	};

public:
	explicit GridWidget(CellsGrid& grid);

public slots:
	void updateOneStep();

	void zoomIn();
	void zoomOut();

protected:
	void paintEvent(QPaintEvent* event) override;
	void mousePressEvent(QMouseEvent* event) override;
	void mouseReleaseEvent(QMouseEvent* event) override;
	void mouseMoveEvent(QMouseEvent* event) override;

private:
	int getCellSize() const;
	int getBorderSize() const;

private:
	CellsGrid& grid;
	size_t currentZoomOption;

	bool mousePressed = false;

	static std::vector<ZoomOption> zoomOptions;
};
