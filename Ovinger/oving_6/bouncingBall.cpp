// TDT4102 ØVING 6
// Oppgave 4

#include "std_lib_facilities.h"
#include "AnimationWindow.h"
#include "bouncingBall.h"
#include <map>
#include "Color.h"

constexpr Point BOUNCE_WINDOW_TOP_LEFT{50, 50};
constexpr int BOUNCE_WINDOW_WIDTH{800}; 
constexpr int BOUNCE_WINDOW_HEIGHT{500};


// 4a)



void bouncingBall() {
    AnimationWindow window{BOUNCE_WINDOW_TOP_LEFT.x, BOUNCE_WINDOW_TOP_LEFT.y, 
                           BOUNCE_WINDOW_WIDTH, BOUNCE_WINDOW_HEIGHT, "Bouncing ball"};
    
    
    map<int, Color> colorMap {
        {1, Color::blue},
        {2, Color::red},
        {3, Color::green},
        {4, Color::yellow},
    };
    
    const int radius{40};
    int alpha{1};
    int velocity{2};
    Color colour_up{Color::blue};
    Color colour_down{Color::red};
    Color color;
    int x{0};
    int y{360};
    int increment_x{0};
    int increment_y{0};
    int count_bounce_top{0};
    int count_bounce_bottom{0};
    int count_num_passes{0};

    // 4b), c)
    // read from configuration file

    filesystem::path config_file{"konfigurasjon.txt"};
    ifstream is{config_file};
    Config slow;
    is >> slow;
    Config fast;
    is >> fast;

    // initialise the run
    velocity = slow.velocity;
    //colour_up = colorMap[fast.colorUp];
    //colour_down = colorMap.at(fast.colorDown);
    color = colour_up;

    while (!window.should_close()) {
        // determine increments based on the velocity
        increment_x = 2*velocity * cos(alpha);
        increment_y = 2*velocity * sin(alpha);

        // movement i x-direction
        if ((increment_x + x) > (window.width() + radius)) {
            // reached right side - wrap around to the leftmost
            x = 0;
            // increment counter which counts number of full left-to-right passes
            count_num_passes++;
            // alternate between slow and fast configuration every fifth pass
            if (count_num_passes % 3 == 0) {
                // change configuration
                if (velocity == slow.velocity) {
                   velocity = fast.velocity;
                   colour_down = Color::green;
                   colour_up = Color::yellow;
                }
                else {
                    velocity = slow.velocity;
                    colour_down = Color::red;
                    colour_up = Color::blue;
                    
                
                }
    
            }
        } else {
            // moving rightwards
            x += increment_x;
        }

        // movement i y-direction
        if (((count_bounce_top + count_bounce_bottom) % 2) == 0) {
            if (y < radius) {
                count_bounce_top++;
                color = colour_down; 
            }
            y -= increment_y;

            
        } else {
            if(y > (BOUNCE_WINDOW_HEIGHT - radius)) {
                count_bounce_bottom++;
                color = colour_up;
            }
            y += increment_y;

        }
        window.draw_circle({x, y}, radius, color);
        window.next_frame();
    }
}


// 4b)
istream& operator>>(istream& is, Config& cfg) {
    int tmpUp, tmpDown, tmpVel;
    is >> tmpUp >> tmpDown >> tmpVel;
    cfg = {tmpUp, tmpDown, tmpVel};
    return is;
}

