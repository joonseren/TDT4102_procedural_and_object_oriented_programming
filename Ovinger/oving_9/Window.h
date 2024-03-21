//TDT4102 Øving 9

#pragma once
#include "Meeting.h"
#include "AnimationWindow.h"
#include "widgets/TextInput.h"
#include "widgets/Button.h"

class MeetingWindow : public TDT4102::AnimationWindow {
    
public:
    MeetingWindow(int x, int y, int w, int h, std::string title) : TDT4102::AnimationWindow(x, y, w, h, title) {}; 
};