#pragma once
#include "Point.h"
#include "Color.h"
#include <vector>
#include <string>
#include <map>
#include <iostream>


enum class TetrominoType{J, L, T, S, Z, O, I, NONE};

extern const std::map<TetrominoType, std::vector<std::vector<int>>> initialMatrixMap;

//extern const std::map<TetrominoType, TDT4102::Color> initialColorMap;
const std::map<TetrominoType, TDT4102::Color>& getInitialColorMap();

extern const std::map<TetrominoType, char> tetTypeToString;

class Tetromino {
public:
    static constexpr int blockSize {30};
    Tetromino();
    Tetromino(TDT4102::Point startingPoint, TetrominoType tetType);
    
    void rotateClockwise();
    void rotateCounterClockwise();
    void moveDown();
    void moveLeft();
    void moveRight();
    bool blockExist(int row, int column);
    TetrominoType getBlock(int row, int column);
    int getMatrixSize();
    TDT4102::Point getPosition();
    TetrominoType getType();
    void setPosition(int x, int y);
    

   
private:
    TetrominoType tetType;
    int matrixSize;
    TDT4102::Point topLeftCorner;
    std::vector<std::vector<TetrominoType>> blockMatrix;
};  