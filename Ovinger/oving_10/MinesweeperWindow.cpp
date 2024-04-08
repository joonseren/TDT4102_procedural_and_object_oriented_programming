#include "MinesweeperWindow.h"
#include <iostream>

MinesweeperWindow::MinesweeperWindow(int x, int y, int width, int height, int mines, const string &title) : 
	// Initialiser medlemsvariabler, bruker konstruktoren til AnimationWindow-klassen
	AnimationWindow{x, y, width * cellSize, (height + 1) * cellSize, title},
	width{width}, height{height}, mines{mines}
{
	// Legg til alle tiles i vinduet
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			tiles.emplace_back(new Tile{ Point{j * cellSize, i * cellSize}, cellSize});
			tiles.back()->setCallback(std::bind(&MinesweeperWindow::cb_click, this));
			auto temp = tiles.back().get();
			add(*temp); 
		}
	}
	// Legg til miner på tilfeldige posisjoner

	int i = 0;
	while (i < mines) {
		std::random_device rd;
		std::default_random_engine generator(rd());
		std::uniform_int_distribution <int> distribution(0, tiles.size());
		int minePosition = distribution(generator); 

		if (!tiles.at(minePosition) -> getIsMine()) {
			tiles.at(minePosition) -> setIsMine(true);
			tiles.at(minePosition) -> setButtonColor(TDT4102::Color::sky_blue);
		i++;
		}
	}
}

vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const {
	vector<Point> points;
	for (int di = -1; di <= 1; ++di) {
		for (int dj = -1; dj <= 1; ++dj) {
			if (di == 0 && dj == 0) {
				continue;
			}

			Point neighbour{ xy.x + di * cellSize,xy.y + dj * cellSize };
			if (inRange(neighbour)) {
				points.push_back(neighbour);
			}
		}
	}
	return points;
}

void MinesweeperWindow::openTile(Point xy) {
	if (MinesweeperWindow::at(xy) -> getState() != Cell::closed) {
		return;
	}

	MinesweeperWindow::at(xy) -> open();
	if (!MinesweeperWindow::at(xy) -> getIsMine()) {
		std::vector<Point> adjPoints = MinesweeperWindow::adjacentPoints(xy);
		int mines = MinesweeperWindow::countMines(adjPoints);
		if (mines > 0) {
			MinesweeperWindow::at(xy) -> setAdjMines(mines);
		} else if (mines == 0) {
			for (const auto& tile : adjPoints) {
				MinesweeperWindow::openTile(tile);
			}
		}
	} 
}

void MinesweeperWindow::flagTile(Point xy) {
	if (MinesweeperWindow::at(xy) -> getState() != Cell::open) {
		MinesweeperWindow::at(xy) -> flag();
	}
}

//Kaller openTile ved venstreklikk og flagTile ved hoyreklikk
void MinesweeperWindow::cb_click() {
	
	Point xy{this->get_mouse_coordinates()};

	if (!inRange(xy)) {
		return;
	}
	if (this->is_left_mouse_button_down()) {
		openTile(xy);
	}
	else if(this->is_right_mouse_button_down()){
		flagTile(xy);
	}
}

int MinesweeperWindow::countMines(vector<Point> coords) const {
	int i = 0;
	for (const auto& tile : coords) {
		if (MinesweeperWindow::at(tile) -> getIsMine()) {
			i++;
		}
	}
	return i;
}


