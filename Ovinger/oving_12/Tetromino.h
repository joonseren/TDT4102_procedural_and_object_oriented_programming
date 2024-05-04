#pragma once
#include "Point.h"
#include "Color.h"
#include <vector>
#include <string>
#include <map>


enum class TetrominoType{J, L, T, S, Z, O, I, NONE};

extern const std::map<TetrominoType, std::vector<std::vector<int>>> initialMatrixMap;

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
    

   
private: 
    int matrixSize;
    TDT4102::Point topLeftCorner;
    std::vector<std::vector<TetrominoType>> blockMatrix;
};  