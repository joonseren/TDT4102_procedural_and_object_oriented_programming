#pragma once
#include "std_lib_facilities.h"
#include "AnimationWindow.h"

// Abstrakt klasse. Arvende konkrete klasser må implementere funksjonen draw()
// som tegner former i vinduet de skal bli vist i.
class Emoji
{
protected:
    Point centre;
    int radius;
public:
    Emoji(Point c, int r) : centre(c), radius(r) {};
    virtual void draw(AnimationWindow& win) = 0;
    virtual ~Emoji(){}; //destruktør
};

// 3a), b), c)
class Face : public Emoji
{
    
public:
    Face(Point c, int r) : Emoji(c, r) {};
    //virtual void draw(AnimationWindow&) {};
    virtual ~Face() {};
    void draw(AnimationWindow& win) override;

};

class EmptyFace : public Face
{
protected:
    Point eyePoint1;
    Point eyePoint2;

public:
    EmptyFace(Point c, int r, Point eP1, Point eP2) : Face(c, r), eyePoint1(eP1), eyePoint2(eP2) {}; 
    void draw(AnimationWindow& win) override;
};

class HappyFace : public EmptyFace
{
protected:
    Point mouthPoint;
public:
    HappyFace(Point c, int r, Point eP1, Point eP2, Point mP) : EmptyFace(c, r, eP1, eP2), mouthPoint(mP) {};
    void draw(AnimationWindow& win) override;

};

class SadFace : public HappyFace
{
public:
    SadFace(Point c, int r, Point eP1, Point eP2, Point mP) : HappyFace(c, r, eP1, eP2, mP) {};
    void draw(AnimationWindow& win) override;
}; 

class NaturalFace : public HappyFace
{
    Point startPoint;
    Point endPoint;
public:
    NaturalFace(Point c, int r, Point eP1, Point eP2, Point mP, Point sP, Point eP) : HappyFace(c, r, eP1, eP2, mP), startPoint(sP), endPoint(eP) {};
    void draw(AnimationWindow& win) override;
};

class WowFace : public HappyFace
{
public:
    WowFace(Point c, int r, Point eP1, Point eP2, Point mP) : HappyFace(c, r, eP1, eP2, mP) {};
    void draw(AnimationWindow& win) override;
};

class SwearingFace : public HappyFace
{
private:
    string word;
public:
    SwearingFace(Point c, int r, Point eP1, Point eP2, Point mP, string w) : HappyFace(c, r, eP1, eP2, mP), word(w) {};
    void draw(AnimationWindow& win) override;
};

