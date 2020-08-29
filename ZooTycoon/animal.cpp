/*********************************************************************
** Program Filename: animal.cpp
** Author: Katie Blickenstaff
** Date: 8/1/2020
** Description: Animal class .cpp
*********************************************************************/
#include "animal.h"
#include "zoo.h"

#include <iostream>

using namespace std;

/*********************************************************************
** Function: Animal()
** Description: Default constructor of Animal
** Parameters: none
** Pre-Conditions: Variables are unitialized
** Post-Conditions: Variables have been initialized
*********************************************************************/
Animal::Animal()
{
    // cout << "Default animal constructor" << endl;
    this->age = 0;
    this->price = 0;
    this->n_babies = 0;
    this->food_cost = 0;
    this->revenue = 0;
}

/*********************************************************************
** Function: get_species()
** Description: Returns the value of species
** Parameters: none
** Pre-Conditions: Value of species unknown
** Post-Conditions: Value of species returned and stored
*********************************************************************/
int Animal::get_species()
{
    return this->species;
}

/*********************************************************************
** Function: get_age()
** Description: Returns the age of animal
** Parameters: none
** Pre-Conditions: Age of animal unknown
** Post-Conditions: Age of animal returned and stored
*********************************************************************/
int Animal::get_age()
{
    return this->age;
}

/*********************************************************************
** Function: add_age()
** Description: Adds a year to the current age
** Parameters: int
** Pre-Conditions: Age is X
** Post-Conditions: Age is X+1
*********************************************************************/
void Animal::add_age(int age)
{
    this->age = age + 1;
}

/*********************************************************************
** Function: get_price()
** Description: Returns the price of the animal
** Parameters: none
** Pre-Conditions: Price of animal is unknown
** Post-Conditions: Price is returned and stored
*********************************************************************/
int Animal::get_price()
{
    return this->price;
}

/*********************************************************************
** Function: get_n_babies()
** Description: Gets the number of babies an animal can have
** Parameters: none
** Pre-Conditions: Number of babies is unknown
** Post-Conditions: Number of babies is returned and stored
*********************************************************************/
int Animal::get_n_babies()
{
    return this->n_babies;
}

/*********************************************************************
** Function: get_food_cost()
** Description: Returns the food_cost multiplier of the animal
** Parameters: none
** Pre-Conditions: Food cost is unknown
** Post-Conditions: Food cost is returned and stored
*********************************************************************/
int Animal::get_food_cost()
{
    return this->food_cost;
}

/*********************************************************************
** Function: get_revenue()
** Description: Returns the revenue multiplier of the animal
** Parameters: none
** Pre-Conditions: Revenue is unknown
** Post-Conditions: Revenue is returned and stored
*********************************************************************/
float Animal::get_revenue()
{
    return this->revenue;
}
