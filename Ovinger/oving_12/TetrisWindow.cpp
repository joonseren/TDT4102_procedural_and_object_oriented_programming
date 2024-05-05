#include "TetrisWindow.h"
#include "Tetromino.h"



TetrisWindow::TetrisWindow(int x, int y, int width, int height, const std::string &title) : 
    AnimationWindow{x, y, width * Tetromino::blockSize, height * Tetromino::blockSize, title},
    height{height}, width{width},
    currentTetromino{Tetromino({0, 0}, generateRandomTetromino())}
    {
        gridMatrix.resize(height, std::vector<TetrominoType>(width, TetrominoType::NONE));
        draw_rectangle({0, 0}, width * Tetromino::blockSize, height * Tetromino::blockSize, TDT4102::Color::light_gray, TDT4102::Color::black);
        drawCurrentTetromino();
    }

TetrominoType TetrisWindow::generateRandomTetromino() {
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_int_distribution <int> distribution(0, static_cast<int>(TetrominoType::I));
    TetrominoType tet = static_cast<TetrominoType>(distribution(generator));
    std::cout << "Tetrominotype: " << tetTypeToString.at(tet) << std::endl;
    return tet;
}

void TetrisWindow::drawCurrentTetromino() {
    //std::cout << "map-size: " << tetTypeToString.size() << std::endl;

    for (int row{0}; row < currentTetromino.getMatrixSize(); row ++) {
        for (int column{0}; column < currentTetromino.getMatrixSize(); column++) {
            //std::cout << "Block type at (" << row << "," << column << "): " << tetTypeToString.at(currentTetromino.getBlock(row, column)) << std::endl;
            if (tetTypeToString.at(currentTetromino.getBlock(row, column)) == tetTypeToString.at(currentTetromino.getType())) {;
                TDT4102::Point pos = {currentTetromino.getPosition().x + row*Tetromino::blockSize, currentTetromino.getPosition().y + column*Tetromino::blockSize};
                draw_rectangle(pos, Tetromino::blockSize, Tetromino::blockSize, getInitialColorMap().at(currentTetromino.getType()), TDT4102::Color::black);
            }
        }
    }
}

void TetrisWindow::run() {
    unsigned int framesSinceLastTetronimoMove = 0;
    const unsigned int framesPerTetronimoMove = 20;

    while(!should_close()) { 
        framesSinceLastTetronimoMove++;
        if(framesSinceLastTetronimoMove >= framesPerTetronimoMove) {
            framesSinceLastTetronimoMove = 0;
            /********************************************************/
            //Tetromino::moveDown();
            /********************************************************/
        }
        handleInput();
        
        /********************************************************/
        drawCurrentTetromino();
        /********************************************************/

        next_frame();
    }
}


void TetrisWindow::handleInput() {

    static bool lastZKeyState = false;
    static bool lastUpKeyState = false;

    bool currentZKeyState = is_key_down(KeyboardKey::Z);
    bool currentUpKeyState = is_key_down(KeyboardKey::UP);

    
    if(currentZKeyState && !lastZKeyState) {
        std::cout << "Hello from z\n";
    }

    if(currentUpKeyState && !lastUpKeyState) {
        std::cout << "Hello from up\n";
    }


    lastZKeyState = currentZKeyState;
    lastUpKeyState = currentUpKeyState;
}

