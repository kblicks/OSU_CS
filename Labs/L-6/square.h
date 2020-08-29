#ifndef SQUARE_H
#define SQUARE_H

#include "rectangle.h"
#include <iostream>

using namespace std;

class Square : public Rectangle
{

public:
    Square();

    void set_width(float);
    void set_height(float);
    void set_name(string);
    void set_color(string);
    //int area();
};

#endif