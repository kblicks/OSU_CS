#include "shape.h"
#include "rectangle.h"
#include "circle.h"
#include "square.h"

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    //Create Shape obj
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
    cout << "setting name" << endl;
    r.set_name("Square");

    string square_color;
    cout << "What color do you want your square to be" << endl;
    getline(cin, square_color);
    r.set_color(square_color);

    int size;
    cout << "Enter a size: " << endl;
    cin >> size;

    cin.clear();
    cin.ignore(10000, '\n');

    s.set_height(size);
    r.display();
    s.area();

    Circle c;

    c.display();
    c.set_radius(10);
    c.area();

    if (r > c)
    {
        cout << "Rectangle's area is greater than Circle's area" << endl;
    }
    if (r < c)
    {
        cout << "The Circle's area is greater than Rectangle's area" << endl;
    }
    if (c > s)
    {
        cout << "The Circle's area is greater than the Square's area" << endl;
    }
    if (c < s)
    {
        cout << "The Square's area is greater than the Circle's area" << endl;
    }
    if (s > r)
    {
        cout << "The Square's area is greater than the Rectangle's area" << endl;
    }
    if (s < r)
    {
        cout << "The Rectangle's area is greater than the Square's area" << endl;
    }
}