#include "shape.h"
#include "circle.h"

#include <iostream>

using namespace std;

Circle::Circle() : Shape()
{
    // cout << "Circle default constructor" << endl;
    //From Shape class
    this->name = "Circle ";
    this->color = "Blue";

    this->radius = 0;
}

int Circle::area()
{

    float area = Shape::area(this->radius);
    cout << "The area is: " << endl;
    cout << "With a radius of: " << this->radius << endl;
    cout << area << endl;
    this->the_area = area;
}

void Circle::display()
{

    //Shape::display();
    cout << "The " << this->name << " is " << this->color << endl;
}

void Circle::set_radius(float radius)
{
    this->radius = radius;
}