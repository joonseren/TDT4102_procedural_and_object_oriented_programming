#include "Tetromino.h"
#include "TetrisWindow.h"



int main() {
	
	TetrisWindow tw{500, 500, 10, 30, "Tetris"};
	tw.run();
	
	return 0;
}
