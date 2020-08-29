#ifndef HAND_H
#define HAND_H

#include "card.h"
#include <iostream>

using namespace std;

class Hand
{

private:
    Card *cards;

    int n_cards; //Number of cards in the hand

public:
    Hand();
    Hand(const Hand &);
    Hand &operator=(const Hand &);
    ~Hand();
    void get_card(Card);
    void add_card(Card);
    void remove_card(int, int);
    void display_hand();
};

#endif