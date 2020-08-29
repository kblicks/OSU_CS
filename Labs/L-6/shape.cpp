#include "shape.h"

#include <iostream>
#include <cmath>
using namespace std;

Shape::Shape()
{
    //cout << "Default constructor of shape called" << endl;
    this->name = "Unknown";
    this->color = "TBA";
}

Shape::Shape(string name, string color)
{
    // cout << "non-default constructor of shape" << endl;
    this->name = name;
    this->color = color;
}

Shape::~Shape()
{
    //cout << "destructor of shape " << endl;
}

int Shape::area()
{
    return 0;
}

int Shape::area(int width, int height)
{

    int area = width * height;
    return area;
}

float Shape::area(float radius)
{

    float area = 3.14159265359 * radius * radius;
    return area;
}
/*
void Shape::display()
{

    cout << "The " << this->name << " is " << this->color << endl;
} */

bool operator>(const Shape &s1, const Shape &s2)
{
    return s1.the_area > s2.the_area;
}

bool operator<(const Shape &s1, const Shape &s2)
{
    return s1.the_area < s2.the_area;
}