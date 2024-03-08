// TDT4102 Øving 7

#include "Emoji.h"


// 3c)
void Face::draw(AnimationWindow& win) {
    win.draw_circle(centre, radius, Color::yellow);
}

void EmptyFace::draw(AnimationWindow& win) {
    win.draw_circle(centre, radius + 2, Color::black);
    win.draw_circle(centre, radius, Color::yellow);
    win.draw_circle(eyePoint1, radius/5 + 2, Color::black);
    win.draw_circle(eyePoint2, radius/5 + 2, Color::black);
    win.draw_circle(eyePoint1, radius/5, Color::ghost_white);
    win.draw_circle(eyePoint2, radius/5, Color::ghost_white);
    win.draw_circle(eyePoint1, radius/8, Color::black);
    win.draw_circle(eyePoint2, radius/8, Color::black);
    
}

void HappyFace::draw(AnimationWindow& win) {
    EmptyFace::draw(win);
    win.draw_arc(mouthPoint, radius, radius, 210, 330, Color::black);
}

void SadFace::draw(AnimationWindow& win) {
    EmptyFace::draw(win);
    win.draw_arc(mouthPoint, radius, radius, 35, 145, Color::black);
}

void NaturalFace::draw(AnimationWindow& win) {
    EmptyFace::draw(win);
    win.draw_line(startPoint, endPoint, Color::black);
}

void WowFace::draw(AnimationWindow& win) {
    EmptyFace::draw(win);
    win.draw_circle(mouthPoint, radius/4, Color::black);
    win.draw_circle(mouthPoint, radius/4 - 2, Color::yellow);
}

void SwearingFace::draw(AnimationWindow& win) {
    EmptyFace::draw(win);
    win.draw_text(mouthPoint, word, Color::black, radius/3);
}


