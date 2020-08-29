#ifndef P_CLASSES_H
#define P_CLASSES_H

#include <iostream>

using namespace std;

class Card
{
private:
    int rank;
    int suit;

public:
    Card(); //Constructor
    void set_rank(int);
    int get_rank();
    void set_suit(int);
    int get_suit();
    string map_suit();
    string map_rank();
    void print_card();
};

class Deck
{

private:
    Card cards[52];
    int n_cards;

public:
    Deck(); //Constructor
    //~Deck(); //Destructor
    void shuffle();
    int select_Card();
    void print_deck();
};

#endif