#include "Tile.h"



// For aa sette Tilelabel i henhold til state
const std::map<Cell, std::string> cellToSymbol{{Cell::closed, ""},
									 			{Cell::open, ""},
									 	  		{Cell::flagged, "|>"}};

Tile::Tile(TDT4102::Point pos, int size) : 
	Button({pos.x, pos.y}, 1.5*size, size, "") {
		setButtonColor(TDT4102::Color::silver);
	}


bool Tile::getIsMine() {
	return isMine;
}
void Tile::setIsMine(bool input) {
	isMine = input;
}


void Tile::open() {
	if ((state == Cell::closed) && getIsMine()) {
		setButtonColor(TDT4102::Color::black);
		set_label_color(TDT4102::Color::red);
		set_label("X"); 
		state = Cell::open;
	}
	else if (state == Cell::closed) {
		setButtonColor(TDT4102::Color::white);
		state = Cell::open;
	} else {
		std::cout << "nothing happens" << std::endl;
	}
}


void Tile::flag() {
	if (state == Cell::flagged) {
		set_label(cellToSymbol.at(Cell::closed));
		state = Cell::closed;
	} else {
		set_label_color(TDT4102::Color::red);
		set_label(cellToSymbol.at(Cell::flagged));
		state = Cell::flagged;
	}
}

void Tile::setAdjMines(int n) {
	if (n < 9 && n > 0) {
		set_label_color(minesToColor.at(n));
		set_label(std::to_string(n));
	}
}
