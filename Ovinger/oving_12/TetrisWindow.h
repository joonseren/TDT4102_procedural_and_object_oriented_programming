#pragma once
#include "AnimationWindow.h"
#include "Tetromino.h"
#include "widgets/TextInput.h"
#include "widgets/Button.h"
#include <iostream>
#include <random>


class TetrisWindow : public TDT4102::AnimationWindow {

public:
    TetrisWindow(int x, int y, int width, int height, const std::string &title);
    void run();


private:
    const int width;
	const int height;	
    std::vector<std::vector<TetrominoType>> gridMatrix;
    Tetromino currentTetromino;
    TetrominoType generateRandomTetromino();
    void drawCurrentTetromino();
    void drawBackground();
    void handleInput();
    void moveTetrominoDown();
    void fastenTetromino();
    

};