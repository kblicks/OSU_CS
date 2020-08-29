#ifndef CARD_H
#define CARD_H

#include <iostream>

using namespace std;

class Card
{
private:
    int rank;
    int suit;

public:
    Card(); //Constructor

    void set_rank(int);
    int get_rank();
    void set_suit(int);
    int get_suit();
    string map_suit();
    string map_rank();
    void print_card();
};

#endif