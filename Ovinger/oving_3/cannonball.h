// Oving 3 TDT4102 
// ———————————————
// Header-file oppg. 1-4

#include "std_lib_facilities.h"


// Deklarasjoner av funksjoner
// 1a)
double acclY();
// 1b)
double velY(double initVelocityY, double time);
// 1c)
double posX(double initPositionX, double initVelocityX, double time);
double posY(double initPositionY, double initVelocityY, double time);
// 1d)
void printTime(int time);
// 1e)
double flightTime(double initVelocityY);

// 4a)
double getUserInputTheta();

double getUserInputInitVelocity();

double degToRad(double deg);

double getVelocityX(double theta, double initVelocity);

double getVelocityY(double theta, double initVelocity);

vector<double> getVelocityVector(double theta, double initVelocity);

double getDistanceTraveled(double velocityX, double velocityY);

double targetPractice(double distanceToTarget, double distanceTraveled);

void playTargetPractice();

