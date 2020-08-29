/*********************************************************************
** Program Filename: sloth.cpp
** Author: Katie Blickenstaff
** Date: 8/1/2020
** Description: Sloth class .cpp
*********************************************************************/
#include "animal.h"
#include "sloth.h"

#include <iostream>

using namespace std;

/*********************************************************************
** Function: Sloth()
** Description: Default constructor of sloth
** Parameters: none
** Pre-Conditions: Variables unitialized 
** Post-Conditions: Variables assigned values
*********************************************************************/
Sloth::Sloth()
{
    //  cout << "Default Sloth constructor" << endl;
    this->species = 3;
    this->age = 24;
    this->price = 1250;
    this->n_babies = 4;
    this->food_cost = 1;
    this->revenue = 0.5;
}

/*********************************************************************
** Function: Sloth()
** Description: Non default constructor of Sloth to create a baby animal
** Parameters: int
** Pre-Conditions: Baby stats not initialized
** Post-Conditions: Baby stats initialized
*********************************************************************/
Sloth::Sloth(int age)
{
    // cout << "non-default constructor of Sloth" << endl;
    this->species = 3;
    this->age = age;
    this->price = 1250;
    this->food_cost = 1;
    this->revenue = 1.0;
}

/*********************************************************************
** Function: set_adult()
** Description: Sets the traits of a sloth to adult
** Parameters: none
** Pre-Conditions: Sloth has baby traits
** Post-Conditions: Sloth has adult traits
*********************************************************************/
void Sloth::set_adult()
{
    // this->age = age;
    this->n_babies = 4;
    this->revenue = 0.5;
}

/*********************************************************************
** Function: display_type()
** Description: Displays the species of the animal
** Parameters: none
** Pre-Conditions: Species not displayed
** Post-Conditions: Species name displayed
*********************************************************************/
void Sloth::display_type()
{
    cout << "Sloth" << endl;
}