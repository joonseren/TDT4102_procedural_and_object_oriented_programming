// Oving 3 TDT4102
// ———————————————————
// Implementation file

#include "cannonball.h"

// 2a)
double acclY() {
    return -9.81;
}

// 2b)
double velY(double initVelocityY, double time) {
    return initVelocityY + acclY()*time;
}

// 2c)
double posX(double initPositionX, double initVelocityX, double time) {
    return initPositionX + initVelocityX*time;
}

double posY(double initPositionY, double initVelocityY, double time) {
    return initPositionY + initVelocityY*time + 0.5*acclY()*time*time;
}



// 2d)
void printTime(int time) {
    int timer = time / 3600;
    int sekundIgjen = time % 3600;
    int minutt = sekundIgjen / 60;
    int sekund = sekundIgjen % 60;

    cout << "Tid: " << timer << ":" << minutt << ":" << sekund << endl;

}


// 2e)
double flightTime(double initVelocityY) {
    return (-2 * initVelocityY)/acclY();

}

// 4a)
double getUserInputTheta() {
    double theta = 0.0; 
    cout << "Skriv inn ønsket vinkel i grader: " << endl;
    cin >> theta;
    return theta;
}

double getUserInputInitVelocity() {
    double initVelocity = 0.0;
    cout << "Skriv inn ønsket startfart i m/s: " << endl;
    cin >> initVelocity;
    return initVelocity;
}

double degToRad(double deg) {
    return deg *(M_PI/180.0);
}

double getVelocityX(double theta, double initVelocity) {
    return initVelocity*cos(theta);
}

double getVelocityY(double theta, double initVelocity) {
    return initVelocity*sin(theta);
}

vector<double> getVelocityVector(double theta, double initVelocity) {
    vector<double> velocity;
    velocity.push_back(getVelocityX(degToRad(theta), initVelocity));    
    velocity.push_back(getVelocityY(degToRad(theta), initVelocity));

    /*
    cout << "x: " << velocity.at(0) << "\n"
    << "y: " << velocity.at(1) << endl;
    */
    return velocity;

}

// 4b)
double getDistanceTraveled(double velocityX, double velocityY) {
    /*
    velocityX = getVelocityVector(getUserInputTheta(), getUserInputInitVelocity()).at(0);
    velocityY = getVelocityVector(getUserInputTheta(), getUserInputInitVelocity()).at(1);
    */

    double distance = posX(0, velocityX, flightTime(velocityY));
    // cout << "Distance traveled: " << distance << endl;
    return distance;
}

// 4c)
double targetPractice(double distanceToTarget, double distanceTraveled) {
    double deviation = distanceToTarget - distanceTraveled;
    return deviation;
}

// 5c)
void playTargetPractice() {
    cout << "Velkommen til kanonskytespillet! \n"
    << "Reglene er som følger: \n"
    << "Du får ti forsøk på å treffe blinken, som er plassert tilfelding mellom 100 og 1000 meter unna. \n"
    << "For hvert forsøk kan du velge utskytningsvinkel og -fart. \n"
    << "Du får vite hvor langt unna du er etter hvert forsøk, og du vinner hvis kulen treffer innen 5 meter. \n"
    << "Lykke til kuktryne!\n" << endl;

    // Oppretter blinken
    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<int> distribution(100, 1000);
    int blink = distribution(generator);

    int maxTries = 10;
    for (int i = 1; i <= maxTries; ++i) {
    
        cout << "Forsøk: " << i << endl;
        cout << "Target: " << blink << endl;
        cout << "Skriv inn 0 i vinkel for å avslutte.\n" << endl;
        cout << "\n" << endl;

        int vinkel = getUserInputTheta();
        int startfart = getUserInputInitVelocity();
        getVelocityVector(vinkel, startfart);
        double velocityX = getVelocityVector(vinkel, startfart).at(0); 
        double velocityY = getVelocityVector(vinkel, startfart).at(1); 
        
        
        if (vinkel == 0) {
            break;
        }else if (fabs(targetPractice(blink, getDistanceTraveled(velocityX, velocityY))) <= 5){
            cout << "Gratulerer du vant!" << endl;
            break;
        } else { 
            cout << "Prøv igjen! \n" << endl;

        }
        cout << "Flight time: " << flightTime(velocityY) << endl;
        cout << "Distance to target: " << targetPractice(blink, getDistanceTraveled(velocityX, velocityY)) << endl;
        cout << "Your hit: " << getDistanceTraveled(velocityX, velocityY) << endl;

        cout << "\n" << endl;

        if (i == maxTries) {
            cout << "Beklager du tapte" << endl;
        }
    }
    return;
}


