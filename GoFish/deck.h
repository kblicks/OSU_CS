/*********************************************************************
** Program Filename: deck.h
** Author: Katie Blickenstaff
** Date: 7/19/2020
** Description: Deck class header and declarations
*********************************************************************/
#ifndef DECK_H
#define DECK_H

#include "card.h"

#include <iostream>

using namespace std;

class Deck
{

private:
    Card cards[52];
    int n_cards;

public:
    Deck(); //Constructor
        //No need for big three because dynamic array isn't being used

    //Shuffle
    void shuffle();
    //Draw a card
    Card draw_card();
    //Getter
    int get_n_cards();
    //Print the whole deck
    void print_deck();
    //Changes rank's data type
    int get_int_rank(string);
    string get_int_string(int);
};

#endif