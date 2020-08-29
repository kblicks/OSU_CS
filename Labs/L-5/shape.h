#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

using namespace std;

class Shape
{
protected:
    string name;
    string color;

public:
    Shape();
    Shape(string, string);
    ~Shape();

    //Overload area
    int area();
    int area(int, int);
    float area(float);

    void display();
};

#endif