/*********************************************************************
** Program Filename: card.h
** Author: Katie Blickenstaff
** Date: 7/19/2020
** Description: Card class header and declarations
*********************************************************************/
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
    //No need for big three because dynamic array isn't being used

    //Setters and Getters
    void set_rank(int);
    int get_rank();
    void set_suit(int);
    int get_suit();
    //Mapping functions (mutators)
    string map_suit();
    string map_rank();
    //Print a card
    void print_card();
};

#endif