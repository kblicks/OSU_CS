/*********************************************************************
** Program Filename: deck.cpp
** Author: Katie Blickenstaff
** Date: 7/19/2020
** Description: Deck class functions
*********************************************************************/

#include <iostream>
#include <string>
#include <map>
#include <stdlib.h>
#include <time.h>
#include <bits/stdc++.h>

#include "deck.h"
#include "card.h"

using namespace std;

/*********************************************************************
** Function: Deck
** Description: Default constructor for the Deck
** Parameters: none
** Pre-Conditions: Private member variables don't have values and deck is not filled with cards
** Post-Conditions: Set n_cards to 52 and filled deck with cards
*********************************************************************/
Deck::Deck()
{
    //cout << "Default Deck constructor called" << endl;
    n_cards = 52;

    for (int i = 0; i < n_cards; i += 13)
    {
        for (int s = 0; s < 4; s++)
        {
            for (int r = 0; r < 13; r++)
            {
                cards[i].set_rank(r);
                cards[i].set_suit(s);

                i++;
            }
        }
    }
}
/*********************************************************************
** Function: shuffle
** Description: Randomly shuffles the deck
** Parameters: none
** Pre-Conditions: Deck is ordered
** Post-Conditions: Deck is randomized
*********************************************************************/
void Deck::shuffle()
{
    for (int i = 0; i < 52; i++)
    {
        int second = (rand() + time(0)) % 52;
        Card temp = cards[i];

        cards[i] = cards[second];

        cards[second] = temp;
    }
}
/*********************************************************************
** Function: draw_card
** Description: Draws a card from the top of the deck and hides that card
** Parameters: none
** Pre-Conditions: Top card is on deck
** Post-Conditions: Deck is -1 card and card is returned to hand
*********************************************************************/
Card Deck::draw_card()
{
    n_cards -= 1;
    return cards[n_cards];
}

/*********************************************************************
** Function: get_n_cards
** Description: Getter function to return number of cards in deck
** Parameters: none
*********************************************************************/
int Deck::get_n_cards()
{
    return this->n_cards;
}
/*********************************************************************
** Function: print_deck
** Description: Prints the whole deck
** Parameters: none
*********************************************************************/
void Deck::print_deck()
{

    for (int i = 0; i < this->n_cards; ++i)
    {
        cards[i].print_card();
    }
}

/*********************************************************************
** Function: get_int_rank
** Description: Converts the users string rank to int and returns rank as int
** Parameters: string
** Pre-Conditions: ask is a string
** Post-Conditions: rank is int
*********************************************************************/
int Deck::get_int_rank(string ask)
{
    transform(ask.begin(), ask.end(), ask.begin(), ::toupper);
    int rank;

    if (ask == "ACE")
    {
        rank = 1;
    }
    else if (ask == "TWO")
    {
        rank = 2;
    }
    else if (ask == "THREE")
    {
        rank = 3;
    }
    else if (ask == "FOUR")
    {
        rank = 4;
    }
    else if (ask == "FIVE")
    {
        rank = 5;
    }
    else if (ask == "SIX")
    {
        rank = 6;
    }
    else if (ask == "SEVEN")
    {
        rank = 7;
    }
    else if (ask == "EIGHT")
    {
        rank = 8;
    }
    else if (ask == "NINE")
    {
        rank = 9;
    }
    else if (ask == "TEN")
    {
        rank = 10;
    }
    else if (ask == "JACK")
    {
        rank = 11;
    }
    else if (ask == "QUEEN")
    {
        rank = 12;
    }
    else if (ask == "KING")
    {
        rank = 0;
    }
    else
    {
        cout << "Sorry but that isn't a valid input. Please try again" << endl;
        rank = -1;
    }
    cin.clear();
    cin.ignore(256, '\n');
    return rank;
}
/*********************************************************************
** Function: get_int_string
** Description: Gets the rank from computer and converts it to string
** Parameters: int
** Pre-Conditions: accepts rank as int
** Post-Conditions: returns string
*********************************************************************/
string Deck::get_int_string(int rank)
{

    string ask;
    switch (rank)
    {
    case 0:
        ask = "KING";
        break;
    case 1:
        ask = "ACE";
        break;
    case 2:
        ask = "TWO";
        break;
    case 3:
        ask = "THREE";
        break;
    case 4:
        ask = "FOUR";
        break;
    case 5:
        ask = "FIVE";
        break;
    case 6:
        ask = "SIX";
        break;
    case 7:
        ask = "SEVEN";
        break;
    case 8:
        ask = "EIGHT";
        break;
    case 9:
        ask = "NINE";
        break;
    case 10:
        ask = "TEN";
        break;
    case 11:
        ask = "JACK";
        break;
    case 12:
        ask = "QUEEN";
        break;
    }
    return ask;
}
