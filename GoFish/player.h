/*********************************************************************
** Program Filename: player.h
** Author: Katie Blickenstaff
** Date: 7/19/2020
** Description: Player class header and declarations
*********************************************************************/
#ifndef PLAYER_H
#define PLAYER_H

#include "hand.h"

#include <iostream>

using namespace std;

class Player
{

private:
    Hand hand;
    int *books;
    int n_books;

public:
    Player();  //Constructor
    ~Player(); //Destructor

    // void check_books();
    //Search for stuff
    void find_book();
    int find_match(int);
    bool check_hand(int);

    //Mutators
    Card take_card(int, int);
    void add_card_to_hand(Card card_add);
    void add_rank_to_book(int rank);
    void remove(int, int);

    //Computer makes a choice
    int get_comp_choice();

    //Getters
    int get_n_cards();
    int get_n_books();

    //Printing
    void print_books();
    void show_hand();
    void string_in_book(int);
};

#endif