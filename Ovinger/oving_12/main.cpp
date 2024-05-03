#include "Tetromino.h"
#include "TetrisWindow.h"



int main() {
	
	TetrisWindow tw{1, 1, 10, 20, "Tetris"};
    
	tw.wait_for_close();
	return 0;
}
