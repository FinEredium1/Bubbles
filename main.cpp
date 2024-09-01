// Author: Fardin Ahmed

#include <SFML/Graphics.hpp>
#include "bubble.h"
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace sf;

#include <iostream>
using namespace std;

// Function for creating new bubble
void make_bubble(vector<Bubble *> &bv, double x = (rand() % 301 + 100) , double y = (rand() % 301 + 100))
{
    
    Color color[] = {Color::Black, Color::Blue, Color::Green, Color::Magenta, Color::Red, Color::White, Color::Yellow};  // 7 colors excepts cyan
    double radius, x_vel, y_vel;
    int color_idx;

    radius = rand() % 41 + 10;
    x_vel = rand() / (double)RAND_MAX * (0.1667 + 0.1667) - 0.1667;
    y_vel = rand() / (double)RAND_MAX * (0.1667 + 0.1667) - 0.1667;
    color_idx = rand() % 8;

    x -= radius; // centerize x
    y -= radius; // centerize y

    bv.push_back(new Bubble(radius, x, y, x_vel, y_vel, color[color_idx]));  // call Bubble constructor

}

int main()
{
    // all vars down here
    srand(time(0));
    int screenWidth = 640;
    int screenHeight = 640;
    bool show = false;

    RenderWindow window(VideoMode(screenWidth, screenHeight), "Whole lotta Bubbles!!!");
    window.setFramerateLimit(60);


    vector<Bubble *> bobs;  // bubble vector

    // creates first 5 bubbles
    for (int i(0); i < 5; i++)
        {
            make_bubble(bobs);
        }


    Event event;

    while (window.isOpen())
    {

        window.clear(Color::Cyan); // Cyan background

        // Show = True on first left-mouseclick. Displays the bubbles on screen
        if (show)
        {
            for (Bubble *bob : bobs)
            {
                bob->updatePosition(screenWidth, screenHeight);
                bob->draw(window);
            }
        }
        window.display();

        while (window.pollEvent(event))
        {

            if (event.type == Event::Closed)
            {

                window.close();
            }

            else if (event.type == Event::MouseButtonPressed)
            {

                if (event.mouseButton.button == Mouse::Left)
                {
                    show = true;
                    make_bubble(bobs, event.mouseButton.x, event.mouseButton.y); // make new bubbles with mouse pos arguments
                }
            }

            else if (event.type == Event::KeyPressed)
            {

                if (event.key.code == Keyboard::Escape || event.key.code == Keyboard::Q)
                {
                    window.close();
                }
                else if (event.key.code == Keyboard::D && bobs.size() > 0){
                    delete bobs.back();
                    bobs.pop_back();
                }
            }
        }
    }

    // deallocate memory
    for (Bubble *bob : bobs)
    {
        delete bob;
    }

    bobs.clear(); // clear vector
    return 0;
}
