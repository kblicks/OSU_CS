#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>

using namespace std;

class Rectangle : public Shape
{
private:
    float width;
    float height;

public:
    Rectangle();

    void set_width(float);
    void set_height(float);
    void set_name(string);
    void set_color(string);
    float get_width();
    float get_height();
    // Rectangle(string, string);
    //~Rectangle();
    int area();
    void display();
};

#endif