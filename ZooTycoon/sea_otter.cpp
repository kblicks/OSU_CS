/*********************************************************************
** Program Filename: sea_otter.cpp
** Author: Katie Blickenstaff
** Date: 8/1/2020
** Description: Sea Otter class .cpp
*********************************************************************/
#include "animal.h"
#include "sea_otter.h"

#include <iostream>

using namespace std;

/*********************************************************************
** Function: Sea_otter()
** Description: Default constructor for sea_otter
** Parameters: none
** Pre-Conditions: Variables unitialized
** Post-Conditions: Variables assigned values
*********************************************************************/
Sea_otter::Sea_otter()
{
    //    cout << "Default Otter constructor" << endl;
    this->species = 2;
    this->age = 24;
    this->price = 2500;
    this->n_babies = 2;
    this->food_cost = 2;
    this->revenue = 0.5;
}

/*********************************************************************
** Function: Sea_otter()
** Description: Non default constructor of Sea_otter
** Parameters: int
** Pre-Conditions: Baby stats unitialized
** Post-Conditions: Baby stats given values
*********************************************************************/
Sea_otter::Sea_otter(int age)
{
    //   cout << "non-default constructor of Otter" << endl;
    this->species = 2;
    this->age = age;
    this->price = 2500;
    this->food_cost = 2;
    this->revenue = 1.0;
}

/*********************************************************************
** Function: set_adults()
** Description: Sets traits of a sloth to adult 
** Parameters: none
** Pre-Conditions: Otter has baby traits
** Post-Conditions: Otter has adult traits
*********************************************************************/
void Sea_otter::set_adult()
{

    this->n_babies = 2;
    this->revenue = 0.5;
}

/*********************************************************************
** Function: display_type()
** Description: Displays the species of the animal
** Parameters: none
** Pre-Conditions: Species not displayed
** Post-Conditions: Species name displayed
*********************************************************************/
void Sea_otter::display_type()
{
    cout << "Sea Otter" << endl;
}
