// Oving 3 TDT4102
// ———————————————————
// Main file

#include "cannonball.h"
#include "utilities.h"


void testDeviation(double compareOperand, double toOperand, double maxError, string name);


int main() {
    // 3c)
    // Start test function
    /*
    double maxError = 0.0001;
    testDeviation(posX(0.0, 50.0, 5.0), 250.0, maxError, "posX(0.0, 50.0, 5.0)");
    // End test function

    // 4a)
    double theta = getUserInputTheta();
    double initVelocity = getUserInputInitVelocity();

    getVelocityVector(theta, initVelocity);

    // 4b)
    
    double velocityX = getVelocityVector(theta, initVelocity).at(0); 
    double velocityY = getVelocityVector(theta, initVelocity).at(1); 

    getDistanceTraveled(velocityX, velocityY);

    // 4c)
    double distanceToTarget = 0.0;
    cout << "Skriv inn avstanden til målet i meter: " << endl;
    cin >> distanceToTarget;

    double deviationToTarget = targetPractice(distanceToTarget, getDistanceTraveled(velocityX, velocityY));

    cout << deviationToTarget << endl;    

    */
    //————————————————————————————————————————————————————————————————————————————————————————
    // Oppgave 5:
    /*
    randomNumberGenerator();
    cout << "——————————————————————————————————————" << endl;

    randomWithLimits();
    */
    
    playTargetPractice();

    return 0;
}






// 3b)
void testDeviation(double compareOperand, double toOperand, double maxError, string name) {
    double testValue = fabs(compareOperand - toOperand);
    if (testValue <= maxError) {
        cout << name << " is valid" << endl;
    }  else {
        cout << name << " is not valid. Expected " <<
        toOperand << " got " << compareOperand << endl;
    }
}

