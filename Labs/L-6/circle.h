#ifndef CIRCLE_H
#define CIRCLE_H

#include <iostream>

using namespace std;

class Circle : public Shape
{
private:
    float radius;

public:
    Circle();
    // Rectangle(string, string);
    //~Rectangle();
    int area();
    void display();
    void set_radius(float);
};

#endif