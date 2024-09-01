#include "bubble.h"

using namespace std;
using namespace sf;

Bubble::Bubble()
{
    _radius = 50;
    _bub.setRadius(_radius);
}


Bubble::Bubble(int radius, double x, double y, double x_vel, double y_vel, Color color)
{
    _radius = radius;
    _xpos = x;
    _ypos = y;
    _xdir = x_vel;
    _ydir = y_vel;
    _color = color;
    _bub.setRadius(_radius);
    _bub.setPosition(_xpos, _ypos);
    _bub.setFillColor(_color);
}



void Bubble::draw(RenderWindow &win)
{
    win.draw(_bub);
}

void Bubble::updatePosition(double wid, double height)
{
    if (_xpos > (wid - (_radius * 2) ) || _xpos < 0.0){
        _xdir *= -1;
    }

    if (_ypos > (height - (_radius * 2) ) || _ypos < 0.0){
        _ydir *= -1;
    }
    _xpos += _xdir;
    _ypos += _ydir;
    _bub.setPosition(_xpos, _ypos);
}