#include <iostream>
#include "p_classes.h"

int main(int argc, char *argv[])
{
    Card c1;
    cout << "call deck" << endl;
    Deck d;

    c1.print_card();
    d.print_deck();
    cout << "Concludes main" << endl;
}