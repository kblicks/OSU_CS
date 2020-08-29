#include <iostream>

#include "card.h"
#include "hand.h"
using namespace std;

//Default constructor of Hand
Hand::Hand()
{
    cout << "Default hand called" << endl;

    this->n_cards = 0;
    this->cards = NULL;
}

//Copy constructor
Hand::Hand(const Hand &old_obj)
{
    cout << "Copy constructor called" << endl;
    this->n_cards = old_obj.n_cards;

    this->cards = new Card[this->n_cards];
    for (int i = 0; i < this->n_cards; ++i)
    {
        this->cards[i] = old_obj.cards[i];
    }
}

//Assignment operator overload
Hand &Hand::operator=(const Hand &old_obj)
{
    cout << "Assignment operator overload of Hand called" << endl;
    if (this != &old_obj)
    {
        this->n_cards = old_obj.n_cards;

        if (this->cards != NULL)
            delete[] this->cards;
        this->cards = new Card[this->n_cards];
        for (int i = 0; i < this->n_cards; ++i)
            this->cards[i] = old_obj.cards[i];
    }
    return *this;
}

//Destructor
Hand::~Hand()
{
    cout << "Hand Destructor called" << endl;
    if (this->cards != NULL)
    {
        delete[] this->cards;
        this->cards = NULL;
    }
}