/*********************************************************************
** Program Filename: animal.h
** Author: Katie Blickenstaff
** Date: 8/1/2020
** Description: header file for the animal class
*********************************************************************/
#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>

using namespace std;

class Animal
{
protected:
    int age;
    int food_cost;
    int n_babies;
    //Sell price and sick price for adults
    int price;
    int species;
    float revenue;

public:
    Animal();
    //ageup +1
    void add_age(int);

    //Pure virtual void
    virtual void set_adult() = 0;
    virtual void display_type() = 0;

    //Getters
    int get_species();
    int get_age();
    int get_food_cost();
    int get_price();
    float get_revenue();
    int get_n_babies();
};

#endif