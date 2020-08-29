#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include "square.h"

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    //Create Shape obj
    Shape s1;

    Rectangle r;
    float width, height;
    string color;
    cout << "Enter a color for your Rectangle: " << endl;
    getline(cin, color);
    cout << "Enter a width: " << endl;
    cin >> width;
    cout << "Enter a height: " << endl;
    cin >> height;

    cin.clear();
    cin.ignore(10000, '\n');

    r.set_color(color);
    r.set_width(width);
    r.set_height(height);
    r.display();
    r.area();

    Square s;
    s.set_name("Square");

    string square_color;
    cout << "What color do you want your square to be" << endl;
    getline(cin, square_color);
    s.set_color(square_color);

    s.set_width(width);
    s.display();
    s.area();

    s.set_height(height);
    s.display();
    s.area();

    Circle c;

    c.display();
    c.set_radius(10);
    c.area();
}