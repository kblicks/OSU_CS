#include <iostream>
#include <string>
#include <map>
#include "p_classes.h"

using namespace std;

//default constructor for Card

Card::Card()
{
    cout << "Default constructor being called" << endl;
    this->rank = 0,
    this->suit = 0;
}

//Initialize the deck
Deck::Deck()
{
    n_cards = 52;
    cards[0] = cards[0].rank.suit;
}

void Card::set_rank(int rank)
{
    this->rank = rank;
}
int Card::get_rank()
{
    return this->rank;
}

void Card::set_suit(int suit)
{
    this->suit = suit;
}
int Card::get_suit()
{
    return this->suit;
}

string Card::map_suit()
{
    map<int, string> mapsuit;
    mapsuit[0] = "Spades";
    mapsuit[1] = "Clubs";
    mapsuit[2] = "Hearts";
    mapsuit[3] = "Diamonds";
    return mapsuit[suit];
}

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

void Card::print_card()
{
    cout << this->map_rank() << " of " << this->map_suit() << endl;
}

void Deck::print_deck()
{
    for (int i = 0; i < this->n_cards; ++i)
    {
        cards[i].print_card();
    }
}
