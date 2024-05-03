#include "TetrisWindow.h"
#include <iostream>


TetrisWindow::TetrisWindow(int x, int y, int width, int height, const std::string &title) : 
    AnimationWindow{x, y, width * Tetromino::blockSize, height * Tetromino::blockSize, title},
    height{height}, width{width} 
    {
        gridMatrix.resize(height, std::vector<TetrominoType>(width, TetrominoType::NONE));

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
        //Kall draw-funksjonene her
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

