#include <iostream>

#include "card.h"
#include "hand.h"

using namespace std;

int main(int argc, char *argv[])
{
    //Default constructor
    Hand h1, h2;
    h1 = h2;

    Hand h3 = h1;

    cout << "End main" << endl;
}