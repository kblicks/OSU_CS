#include "shape.h"
#include "square.h"
#include "rectangle.h"

#include <iostream>

using namespace std;

Square::Square() : Rectangle()
{
    // cout << "Square constructor" << endl;
}

void Square::set_width(float sqwidth)
{
    Rectangle::set_width(sqwidth);
    Rectangle::set_height(sqwidth);
}

void Square::set_height(float sqheight)
{
    Rectangle::set_height(sqheight);
    Rectangle::set_width(sqheight);
}

void Square::set_name(string name)
{
    this->name = name;
}
void Square::set_color(string color)
{
    this->color = color;
}