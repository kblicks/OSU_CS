/*********************************************************************
** Program Filename: go_fish.cpp
** Author: Katie Blickenstaff
** Date: 7/19/2020
** Description: This file holds the main function for running the program
** Input: Command line argument with 2 arguments
** Output: Runs the game
*********************************************************************/

#include <iostream>
#include <stdlib.h>

#include "card.h"
#include "deck.h"
#include "hand.h"
#include "player.h"
#include "game.h"

int main(int argc, char *argv[])
{
    //Exits program if there aren't two arguments
    if (argc != 2)
    {
        cout << "Two arguments not detected" << endl;
        exit(EXIT_FAILURE);
    }

    bool again = true;
    string input = argv[1];

    //run the program normally
    if (input == "false")
    {
        cout << "Running game in normal mode" << endl;
        while (again == true)
        {
            bool gameover = false;
            Game gg;

            int turn = 0;
            while (gameover == false)
            {
                if (turn == 0)
                {
                    gg.print_normal_mode();
                    gg.player_turn();
                    turn = 1;
                    gameover = gg.check_game_over();
                }
                else if (turn == 1)
                {
                    gg.computer_turn();
                    turn = 0;
                    gameover = gg.check_game_over();
                }
            }
            again = gg.play_again();
        }
    }
    //Run the program in debug mode
    else if (input == "true")
    {
        cout << "Running game in debug mode" << endl;
        while (again == true)
        {
            bool gameover = false;
            Game gg;

            int turn = 0;
            while (gameover == false)
            {
                if (turn == 0)
                {
                    gg.print_cheat_mode();
                    gg.player_turn();
                    turn = 1;
                    gameover = gg.check_game_over();
                }
                else if (turn == 1)
                {
                    gg.computer_turn();
                    turn = 0;
                    gameover = gg.check_game_over();
                }
            }
            again = gg.play_again();
        }
    }
    else
    {
        cout << "Please enter either true or false in lowercase" << endl;
    }
}