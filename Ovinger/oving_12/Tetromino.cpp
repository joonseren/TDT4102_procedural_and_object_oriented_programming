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
    },
    {
    TetrominoType::L,
        {
        {0, 0, 0},
        {1, 1, 1},
        {1, 0, 0}
        }
    },
    {
    TetrominoType::T,
        {
        {0, 0, 0},
        {1, 1, 1},
        {0, 1, 0}
        }
    },
    {
    TetrominoType::S,
        {
        {0, 0, 0},
        {0, 1, 1},
        {1, 1, 0}
        }
    },
    {
    TetrominoType::Z,
        {
        {0, 0, 0},
        {1, 1, 0},
        {0, 1, 1}
        }
    },
    {
    TetrominoType::O,
        {
        {1, 1},
        {1, 1}
        }
    },
        {
    TetrominoType::I,
        {
        {0, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 0, 0},
        {0, 1, 0, 0}
        }
    },

};

const std::map<TetrominoType, TDT4102::Color> initialColorMap {
    {TetrominoType::J, TDT4102::Color::blue},
    {TetrominoType::L, TDT4102::Color::orange},
    {TetrominoType::T, TDT4102::Color::purple},
    {TetrominoType::S, TDT4102::Color::green},
    {TetrominoType::Z, TDT4102::Color::red},
    {TetrominoType::O, TDT4102::Color::yellow},
    {TetrominoType::I, TDT4102::Color::turquoise},
};

Tetromino::Tetromino() : topLeftCorner{0, 0}, matrixSize{0} {};

Tetromino::Tetromino(TDT4102::Point startingPoint, TetrominoType tetType) : 
topLeftCorner{startingPoint}, matrixSize{int(initialMatrixMap.at(tetType).size())} {

    blockMatrix.resize(matrixSize, std::vector<TetrominoType>(matrixSize, TetrominoType::NONE));

    const auto& initialMatrix = initialMatrixMap.at(tetType);

    for(int row = 0; row < matrixSize; row++) {
        for(int column = 0; column < row; column++) {
            if(initialMatrix[row][column] == 1) {
                blockMatrix[row][column] = tetType;
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

void Tetromino::moveDown() {
    topLeftCorner.y += blockSize;
}

void Tetromino::moveLeft() {
    topLeftCorner.x -= blockSize;
}

void Tetromino::moveRight() {
    topLeftCorner.x += blockSize;
}

bool Tetromino::blockExist(int row, int column) {
    if (blockMatrix[row][column] != TetrominoType::NONE) {
        return true;
    } else {return false;} 
}

TetrominoType Tetromino::getBlock(int row, int column) {
    return blockMatrix[row][column];
}

int Tetromino::getMatrixSize() {
    return matrixSize;
}

TDT4102::Point Tetromino::getPosition() {
    return topLeftCorner;
}

