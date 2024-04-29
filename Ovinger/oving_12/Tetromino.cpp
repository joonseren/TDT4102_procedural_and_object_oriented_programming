#include "Tetromino.h"
#include <map>
    
const std::map<TetrominoType, std::vector<std::vector<int>>> initialMatrixMap {

    {
    TetrominoType::J,
        {
        {0, 0, 0},
        {1, 1, 1},
        {0, 0, 1}
        }
    }
};

Tetromino::Tetromino() : topLeftCorner{0, 0}, matrixSize{0} {};

Tetromino::Tetromino(TDT4102::Point startingPoint, TetrominoType tetType) : 
topLeftCorner{startingPoint}, matrixSize{int(initialMatrixMap.at(tetType).size())} {

    blockMatrix.resize(matrixSize, std::vector<TetrominoType>(matrixSize, TetrominoType::NONE));

    const auto& initialMatrix = initialMatrixMap.at(tetType);

    for(int row = 0; row < matrixSize; row++) {
        for(int column = 0; column < row; column++) {
            if(initialMatrix[row][column] == 1) {
                blockMatrix[row][column] = TetrominoType::J;
            } else {
                blockMatrix[row][column] = TetrominoType::NONE;
            }
        }
    }

};

void Tetromino::rotateCounterClockwise() {
    //Første rotasjon, med hensyn på diagonalen
    for(int row = 0; row < matrixSize; row++){
        for(int column = 0; column < row; column++){
            std::swap(blockMatrix[row][column], blockMatrix[column][row]);
        }
    }

    //Andre rotasjon, med hensyn på den midtre raden
    for(int row = 0; row < matrixSize/2; row++){
        for(int column = 0; column < matrixSize; column++){
            std::swap(blockMatrix[row][column], blockMatrix[matrixSize-row-1][column]);
            
        }
    }
}

void Tetromino::rotateClockwise() {
    //Første rotasjon, med hensyn på diagonalen
    for(int row = 0; row < matrixSize; row++){
        for(int column = 0; column < row; column++){
            std::swap(blockMatrix[row][column], blockMatrix[column][row]);
        }
    }
     
    //Andre rotasjon, med hensyn på den midtre kolonnen
    for(int row = 0; row < matrixSize; row++){
        for(int column = 0; column < matrixSize/2; column++){
            std::swap(blockMatrix[row][column], blockMatrix[row][matrixSize-column-1]);
        }
    }
}