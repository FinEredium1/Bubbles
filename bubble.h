#ifndef BUBBLE_H
#define BUBBLE_H

#include <SFML/Graphics.hpp>

class Bubble
{
private:
    sf::CircleShape _bub;
    double _xdir;
    double _ydir;
    double _xpos;
    double _ypos;
    int _radius;
    sf::Color _color;

public:
    Bubble();
    Bubble(int, double, double, double, double, sf::Color);


    void draw(sf::RenderWindow &);
    void updatePosition(double, double);

};

#endif