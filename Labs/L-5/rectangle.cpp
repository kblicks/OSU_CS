#include "shape.h"
#include "rectangle.h"

#include <iostream>

using namespace std;

Rectangle::Rectangle() : Shape()
{
    //From Shape class
    this->name = "Rectangle ";
    this->color = "Yellow";

    this->width = 0;
    this->height = 0;
}

int Rectangle::area()
{

    int area = Shape::area(this->width, this->height);
    cout << "With a width of: " << this->width << " and a height of: " << this->height << endl;

    cout << "The area is: " << endl;
    cout << area << endl;
}

void Rectangle::display()
{
    Shape::display();
}

void Rectangle::set_width(float width)
{
    this->width = width;
}
float Rectangle::get_width()
{
    return this->width;
}

void Rectangle::set_height(float height)
{
    this->height = height;
}

float Rectangle::get_height()
{
    return this->height;
}

void Rectangle::set_name(string name)
{
    this->name = name;
}
void Rectangle::set_color(string color)
{
    this->color = color;
}