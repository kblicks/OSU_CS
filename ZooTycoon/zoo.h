/*********************************************************************
** Program Filename: zoo.h
** Author: Katie Blickenstaff
** Date: 8/1/2020
** Description: header file for the zoo class
*********************************************************************/
#ifndef ZOO_H
#define ZOO_H

#include "animal.h"

#include <iostream>
#include <vector>

using namespace std;

class Zoo
{
private:
    vector<Animal *> animals;
    //track animals
    int total_animals;
    int num_monkeys;
    int num_sea_otters;
    int num_sloths;
    int last_bought;
    //Adult/Baby breakdown
    int num_adult_monkeys;
    int num_baby_monkeys;
    int num_adult_otters;
    int num_baby_otters;
    int num_adult_sloths;
    int num_baby_sloths;

    //Money
    float start_money;
    float total_money;
    float m_purchases;
    float m_sales;
    float m_attendance_rev;
    float m_feed_costs;
    float m_meds;
    float food_cost;
    float last_m_attrev;

    //Time period
    int month;
    //monthly actions

    int bought;
    int sold;
    //Special base food multiplier
    bool boom_food;
    //Track attendance for month
    int attendance;

public:
    Zoo();
    //Game flow
    void play_game();

    //Player menu and monthly actions
    void menu();
    int action(int);
    void choose_animal_buy();
    void choose_animal_sell();
    int buy_animal(int);
    int sell_animal(int);

    //Special Event
    void random_event();
    void sickness();
    void birth();
    void boom_zoo();
    //Revenue and costs for month
    void balance_sheet();
    void feeding_cost();
    void add_revenue();
    void reset_m_vars();
    void get_last_month_rev();
    void calc_income();
    //Game over
    bool check_gameover();
    //Play again
    bool play_again();

    //Delete vector and free memory
    void del_vector();

    void ageup();
    void check_adulthood();

    //Getters and Setters
    void set_species_totals();
    void set_month_revenue();

    //Stats of zoo
    void add_speciesstats();
    void print_zoolist();
    void print_status();

    //Error handle input
    int check_int_input();

    template <class ForwardIterator, class T>
    ForwardIterator remove(ForwardIterator first, ForwardIterator last, const T &val)
    {
        ForwardIterator result = first;
        while (first != last)
        {
            if (!(*first == val))
            {
                *result = *first;
                ++result;
            }
            ++first;
        }
        return result;
    }
};

#endif