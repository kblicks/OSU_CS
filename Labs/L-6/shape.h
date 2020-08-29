#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

using namespace std;

class Shape
{
private:
    //float the_area;

protected:
    string name;
    string color;
    float the_area;

public:
    Shape();
    Shape(string, string);
    ~Shape();

    //Overload area
    int area();
    int area(int, int);
    float area(float);
    //Friend overload to compare area

    bool operator>(const Shape &, const Shape &);
    bool operator<(const Shape &, const Shape &);

    virtual void display() = 0;
};

#endif