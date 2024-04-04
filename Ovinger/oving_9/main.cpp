// TDT4102 Øving 9

#include "Window.h"


int main() {
    /*
    auto bil1 = std::make_unique<Car>(5);
    auto bil2 = std::make_unique<Car>(5);


    std::shared_ptr<Person> jens = std::make_shared<Person>("Jens", "jens@gmail.com", std::move(bil1));
    std::shared_ptr<Person> sebastian = std::make_shared<Person>("Sebastian", "seb@gmail.com", std::move(bil2));
    std::shared_ptr<Person> helene = std::make_shared<Person>("Helene", "Helenebella@icloud.com");
    std::shared_ptr<Person> jensUBil = std::make_shared<Person>("Jensern", "jens@gmail.com");

    Meeting digitaliseringITK(1, 10, 14, Campus::trondheim, "digitalieringsmøte for ITK", sebastian);

    Meeting m(1, 10, 14, Campus::trondheim, "Styremøtet nettverket", jens);
    std::cout << m; 
    m.addParticipant(jensUBil);
    std::cout << m;
    m.findPotentialCoDriving(digitaliseringITK);
    */

    MeetingWindow mwin(50, 50, 1000, 500, "GUI - Campus Samkjøring NTNU - EcoTrans AS");
    mwin.wait_for_close();
    mwin.newPerson();
    mwin.printPeople();

    return 0;
}
