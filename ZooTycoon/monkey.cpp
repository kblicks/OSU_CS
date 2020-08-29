/*********************************************************************
** Program Filename: Monkey.cpp
** Author: Katie Blickenstaff
** Date: 8/1/2020
** Description: Monkey class .cpp
*********************************************************************/
#include "animal.h"
#include "monkey.h"

#include <iostream>

using namespace std;

/*********************************************************************
** Function: Monkey()
** Description: default constructor of Monkey to create a baby animal
** Parameters: int
** Pre-Conditions: Monkey stats not initialized
** Post-Conditions: Monkey stats initialized
*********************************************************************/
Monkey::Monkey()
{
    //  cout << "Default Monkey constructor" << endl;
    this->species = 1;
    this->age = 24;
    this->price = 7500;
    this->n_babies = 1;
    this->food_cost = 4;
    this->revenue = 2.0;
}

/*********************************************************************
** Function: Monkey()
** Description: Non default constructor of Monkey to create a baby animal
** Parameters: int
** Pre-Conditions: Baby stats not initialized
** Post-Conditions: Baby stats initialized
*********************************************************************/
Monkey::Monkey(int age)
{
    //  cout << "non-default constructor of Monkey" << endl;
    this->species = 1;
    this->age = age;
    this->price = 7500;
    this->food_cost = 4;
    this->revenue = 4.0;
}

/*********************************************************************
** Function: set_adult()
** Description: Sets the traits of a Monkey to adult
** Parameters: none
** Pre-Conditions: Monkey has baby traits
** Post-Conditions: Monkey has adult traits
*********************************************************************/
void Monkey::set_adult()
{
    // this->age = age;
    this->n_babies = 1;
    this->revenue = 2.0;
}

/*********************************************************************
** Function: display_type()
** Description: Displays the species of the animal
** Parameters: none
** Pre-Conditions: Species not displayed
** Post-Conditions: Species name displayed
*********************************************************************/
void Monkey::display_type()
{
    cout << "Monkey" << endl;
}
