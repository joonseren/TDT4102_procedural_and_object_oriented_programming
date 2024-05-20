#include "TetrisWindow.h"
#include "Tetromino.h"



TetrisWindow::TetrisWindow(int x, int y, int width, int height, const std::string &title) : 
    AnimationWindow{x, y, width * Tetromino::blockSize, height * Tetromino::blockSize, title},
    height{height}, width{width},
    currentTetromino{Tetromino({0, 0}, generateRandomTetromino())}
    {
        gridMatrix.resize(height, std::vector<TetrominoType>(width, TetrominoType::NONE));
        drawBackground();
        drawCurrentTetromino();
    }

void TetrisWindow::drawBackground() {
    draw_rectangle({0, 0}, width * Tetromino::blockSize, height * Tetromino::blockSize, TDT4102::Color::light_gray, TDT4102::Color::black);
    for (int i{0}; i < width; i++) {
        int x = Tetromino::blockSize + i*Tetromino::blockSize;
        int y1 = 0;
        int y2 = height*Tetromino::blockSize;
        draw_line({x, y1}, {x, y2}, TDT4102::Color::white);
    }
}

TetrominoType TetrisWindow::generateRandomTetromino() {
    std::random_device rd;
    std::default_random_engine generator(rd());
    std::uniform_int_distribution <int> distribution(0, static_cast<int>(TetrominoType::I));
    TetrominoType tet = static_cast<TetrominoType>(distribution(generator));
    //std::cout << "Tetrominotype: " << tetTypeToString.at(tet) << std::endl;
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
    std::cout << "Grid-size: " << gridMatrix.size() << std::endl;
    std::cout << "Matrix-size: " << currentTetromino.getMatrixSize() << std::endl;
    unsigned int framesSinceLastTetronimoMove = 0;
    const unsigned int framesPerTetronimoMove = 20;

    while(!should_close()) { 
        drawBackground();
        framesSinceLastTetronimoMove++;
        if(framesSinceLastTetronimoMove >= framesPerTetronimoMove) {
            framesSinceLastTetronimoMove = 0;
            /********************************************************/
            moveTetrominoDown();
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
    static bool lastRightKeyState = false;
    static bool lastLeftKeyState = false;
    static bool lastDownKeyState = false;

    bool currentZKeyState = is_key_down(KeyboardKey::Z);
    bool currentUpKeyState = is_key_down(KeyboardKey::UP);
    bool currentRightKeyState = is_key_down(KeyboardKey::RIGHT);
    bool currentLeftKeyState = is_key_down(KeyboardKey::LEFT);
    bool currentDownKeyState = is_key_down(KeyboardKey::DOWN);
    bool insideWindow = currentTetromino.getPosition().x > -(Tetromino::blockSize + 1) && currentTetromino.getPosition().x < (width - currentTetromino.getMatrixSize())*Tetromino::blockSize;
    
    if (!insideWindow) {
        if (currentTetromino.getPosition().x < 0) {
            currentTetromino.setPosition(0, currentTetromino.getPosition().y);
        }
    } else {    
        if(currentZKeyState && !lastZKeyState) {
            currentTetromino.rotateCounterClockwise();

        }

        if(currentUpKeyState && !lastUpKeyState) {
            currentTetromino.rotateClockwise();
        }

        if (currentRightKeyState && !lastRightKeyState) {
            currentTetromino.moveRight();
        }

        if (currentLeftKeyState && !lastLeftKeyState) {
            currentTetromino.moveLeft();
        }

        if (currentDownKeyState && !lastDownKeyState) {
            currentTetromino.moveDown();
        }
    }


    lastZKeyState = currentZKeyState;
    lastUpKeyState = currentUpKeyState;
    lastRightKeyState = currentRightKeyState;
    lastLeftKeyState = currentLeftKeyState;
    lastDownKeyState = currentDownKeyState;
}

void TetrisWindow::moveTetrominoDown() {
    if (currentTetromino.getPosition().y < (gridMatrix.size() - currentTetromino.getMatrixSize())*Tetromino::blockSize) {
        currentTetromino.moveDown();
    }
}

void TetrisWindow::fastenTetromino() {
    for (int row{0}; row < currentTetromino.getMatrixSize(); row ++) {
        for (int column{0}; column < currentTetromino.getMatrixSize(); column++) {
            
        }
    }
}