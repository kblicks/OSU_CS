/*********************************************************************
** Program Filename: game.h
** Author: Katie Blickenstaff
** Date: 7/19/2020
** Description: Game class header and declarations
*********************************************************************/
#ifndef GAME_H
#define GAME_H

#include "deck.h"
#include "player.h"

#include <iostream>

using namespace std;

class Game
{

private:
    Deck cards;
    Player players[2];

public:
    Game(); //Default Game constructor
    //No need for big three because dynamic array isn't being used

    //Deal cards
    void deal_cards();

    //Turn functions
    void player_turn();
    void computer_turn();

    //Print functions for each mode
    void print_normal_mode();
    void print_cheat_mode();
    //Checks status of game and hands
    bool check_game_over();
    bool check_hands();

    //Ask user if they want to play again
    bool play_again();

    int check_int_input();
};

#endif