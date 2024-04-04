//TDT4102 Øving 9

#pragma once
#include "Meeting.h"
#include "AnimationWindow.h"
#include "widgets/TextInput.h"
#include "widgets/Button.h"
#include "Point.h"
#include "std_lib_facilities.h"


class MeetingWindow : public TDT4102::AnimationWindow {
private:
    static constexpr int pad = 10;
    static constexpr int btnW = 100;
    static constexpr int btnH = 30;
    static constexpr int fieldW = 300;
    static constexpr int fieldH = 30;


    TDT4102::Button quitBtn;
    TDT4102::TextInput personName;
    TDT4102::TextInput personEmail;
    TDT4102::TextInput personSeats;
    TDT4102::Button personNewBtn;
    TDT4102::Button clearTextBtn;


    std::vector<shared_ptr<Person>> people;
    

public:
    MeetingWindow(int x, int y, int w, int h, std::string title);
    void cb_quit();
    void cb_clear();
    bool newPerson();

    void printPeople();
     
};