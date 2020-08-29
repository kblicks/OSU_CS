
/*********************************************************************
** Program Filename: run_wizard.cpp
** Author: Katie Blickenstaff
** Date: 7/5/2020
** Description: This file holds the main function 
** Input: command line argument takes two files
*********************************************************************/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

#include "catalog.h"
using namespace std;

int main(int argc, char *argv[])
{ //Open files
    ifstream wizard_text(argv[1]);
    ifstream spellb_text(argv[2]);
    //Check if files opened successfully
    check_open(wizard_text);
    check_open(spellb_text);
    //Get the size
    int w_size = get_size(wizard_text);
    int sb_size = get_size(spellb_text);
    //define the array
    wizard *wizards;
    spellbook *spellbooks;
    //Create the wizard database and populate
    wizards = create_wizard_db(w_size);
    populate_wizard_db(wizards, w_size, wizard_text);
    //Create the spellbooks database and populate
    spellbooks = create_spellbooks(sb_size);
    populate_spellbook_db(spellbooks, sb_size, spellb_text);
    //Close the files
    spellb_text.close();
    wizard_text.close();

    //Login
    int status = Login(&wizards, w_size);
    cin.clear();
    cin.ignore(256, '\n');
    //Chose how to sort
    options(wizards, spellbooks, sb_size, status);
    delete_info(&wizards, &spellbooks, sb_size);
}

/* Print loops for error checking


WIZARDS

    for (int i = 0; i < size; i++)
    {
        cout << wizards[i].name << " " << endl;
        cout << wizards[i].id << " " << endl;
        cout << wizards[i].password << " " << endl;
        cout << wizards[i].position_title << " " << endl;
        cout << wizards[i].beard_length << " " << endl;
        cout << " " << endl;
    }

SPELLBOOKS

    for (int i = 0; i < sb_size; i++)
    {
        cout << spellbooks[i].title << " " << endl;
        cout << spellbooks[i].author << " " << endl;
        cout << spellbooks[i].num_pages << " " << endl;
        cout << spellbooks[i].edition << " " << endl;
        cout << spellbooks[i].num_spells << " " << endl;
        cout << spellbooks[i].avg_success_rate << " " << endl;

        cout << " " << endl;
    }



SPELLS

    for (int i = 0; i < sb_size; i++)
    {
        for (int j = 0; j < spellbooks[i].num_spells; j++)
        {
            cout << spellbooks[i].s[j].name << " " << endl;
            cout << spellbooks[i].s[j].success_rate << " " << endl;
            cout << spellbooks[i].s[j].effect << " " << endl;

            cout << " " << endl;
        }
    }


*/
