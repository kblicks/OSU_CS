/*********************************************************************
** Program Filename: card.cpp
** Author: Katie Blickenstaff
** Date: 7/19/2020
** Description: Card class functions
*********************************************************************/

#include <iostream>
#include <string>
#include <map>
#include <stdlib.h>
#include <time.h>

#include "card.h"
#include "deck.h"

using namespace std;

/*********************************************************************
** Function: Card
** Description: Default constructor for card
** Parameters: none
** Pre-Conditions: Private member variables don't have values
** Post-Conditions: Assigned values to private member variables
*********************************************************************/
Card::Card()
{
    this->rank = 0,
    this->suit = 0;
}

/*********************************************************************
** Function: set_rank
** Description: Function to set rank
** Parameters: int
** Pre-Conditions: rank not set
** Post-Conditions: rank set
*********************************************************************/
void Card::set_rank(int rank)
{
    this->rank = rank;
}
/*********************************************************************
** Function: get_rank
** Description: Getter function to return rank
** Parameters: none
*********************************************************************/
int Card::get_rank()
{
    return this->rank;
}
/*********************************************************************
** Function: set_suit
** Description: Function to set suit
** Parameters: int
** Pre-Conditions: suit not set
** Post-Conditions: suit set
*********************************************************************/
void Card::set_suit(int suit)
{
    this->suit = suit;
}
/*********************************************************************
** Function: get_suit
** Description: Getter function to return suit
** Parameters: none
*********************************************************************/
int Card::get_suit()
{
    return this->suit;
}
/*********************************************************************
** Function: map_suit
** Description: Maps suit from int to string
** Parameters: none
** Pre-Conditions: suit is an int
** Post-Conditions: suit is a string
*********************************************************************/
string Card::map_suit()
{
    map<int, string> mapsuit;
    mapsuit[0] = "Spades";
    mapsuit[1] = "Clubs";
    mapsuit[2] = "Hearts";
    mapsuit[3] = "Diamonds";
    return mapsuit[suit];
}
/*********************************************************************
** Function: map_rank
** Description: Maps rank from int to string
** Parameters: none
** Pre-Conditions: rank is an int
** Post-Conditions: rank is a string
*********************************************************************/
string Card::map_rank()
{
    map<int, string> maprank;
    maprank[0] = "King";
    maprank[1] = "Ace";
    maprank[2] = "Two";
    maprank[3] = "Three";
    maprank[4] = "Four";
    maprank[5] = "Five";
    maprank[6] = "Six";
    maprank[7] = "Seven";
    maprank[8] = "Eight";
    maprank[9] = "Nine";
    maprank[10] = "Ten";
    maprank[11] = "Jack";
    maprank[12] = "Queen";
    return maprank[rank];
}
/*********************************************************************
** Function: print_card
** Description: Prints the card out
** Parameters: none
** Pre-Conditions: Card is not displayed
** Post-Conditions: Card is displayed
*********************************************************************/
void Card::print_card()
{
    cout << this->map_rank() << " of " << this->map_suit() << endl;
}
