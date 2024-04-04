//TDT4102 Øving 9

#include "Window.h"

MeetingWindow::MeetingWindow(int x, int y, int w, int h, std::string title) 
    : TDT4102::AnimationWindow(x, y, w, h, title)
    , quitBtn({900, 455}, btnW, btnH, "Quit")
    , personName({pad, pad}, fieldW, fieldH, "Person Name")
    , personEmail({pad, pad + fieldH + pad}, fieldW, fieldH, "Person Email")
    , personSeats({pad, (pad + fieldH)*2 + pad}, fieldW, fieldH, "Person Seats")
    , personNewBtn({pad, (pad + fieldH)*4 + pad}, btnW, btnH, "Add to list")
    , clearTextBtn({2*pad + btnW, (pad + fieldH)*4 + pad}, btnW, btnH, "Clear Text")
{
    add(quitBtn);
    quitBtn.setCallback(std::bind(&MeetingWindow::cb_quit, this));


    add(personName);
    add(personEmail);
    add(personSeats);

    add(clearTextBtn);    
    clearTextBtn.setCallback(std::bind(&MeetingWindow::cb_clear, this));

    add(personNewBtn);
    personNewBtn.setCallback(std::bind(&MeetingWindow::newPerson, this));



} 

void MeetingWindow::cb_quit() {
    AnimationWindow::close();
}

bool MeetingWindow::newPerson() {
    std::string name = personName.getText();
    std::string email = personEmail.getText();
    std::string seatText = personSeats.getText();

    if (name.empty() || email.empty()) {
        std::cout << "Navn og e-post må fylles ut." << std::endl;
    }

    int seats = 0;
    bool validSeats = false;

    /*
    if (!seatText.empty()) {
        try {
            seats = std::stoi(seatText);
            validSeats = seats > 0;
        } catch (const std::exception& e) {
            std::cout << "Ugyldig antall seter: " << e.what() << std::endl;
        }
    }
    */

    if (!validSeats) {
        std::cout << "Oppretter person uten bil." << std::endl;
        people.emplace_back(std::make_shared<Person>(name, email));
    } else {
        std::cout << "Oppretter person med bil." << std::endl;
        auto car = std::make_unique<Car>(seats);
        people.emplace_back(std::make_shared<Person>(name, email, std::move(car)));
    }

    personName.setText("");
    personEmail.setText("");
    personSeats.setText("");

    return true;
}


void MeetingWindow::cb_clear() {
    personName.setText(" ");
    personEmail.setText(" ");
    personSeats.setText(" ");
}

void MeetingWindow::printPeople() {
    std::cout << "Participant overview:" << std::endl;
    std::cout << "—————————————————————\n" << std::endl;
    if (newPerson()) {
        for (int i{0}; i < people.size(); i++) {
            std::cout << "Place number " << (i + 1) << ":\n" << *people.at(i) << std::endl; 
        }
    }
}