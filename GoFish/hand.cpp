/*********************************************************************
** Program Filename: hand.cpp
** Author: Katie Blickenstaff
** Date: 7/19/2020
** Description: Hand class functions
*********************************************************************/

#include <iostream>
#include <string>
#include <map>
#include <stdlib.h>
#include <time.h>

#include "deck.h"
#include "card.h"
#include "hand.h"

using namespace std;

/*********************************************************************
** Function: Hand
** Description: Default constructor of hand
** Parameters: none
** Pre-Conditions: Values not assigned to private member variables
** Post-Conditions: Initializes and assigns values to private member variables
*********************************************************************/
Hand::Hand()
{
    //cout << "Default hand called" << endl;
    this->n_cards = 0;
    this->cards = NULL;
}

/*********************************************************************
** Function: Hand
** Description: Copy constructor for Hand
** Parameters: old hand object
** Pre-Conditions:  No copy made
** Post-Conditions: Created new object and initialized it with values of original
*********************************************************************/
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
/*********************************************************************
** Function: Hand Operator
** Description: Assignment overload operator
** Parameters: reference to old hand obj
** Pre-Conditions: No operator overloaded
** Post-Conditions: Overloaded operator and assigned it values of original
*********************************************************************/
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

/*********************************************************************
** Function: ~Hand
** Description: Destructor for Hand 
** Parameters: none
** Pre-Conditions: Array is full of elements
** Post-Conditions: Deletes elements in array and sets it back to NULL
*********************************************************************/
Hand::~Hand()
{
    //cout << "Hand Destructor called" << endl;
    if (this->cards != NULL)
    {
        delete[] this->cards;
        this->cards = NULL;
    }
}
/*********************************************************************
** Function: add_card
** Description: Add a card to hand after it's been drawn
** Parameters: Card drawn
** Pre-Conditions: Hand has X amount of cards
** Post-Conditions: Hand now has X+1 amount of cards
*********************************************************************/
void Hand::add_card(Card drawn)
{
    //create temp array
    Card *temp = new Card[n_cards + 1];

    for (int i = 0; i < this->n_cards; ++i)
    {
        temp[i] = this->cards[i];
    }

    //add our drawn card
    temp[this->n_cards] = drawn;

    //Delete the array

    if (this->cards != NULL)
    {
        delete[] this->cards;
    }

    //assign temp array to pointer
    this->cards = temp;
    //increment number of cards in hand
    this->n_cards++;
}

/*********************************************************************
** Function: take_card
** Description: Grabs the location of specified card from other player's hand to steal it
** Parameters: int int
** Pre-Conditions: Unknown location of card
** Post-Conditions: returns a card
*********************************************************************/
Card Hand::take_card(int rank, int suit)
{
    for (int i = 0; i < n_cards; i++)
    {
        if (cards[i].get_rank() == rank && cards[i].get_suit() == suit)
        {
            return cards[i];
        }
    }
}

/*********************************************************************
** Function: remove_card
** Description: Removes the specified card from the hand
** Parameters: int int
** Pre-Conditions: Hand has X amount of cards
** Post-Conditions: Hand now has x-1 amount of cards
*********************************************************************/
void Hand::remove_card(int rank, int suit)
{
    int rankx = -1;
    int suitx = -1;
    for (int i = 0; i < this->n_cards; ++i)
    {
        if (this->cards[i].get_rank() == rank && this->cards[i].get_suit() == suit)
        {
            rankx = i;
            suitx = i;
            break;
        }
    }
    //2. if not found, return
    if (rankx == -1)
    {
        return;
    }
    else if (suitx == -1)
    {
        return;
    }

    //3. loop from rankx value to the end of the std array, shift them to the left by 1
    for (int i = rankx; i < this->n_cards - 1; ++i)
    {
        this->cards[i] = this->cards[i + 1];
    }

    //4. decrement the cards in hand
    this->n_cards--;
}

/*********************************************************************
** Function: create_book
** Description: Checks to see if there are enough ranks in the hand to create a book and returns the rank is so
** Parameters: none
** Pre-Conditions: Book does not contain specific rank
** Post-Conditions: returns a rank
*********************************************************************/
int Hand::create_book()
{
    int check_rank;
    for (int i = 0; i < n_cards; i++)
    {
        check_rank = cards[i].get_rank();
        int count = 0;
        for (int j = 0; j < n_cards; j++)
        {
            if (check_rank == cards[j].get_rank())
            {
                count++;
            }
            if (count == 4)
            {
                cout << "Created a book" << endl;
                return check_rank;
            }
        }
    }
    return -1;
}

/*********************************************************************
** Function: rank_in_hand
** Description: Checks to see if rank being asked for is in hand
** Parameters: int
** Pre-Conditions: unkown if rank is in hand
** Post-Conditions: confirms if rank is in hand or not
*********************************************************************/
bool Hand::rank_in_hand(int rank)
{
    for (int i = 0; i < n_cards; i++)
    {
        if (this->cards[i].get_rank() == rank)
        {
            return true;
        }
    }
    cout << "This rank is not in your hand, please choose one that is" << endl;
    return false;
}

/*********************************************************************
** Function: match_suit
** Description: Search to see if rank is in the other player's hand
** Parameters: int
** Pre-Conditions: Unknown if rank is in other hand
** Post-Conditions: Confirms if rank is in other hand and returns corresponding suit if so
*********************************************************************/
int Hand::match_suit(int rank)
{
    for (int i = 0; i < this->n_cards; i++)
    {
        if (this->cards[i].get_rank() == rank)
        {

            return cards[i].get_suit();
        }
    }
    return -1;
}
/*********************************************************************
** Function: computer_choice
** Description: Search through the ranks in the computer's hand and randomize pick
** Parameters: none
** Pre-Conditions: Computer hasn't picked a rank to ask for
** Post-Conditions: Computer picks rank to ask for
*********************************************************************/
int Hand::computer_choice()
{
    //initialize array and fill with ranks
    int ranks[n_cards];
    for (int i = 0; i < n_cards; i++)
    {
        ranks[i] = cards[i].get_rank();
    }

    srand(time(NULL)); //initialize random seed

    int rand_rank = rand() % n_cards; //generates a random number between 0 and n_cards
    return ranks[rand_rank];          //return the random rank choice
}

/*********************************************************************
** Function: swap
** Description: helper function to swap elements locations
** Parameters: Card* Card*
** Pre-Conditions: Element X : Element Y
** Post-Conditions: Element Y: Element X
*********************************************************************/
void Hand::swap(Card *xp, Card *yp)
{
    Card temp = *xp;
    *xp = *yp;
    *yp = temp;
}
/*********************************************************************
** Function: sort_by_rank
** Description: Sorts the cards by rank
** Parameters: none
** Pre-Conditions: Cards are unsorted
** Post-Conditions: Cards in hand are sorted by rank
*********************************************************************/
void Hand::sort_by_rank()
{
    bool swapped;
    for (int i = 0; i < n_cards - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < n_cards - i - 1; j++)
        {
            if (cards[j].get_rank() > cards[j + 1].get_rank())
            {
                swap(&cards[j], &cards[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
        {
            break;
        }
    }
}

/*********************************************************************
** Function: get_n_cards
** Description: Getter to return n_cards
** Parameters: none
** Pre-Conditions: n_cards is set
** Post-Conditions: n_cards is gotten
*********************************************************************/
int Hand::get_n_cards()
{

    return this->n_cards;
}

/*********************************************************************
** Function: display_hand
** Description: prints out the hands sorted by rank
** Parameters: none
** Pre-Conditions: Hand is not displayed
** Post-Conditions: Hand is printed
*********************************************************************/
void Hand::display_hand()
{
    //Sorted by rank
    sort_by_rank();

    for (int i = 0; i < n_cards; i++)
    {
        cards[i].print_card();
    }
}