/*********************************************************************
** Program Filename: player.cpp
** Author: Katie Blickenstaff
** Date: 7/19/2020
** Description: File that hosts the Player class functions
*********************************************************************/

#include <iostream>

#include "player.h"
#include "hand.h"
#include "card.h"

using namespace std;

/*********************************************************************
** Function: Player
** Description: Default constructor
** Parameters: none
** Pre-Conditions: Private members don't have values
** Post-Conditions: Private members get values
*********************************************************************/
Player::Player()
{
    //cout << "Player constructor called" << endl;
    this->n_books = 0;
    this->books = NULL;
}
/*********************************************************************
** Function: ~Player
** Description: Destructor for player class
** Parameters: none
** Pre-Conditions: books array is filled
** Post-Conditions: books array is deleted and set to NULL
*********************************************************************/
Player::~Player()
{
    //cout << "Player Destructor called" << endl;
    if (this->books != NULL)
    {
        delete[] this->books;
        this->books = NULL;
    }
}
/*********************************************************************
** Function: find_book
** Description: If a book can be created, takes rank and adds it to the book. Then deletes the matching cards from current hand
** Parameters: none
** Pre-Conditions: Books array is X. Hand array is Y
** Post-Conditions: Books array is X+1. Hand array is Y -4
*********************************************************************/
void Player::find_book()
{
    int add_rank = this->hand.create_book();

    if (add_rank != -1)
    {
        add_rank_to_book(add_rank);

        for (int i = 0; i < 4; i++)
        {
            int suit = find_match(add_rank);
            remove(add_rank, suit);
        }
    }
}

/*********************************************************************
** Function: find_match
** Description: Access match_suit function in Hand to pair a rank and suit then returns matchin suit
** Parameters: int
** Pre-Conditions: Suit is unknown
** Post-Conditions: Returns a suit
*********************************************************************/
int Player::find_match(int rank)
{
    int suit;

    suit = this->hand.match_suit(rank);
    return suit;
}

/*********************************************************************
** Function: check_hand
** Description: Accesses Hand function to see if rank is in current hand
** Parameters: int
** Pre-Conditions: Takes in asked for rank 
** Post-Conditions: Returns status of rank being in hand or not
*********************************************************************/
bool Player::check_hand(int rank)
{
    bool exists = this->hand.rank_in_hand(rank);
    return exists;
}

/*********************************************************************
** Function: take_card
** Description: Returns the card taken from other player's hand
** Parameters: int int
** Pre-Conditions: Don't have a card to steal
** Post-Conditions: returns a card
*********************************************************************/
Card Player::take_card(int rank, int suit)
{
    Card card = this->hand.take_card(rank, suit);
    return card;
}

/*********************************************************************
** Function: add_card_to_hand
** Description: Passes in card to add to hand
** Parameters: Card
** Pre-Conditions: Card hasn't been added 
** Post-Conditions: Card is added to hand
*********************************************************************/
void Player::add_card_to_hand(Card card_add)
{
    this->hand.add_card(card_add);
}

/*********************************************************************
** Function: add_rank_to_book
** Description: Add rank to book and increase the array size
** Parameters: int
** Pre-Conditions: Book has X elements in array 
** Post-Conditions: Book has X+1 elements in array 
*********************************************************************/
void Player::add_rank_to_book(int add_rank)
{
    //create temp array
    int *temp = new int[n_books + 1];

    for (int i = 0; i < this->n_books; ++i)
    {
        temp[i] = this->books[i];
    }

    //add our drawn card
    temp[this->n_books] = add_rank;

    //Delete the array

    if (this->books != NULL)
    {
        delete[] this->books;
    }

    //assign temp array to pointer
    this->books = temp;
    //increment number of cards in hand
    this->n_books++;
}

/*********************************************************************
** Function: remove
** Description: Accesses the remove_card function in Hand
** Parameters: int int
** Pre-Conditions: Hand has X cards
** Post-Conditions: Hand has X-1 cards
*********************************************************************/
void Player::remove(int rank, int suit)
{
    this->hand.remove_card(rank, suit);
}

/*********************************************************************
** Function: get_comp_choice
** Description: Accesses computer choice function with Hand object
** Parameters: none
** Pre-Conditions: Computer hasn't asked for a rank
** Post-Conditions: returns the rank the computer asks for
*********************************************************************/
int Player::get_comp_choice()
{
    int choice = this->hand.computer_choice();
    return choice;
}

/*********************************************************************
** Function: get_n_cards
** Description: Access the getter for getting number of cards in hand
** Parameters: none
** Pre-Conditions: Unknown amount of cards in hand
** Post-Conditions: Returns number of cards in hand
*********************************************************************/
int Player::get_n_cards()
{
    int number = this->hand.get_n_cards();
    return number;
}

/*********************************************************************
** Function: get_n_books
** Description: Getter function to return number of books for player
** Parameters: none
** Pre-Conditions: Unknowm amount of books for player
** Post-Conditions: Returns amount of books player has
*********************************************************************/
int Player::get_n_books()
{
    return this->n_books;
}

/*********************************************************************
** Function: print_books
** Description: Prints out the ranks in each book
** Parameters: none
** Pre-Conditions:  Unkown content of book
** Post-Conditions: Displays contents of book
*********************************************************************/
void Player::print_books()
{

    for (int i = 0; i < n_books; i++)
    {
        int rank = books[i];
        string_in_book(rank);
    }
}

/*********************************************************************
** Function: show_hand
** Description: Uses hand object to call the function display_hand
** Parameters: none
** Pre-Conditions: Hand not shown
** Post-Conditions: Function called to show hand
*********************************************************************/
void Player::show_hand()
{
    //Display only cards in hand
    this->hand.display_hand();
}

/*********************************************************************
** Function: string_in_book
** Description: Maps the rank in a book to string and prints to screen
** Parameters: int
** Pre-Conditions: Accepts int element from book
** Post-Conditions: Prints out corresponding name of rank in string
*********************************************************************/
void Player::string_in_book(int rank)
{
    switch (rank)
    {
    case 0:
        cout << "King's ";
        break;
    case 1:
        cout << "Ace's ";
        break;
    case 2:
        cout << "Two's ";
        break;
    case 3:
        cout << "Three's ";
        break;
    case 4:
        cout << "Four's ";
        break;
    case 5:
        cout << "Five's ";
        break;
    case 6:
        cout << "Sixe's ";
        break;
    case 7:
        cout << "Seven's ";
        break;
    case 8:
        cout << "Eight's ";
        break;
    case 9:
        cout << "Nine's ";
        break;
    case 10:
        cout << "Ten's ";
        break;
    case 11:
        cout << "Jack's ";
        break;
    case 12:
        cout << "Queen's ";
        break;
    }
}
