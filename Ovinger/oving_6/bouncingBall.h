// TDT4102 ØVING 6
// Oppgave 4

#pragma once
void bouncingBall();

// 4a)
struct Config {
    int colorUp;
    int colorDown;
    int velocity;
};


istream& operator>>(istream& is, Config& cfg);


