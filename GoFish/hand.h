/*********************************************************************
** Program Filename: hand.h
** Author: Katie Blickenstaff
** Date: 7/19/2020
** Description: Hand class header and declarations
*********************************************************************/
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
    Hand();                        //Default constructor
    Hand(const Hand &);            //Copy constructor
    Hand &operator=(const Hand &); //Assignment overload operator
    ~Hand();                       //Destructor

    //Mutators
    void add_card(Card);
    Card take_card(int, int);
    void remove_card(int, int);
    int create_book();

    //Finds match
    bool rank_in_hand(int);
    int match_suit(int);
    //Returns the computer's choice
    int computer_choice();

    //Sort functions
    void swap(Card *, Card *);
    void sort_by_rank();

    //Getters
    int get_n_cards();

    //Prints the hand
    void display_hand();
};

#endif