/*********************************************************************
** Program Filename: game.cpp
** Author: Katie Blickenstaff
** Date: 7/19/2020
** Description: Game class functions
*********************************************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "deck.h"
#include "player.h"
#include "hand.h"
#include "card.h"
#include "game.h"
using namespace std;

/*********************************************************************
** Function: Game
** Description: This is the default constructor for the Game class. Sets up the game by shuffling and dealing the cards
** Parameters: none
** Pre-Conditions:  The deck is not shuffled and each player has 0 cards in hand
** Post-Conditions: The deck is shuffled and each player has 7 cards in hand
*********************************************************************/
Game::Game()
{
    //cout << "Default game constructor called" << endl;
    cards.shuffle();
    cout << endl;
    deal_cards();
}

/*********************************************************************
** Function: deal_cards
** Description: function to alternate giving cards to each hand 7 times
** Parameters: none
** Pre-Conditions: Each player's hand is empty
** Post-Conditions: Each player ends up with 7 cards in their hand
*********************************************************************/
void Game::deal_cards()
{
    //Deal 7 cards at the start
    for (int i = 0; i < 7; i++)
    {
        this->players[0].add_card_to_hand(cards.draw_card());
        for (int j = 0; j < 1; j++)
        {
            this->players[1].add_card_to_hand(cards.draw_card());
        }
    }
}

/*********************************************************************
** Function: player_turn
** Description: Starts the human players turn and ends when they get a card that doesn't match their request
** Parameters: none
** Pre-Conditions: Player's previous hand is un-altered
** Post-Conditions: Alters player's hand by gaining a card and possibly creating a book
*********************************************************************/
void Game::player_turn()
{
    bool turnover = false;

    int rank, suit;
    string ask;

    while (turnover == false)
    {

        bool present = false;
        while (present == false)
        {
            rank = -1;

            while (rank == -1)
            {
                if (this->players[0].get_n_cards() == 0)
                {
                    if (cards.get_n_cards() != 0)
                    {
                        cout << "Your hand has 0 cards, drawing a card now" << endl;
                        this->players[0].add_card_to_hand(cards.draw_card());
                        //show hand here
                        this->players[0].show_hand();
                    }
                }

                cout << "what rank would you like to ask for?" << endl;
                cin >> ask;
                rank = this->cards.get_int_rank(ask);
            }
            present = this->players[0].check_hand(rank);
        }
        Card stolen;
        suit = this->players[1].find_match(rank);

        if (suit == -1)
        {

            cout << "//\\ Go FISH! //\\" << endl;
            Card draw = cards.draw_card();
            cout << "You drew a ";
            draw.print_card();
            cout << endl;
            this->players[0].add_card_to_hand(draw);
            //Check current hand to see if a book can be created
            this->players[0].find_book();

            //Draw and go again if drawn card matches requested rank
            if (rank == draw.get_rank())
            {
                cout << "You drew a card that matches the rank you asked for, go again" << endl;
                turnover = false;
            }
            else
            {
                turnover = true;
            }
        }
        else
        {
            while (suit != -1)
            {
                stolen = this->players[1].take_card(rank, suit);
                cout << "________________________________" << endl;
                cout << "You took their ";
                stolen.print_card();
                cout << "________________________________" << endl;
                this->players[0].add_card_to_hand(stolen);
                this->players[1].remove(rank, suit);
                suit = this->players[1].find_match(rank);
            }
            //Check current hand to see if a book can be created
            this->players[0].find_book();
            //Check if both players are out of cards
            turnover = check_hands();
        }
    }
}
/*********************************************************************
** Function: computer_turn
** Description: Starts the computer players turn
** Parameters:  none
** Pre-Conditions:  Computer hand is un-altered from last turn
** Post-Conditions: Alters computer's hand by gaining a card and possibly creating a book
*********************************************************************/
void Game::computer_turn()
{
    bool turnover = false;
    int rank, suit;
    string ask;

    while (turnover == false)
    {

        if (this->players[1].get_n_cards() == 0)
        {
            if (cards.get_n_cards() != 0)
            {
                cout << "Computer drew a card because their hand was empty" << endl;
                this->players[1].add_card_to_hand(cards.draw_card());
            }
        }
        rank = players[1].get_comp_choice();
        ask = this->cards.get_int_string(rank);
        cout << "***********************************" << endl;

        cout << "The computer asks for " << ask << "'s" << endl;

        Card stolen;
        suit = this->players[0].find_match(rank);

        if (suit == -1)
        {
            cout << "//\\ You say: Go FISH! //\\" << endl;
            cout << "***********************************" << endl;
            Card draw = cards.draw_card();
            this->players[1].add_card_to_hand(draw);
            //Check current hand to see if a book can be created
            this->players[1].find_book();

            //Draw and go again if drawn card matches requested rank

            if (rank == draw.get_rank())
            {
                cout << "Computer drew a card that matches the rank they asked for, go again" << endl;
                turnover = false;
            }
            else
            {
                turnover = true;
            }
        }
        else
        {
            while (suit != -1)
            {

                stolen = this->players[0].take_card(rank, suit);
                cout << "Computer took your ";
                stolen.print_card();
                this->players[1].add_card_to_hand(stolen);
                this->players[0].remove(rank, suit);
                suit = this->players[0].find_match(rank);
            }
            this->players[1].find_book();
            //Check if both players are out of cards
            turnover = check_hands();
        }
    }
}
/*********************************************************************
** Function: print_normal_mode
** Description: Prints the state of the game under normal mode conditions
** Parameters: none
** Pre-Conditions: Current state of game is not updated
** Post-Conditions: Updates and prints current state of game
*********************************************************************/
void Game::print_normal_mode()
{
    cout << endl;
    cout << "    Current state of the game" << endl;
    cout << "____________________________________________" << endl;

    cout << "There are: " << cards.get_n_cards() << " cards left in the deck" << endl;
    cout << endl;
    cout << "The computer hand has: " << this->players[1].get_n_cards() << " cards" << endl;
    cout << this->players[1].get_n_books() << " Created Books" << endl;
    cout << endl;
    cout << "The human hand has: " << this->players[0].get_n_cards() << " cards" << endl;
    cout << this->players[0].get_n_books() << " Created Books" << endl;
    cout << endl;
    cout << "Your hand is: " << endl;
    cout << "------------------------" << endl;
    this->players[0].show_hand();
    cout << "------------------------" << endl;
    cout << "____________________________________________" << endl;

    cout << endl;
}

/*********************************************************************
** Function: print_cheat_mode
** Description: Prints the state of the game under debug mode conditions
** Parameters: none
** Pre-Conditions: Current state of game is not updated
** Post-Conditions: Updates and prints current state of game
*********************************************************************/
//Cheat mode
void Game::print_cheat_mode()
{
    cout << endl;
    cout << "    Current state of the game" << endl;
    cout << "____________________________________________" << endl;
    cout << "There are: " << cards.get_n_cards() << " cards left in the deck" << endl;
    cout << endl;
    cout << "The computer hand has: " << this->players[1].get_n_cards() << " cards" << endl;
    cout << this->players[1].get_n_books() << " Created Books. Their books are: " << endl;
    this->players[1].print_books();
    cout << endl;
    cout << endl;
    cout << "The human hand has: " << this->players[0].get_n_cards() << " cards" << endl;
    cout << this->players[0].get_n_books() << " Created Books. Your books are: " << endl;
    this->players[0].print_books();
    cout << endl;
    cout << endl;
    cout << "The computer hand is: " << endl;
    cout << "------------------------" << endl;
    this->players[1].show_hand();
    cout << "------------------------" << endl;
    cout << endl;
    cout << "Your hand is: " << endl;
    cout << "------------------------" << endl;
    this->players[0].show_hand();
    cout << "------------------------" << endl;
    cout << "____________________________________________" << endl;
    cout << endl;
}
/*********************************************************************
** Function: check_game_over
** Description: Checks to see if game is over by getting the number of cards held in each player's hands. When each player has 0 cards, game is over
** Parameters: none
** Pre-Conditions: Game is not over
** Post-Conditions: Returns if game is over or not
*********************************************************************/
bool Game::check_game_over()
{
    int comp_cards, hum_cards;
    hum_cards = this->players[0].get_n_cards();
    comp_cards = this->players[1].get_n_cards();

    if (hum_cards == 0 && comp_cards == 0)
    {
        cout << endl;
        cout << endl;
        cout << "Both players are out of cards, the game is over" << endl;
        cout << "Here are the scores: " << endl;
        cout << "_______________________________________" << endl;
        cout << "You created: " << this->players[0].get_n_books() << " books. Your books are: " << endl;
        this->players[0].print_books();
        cout << "\n_______________________________________" << endl;
        cout << "The computer created: " << this->players[1].get_n_books() << " books. Their books are: " << endl;
        this->players[1].print_books();
        cout << "\n_______________________________________" << endl;
        if (this->players[0].get_n_books() > this->players[1].get_n_books())
        {
            cout << "YOU WIN!" << endl;
        }
        else
        {
            cout << "YOU LOSE!" << endl;
        }
        return true;
    }
    else
    {
        return false;
    }
}

/*********************************************************************
** Function: check_hands
** Description: Check to see if both hands are empty and if so, ends current player's turn
** Parameters: none
** Pre-Conditions: Number of cards in hand are unknown
** Post-Conditions: Returns true if hands are empty
*********************************************************************/
bool Game::check_hands()
{
    int comp_cards, hum_cards;
    hum_cards = this->players[0].get_n_cards();
    comp_cards = this->players[1].get_n_cards();

    if (hum_cards == 0 && comp_cards == 0)
    {
        return true;
    }
    return false;
}

bool Game::play_again()
{
    bool again;
    int choice = 0;
    while (choice != 1 || choice != 2)
    {
        cout << "Would you like to play again? (1-yes, 2-no)" << endl;
        int choice = check_int_input();

        if (choice == 1)
        {
            cout << "Resetting the game" << endl;
            return true;
        }
        else if (choice == 2)
        {
            cout << "Thank you for playing" << endl;
            return false;
        }
        else
        {
            cout << "That's not an option, please select again" << endl;
        }
    }
}
/*********************************************************************
** Function: check_int_input
** Description: Used to make sure rank input is valid
** Parameters: none
** Pre-Conditions: Input needs to be given
** Post-Conditions: Returns an input
*********************************************************************/
int Game::check_int_input()
{
    cin.clear();
    string input_str;
    int input;
    getline(cin, input_str);

    while (cin.fail() || cin.eof() || input_str.find_first_not_of("0123456789") != string::npos)
    {
        if (input_str.find_first_not_of("0123456789") == string::npos)
        {
            cin.clear();
            cin.ignore(256, '\n');
        }

        cout << " Re-Enter a valid " << endl;
        getline(cin, input_str);
    }

    input = atoi(input_str.c_str());
    return input;
}