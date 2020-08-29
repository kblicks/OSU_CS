/*********************************************************************
** Program Filename: catalog.cpp
** Author: Katie Blickenstaff
** Date: 7/5/2020
** Description: This is the cpp file that hosts the functions for the program. The program reads in spellbooks and spells and allows the user to sort and display the spells/spellbooks back to the screen or written to a file. 
** Input: strings, integers
** Output: sorted results and writes to files or prints to console
*********************************************************************/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

#include "catalog.h"
using namespace std;

/*********************************************************************
** Function: spell *create_spells
** Description: Creates the spells array
** Parameters: integer
** Pre-Conditions: Accepts the number of spells in a spellbook 
** Post-Conditions: Allocates space for the spells in the spellbook based on input received
*********************************************************************/
spell *create_spells(int size)
{
    spell *s = new spell[size];
    return s;
}

/*********************************************************************
** Function: spellbook *create_spellbooks
** Description: Creates the spellbook database by allocating space to the array
** Parameters: integer
** Pre-Conditions: Accepts the number of spellbooks
** Post-Conditions: Allocates space for spellbooks in the array
*********************************************************************/
spellbook *create_spellbooks(int size)
{

    spellbook *spellbooks = new spellbook[size];
    return spellbooks;
}

/*********************************************************************
** Function: populate_spell_data
** Description: populates the spells from the text file to the array s 
** Parameters: pointer, integer, ifstream
** Pre-Conditions: empty spell array
** Post-Conditions: populated spell array
*********************************************************************/
void populate_spell_data(spell *s, int size, ifstream &spellb_text)
{

    for (int j = 0; j < size; j++)
    {
        spellb_text >> s[j].name >> s[j].success_rate >> s[j].effect;
    }
}

/*********************************************************************
** Function: populate_spellbook_db
** Description: populates the spellbooks from the text file to the array spellbooks
** Parameters:  array, integer, ifstream
** Pre-Conditions: takes in the declared array
** Post-Conditions: outputs populated array 
*********************************************************************/
void populate_spellbook_db(spellbook *spellbooks, int size, ifstream &spellb_text)
{
    spell *s;

    for (int i = 0; i < size; i++)
    {
        spellb_text >> spellbooks[i].title >> spellbooks[i].author >> spellbooks[i].num_pages >> spellbooks[i].edition >> spellbooks[i].num_spells;

        struct spell *s = create_spells(spellbooks[i].num_spells);
        spellbooks[i].s = s;
        populate_spell_data(spellbooks[i].s, spellbooks[i].num_spells, spellb_text);
    }
}

/*********************************************************************
** Function: wizard *create_wizard_db
** Description: Allocates space to the wizards array to hold information about the wizards
** Parameters: integer
** Pre-Conditions: takes in the size of array
** Post-Conditions: creates array of size x
*********************************************************************/
wizard *create_wizard_db(int size)
{
    wizard *wizards = new wizard[size];
    return wizards;
}

/*********************************************************************
** Function: populate_wizard_db
** Description: Populates the wizards from the text file
** Parameters: array, integer, ifstream
** Pre-Conditions: takes in the wizards array
** Post-Conditions: array populated by wizard information
*********************************************************************/
void populate_wizard_db(wizard *wizards, int size, ifstream &wizard_text)
{
    for (int i = 0; i < size; i++)
    {
        wizard_text >> wizards[i].name >> wizards[i].id >> wizards[i].password >> wizards[i].position_title >> wizards[i].beard_length;
    }
}

/*********************************************************************
** Function: delete_info
** Description: Deletes the wizards and spellbooks arrays
** Parameters: array, array
** Pre-Conditions: takes in filled wizards and spellbooks arrays
** Post-Conditions: deletes the array and sets to null
*********************************************************************/
void delete_info(wizard **wizards, spellbook **spellbooks, int sb_size)
{
    delete[] * wizards;
    *wizards = NULL;

    for (int i = 0; i < sb_size; i++)
    {
        delete[](*spellbooks)[i].s;
        (*spellbooks)[i].s = NULL;
    }
    delete[] * spellbooks;
    *spellbooks = NULL;
}
/*********************************************************************
** Function: check_int_input
** Description: Checks any integer input from the user and error handles for chars
** Parameters: none
** Pre-Conditions: none
** Post-Conditions: returns the user input
*********************************************************************/
int check_int_input()
{
    cin.clear();
    string input_str;
    int input;
    getline(cin, input_str);

    while (cin.fail() || cin.eof() || input_str.find_first_not_of("0123456789") != string::npos)
    {
        if (input_str.find_first_not_of("0123456789") == string::npos)
        {
            cin.clear();
            cin.ignore(256, '\n');
        }

        cout << " Re-Enter a valid " << endl;
        getline(cin, input_str);
    }

    input = atoi(input_str.c_str());
    return input;
}

/*********************************************************************
** Function: Login
** Description: Prompts the user for ID and Password then matches them against the wizards array, looking for a match
** Parameters: array, integer
** Pre-Conditions: takes in the filled wizards array
** Post-Conditions: returns if the user is a student or not
*********************************************************************/
int Login(wizard **wizards, int size)
{
    for (int i = 0; i < 3; i++)
    {

        cout << "Please enter your ID" << endl;
        int id = check_int_input();

        string pass;
        cout << "Please enter your password" << endl;
        cin >> pass;

        for (int i = 0; i < size; i++)
        {

            if (id == (*wizards)[i].id && pass == (*wizards)[i].password)
            {
                cout << endl;
                cout << "Hello There! Welcome " << (*wizards)[i].name << " " << endl;
                cout << "ID: " << (*wizards)[i].id << " " << endl;
                cout << "Status: " << (*wizards)[i].position_title << " " << endl;
                cout << "Beard_Length: " << (*wizards)[i].beard_length << " " << endl;
                cout << " " << endl;

                int status = 0;
                if ((*wizards)[i].position_title == "Student")
                {
                    return status;
                }
                else
                {
                    status++;
                    return status;
                }
            }
        }
        cout << "Incorrect ID or Password" << endl;
        cin.clear();
        cin.ignore(256, '\n');
    }
    cout << "Out of attempts. Program quitting" << endl;
    exit(EXIT_FAILURE);
}

/*********************************************************************
** Function: swap
** Description: Helper funciton to swap
** Parameters: int pointer, int pointer
** Pre-Conditions: two consecutive array elements
** Post-Conditions: swaps the array elements
*********************************************************************/
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
/*********************************************************************
** Function: sort_by_pages
** Description: Sorts the spellbooks by number of pages in ascending order
** Parameters: pointer array, integer
** Pre-Conditions: spellbooks are unsorted
** Post-Conditions: spellbooks sorted by number of pages in ascending order
*********************************************************************/
void sort_by_pages(spellbook *spellbooks, int size)
{
    bool swapped;
    for (int i = 0; i < size - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (spellbooks[j].num_pages > spellbooks[j + 1].num_pages)
            {
                swap(spellbooks[j], spellbooks[j + 1]);
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
** Function: sort_by_avg
** Description: Computes and sorts the spellbooks by average success rate
** Parameters: pointer array, integer
** Pre-Conditions: spellbooks are unsorted
** Post-Conditions: spellbooks sorted by the average in ascending order
*********************************************************************/
void sort_by_avg(spellbook *spellbooks, int size)
{

    for (int i = 0; i < size; i++)
    {
        double total = 0, avg = 0;
        for (int j = 0; j < spellbooks[i].num_spells; j++)
        {
            total += spellbooks[i].s[j].success_rate;
        }
        avg = total / spellbooks[i].num_spells;
        spellbooks[i].avg_success_rate = avg;
    }

    bool swapped;
    for (int i = 0; i < size - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (spellbooks[j].avg_success_rate > spellbooks[j + 1].avg_success_rate)
            {
                swap(spellbooks[j], spellbooks[j + 1]);
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
** Function: print_group_by_effect_student
** Description: Groups spells by effect and prints them for students. Students are not allowed to see poison or death spells.
** Parameters: pointer array, integer
** Pre-Conditions: the spells are unsorted
** Post-Conditions: group the spells by effect and prints them for a student
*********************************************************************/
void print_group_by_effect_student(spellbook *spellbooks, int size)
{

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < spellbooks[i].num_spells; j++)
        {
            if (spellbooks[i].s[j].effect == "memory_loss")
            {
                cout << spellbooks[i].s[j].effect << " " << spellbooks[i].s[j].name << endl;
            }
        }
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < spellbooks[i].num_spells; j++)
        {
            if (spellbooks[i].s[j].effect == "fire")
            {
                cout << spellbooks[i].s[j].effect << " " << spellbooks[i].s[j].name << endl;
            }
        }
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < spellbooks[i].num_spells; j++)
        {
            if (spellbooks[i].s[j].effect == "bubble")
            {
                cout << spellbooks[i].s[j].effect << " " << spellbooks[i].s[j].name << endl;
            }
        }
    }
}

/*********************************************************************
** Function: print_group_by_effect_wizard
** Description: groups spells by effect and prints all the spells
** Parameters: pointer array, integer
** Pre-Conditions: unsorted spells
** Post-Conditions: groups the spells by effect and prints all the spells
*********************************************************************/
void print_group_by_effect_wizard(spellbook *spellbooks, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < spellbooks[i].num_spells; j++)
        {
            if (spellbooks[i].s[j].effect == "memory_loss")
            {
                cout << spellbooks[i].s[j].effect << " " << spellbooks[i].s[j].name << endl;
            }
        }
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < spellbooks[i].num_spells; j++)
        {
            if (spellbooks[i].s[j].effect == "fire")
            {
                cout << spellbooks[i].s[j].effect << " " << spellbooks[i].s[j].name << endl;
            }
        }
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < spellbooks[i].num_spells; j++)
        {
            if (spellbooks[i].s[j].effect == "bubble")
            {
                cout << spellbooks[i].s[j].effect << " " << spellbooks[i].s[j].name << endl;
            }
        }
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < spellbooks[i].num_spells; j++)
        {
            if (spellbooks[i].s[j].effect == "poison")
            {
                cout << spellbooks[i].s[j].effect << " " << spellbooks[i].s[j].name << endl;
            }
        }
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < spellbooks[i].num_spells; j++)
        {
            if (spellbooks[i].s[j].effect == "death")
            {
                cout << spellbooks[i].s[j].effect << " " << spellbooks[i].s[j].name << endl;
            }
        }
    }
}

/*********************************************************************
** Function: writefile_group_by_effect_student
** Description: groups spells by effect and writes to a file for students. Students are not allowed to see poison or death spells. 
** Parameters: pointer array, integer, ofstream
** Pre-Conditions: spells are unsorted
** Post-Conditions: groups spells by effect and writes them to file for student
*********************************************************************/
void writefile_group_by_effect_student(spellbook *spellbooks, int size, ofstream &file)
{
    file << "-------------------------------" << endl;
    file << "       SPELLS BY EFFECT        " << endl;
    file << "-------------------------------" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < spellbooks[i].num_spells; j++)
        {
            if (spellbooks[i].s[j].effect == "memory_loss")
            {
                file << spellbooks[i].s[j].effect << " " << spellbooks[i].s[j].name << endl;
            }
        }
    }
    file << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < spellbooks[i].num_spells; j++)
        {
            if (spellbooks[i].s[j].effect == "fire")
            {
                file << spellbooks[i].s[j].effect << " " << spellbooks[i].s[j].name << endl;
            }
        }
    }
    file << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < spellbooks[i].num_spells; j++)
        {
            if (spellbooks[i].s[j].effect == "bubble")
            {
                file << spellbooks[i].s[j].effect << " " << spellbooks[i].s[j].name << endl;
            }
        }
    }
}

/*********************************************************************
** Function: writefile_group_by_effect_wizard
** Description: groups spells by effect and writes all of them to a file
** Parameters: pointer array, integer, ofstream
** Pre-Conditions: spells are unsorted
** Post-Conditions: groups spells and writes all of them to a file
*********************************************************************/
void writefile_group_by_effect_wizard(spellbook *spellbooks, int size, ofstream &file)
{
    file << "-------------------------------" << endl;
    file << "       SPELLS BY EFFECT        " << endl;
    file << "-------------------------------" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < spellbooks[i].num_spells; j++)
        {
            if (spellbooks[i].s[j].effect == "memory_loss")
            {
                file << spellbooks[i].s[j].effect << " " << spellbooks[i].s[j].name << endl;
            }
        }
    }
    file << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < spellbooks[i].num_spells; j++)
        {
            if (spellbooks[i].s[j].effect == "fire")
            {
                file << spellbooks[i].s[j].effect << " " << spellbooks[i].s[j].name << endl;
            }
        }
    }
    file << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < spellbooks[i].num_spells; j++)
        {
            if (spellbooks[i].s[j].effect == "bubble")
            {
                file << spellbooks[i].s[j].effect << " " << spellbooks[i].s[j].name << endl;
            }
        }
    }
    file << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < spellbooks[i].num_spells; j++)
        {
            if (spellbooks[i].s[j].effect == "poison")
            {
                file << spellbooks[i].s[j].effect << " " << spellbooks[i].s[j].name << endl;
            }
        }
    }
    file << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < spellbooks[i].num_spells; j++)
        {
            if (spellbooks[i].s[j].effect == "death")
            {
                file << spellbooks[i].s[j].effect << " " << spellbooks[i].s[j].name << endl;
            }
        }
    }
}

/*********************************************************************
** Function: print_pages
** Description: prints the spellbooks by pages and will hide spellbooks containing poison and death effect spells
** Parameters: double pointer array, integer, integer
** Pre-Conditions: spellbooks are unsorted
** Post-Conditions: sorts the spellbooks by number of pages and prints them
*********************************************************************/
void print_pages(spellbook **spellbooks, int size, int status)
{
    if (status == 0)
    {
        for (int i = 0; i < size; i++)
        {
            string effects;
            for (int j = 0; j < (*spellbooks)[i].num_spells; j++)
            {
                //temp = map_string_to_int(spellbooks[i].s[j].effect);
                effects.append(" \" ");
                effects.append((*spellbooks)[i].s[j].effect);
                effects.append(" \", ");
            }

            size_t death = effects.find("death");
            size_t poison = effects.find("poison");
            if (death != std::string::npos)
            {
            }
            else if (poison != std::string::npos)
            {
            }
            else
            {
                cout << (*spellbooks)[i].title << endl;
                cout << (*spellbooks)[i].num_pages << endl;
                cout << " " << endl;
            }
        }
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            cout << (*spellbooks)[i].title << " " << endl;
            cout << (*spellbooks)[i].num_pages << " " << endl;
            cout << "" << endl;
        }
    }
}

/*********************************************************************
** Function: writefile_pages
** Description: writes the spellbooks to file organized by pages and will hide spellbooks containing poison and death effect spells
** Parameters: double pointer array, integer, integer
** Pre-Conditions: spellbooks are unsorted
** Post-Conditions: sorts the spellbooks by number of pages and writes them to a file
*********************************************************************/
void writefile_pages(spellbook *spellbooks, int size, int status, ofstream &file)
{
    file << "-------------------------------" << endl;
    file << "SPELLBOOKS SORTED BY PAGE NUMBER" << endl;
    file << "-------------------------------" << endl;
    if (status == 0)
    {
        for (int i = 0; i < size; i++)
        {
            string effects;
            for (int j = 0; j < spellbooks[i].num_spells; j++)
            {
                //temp = map_string_to_int(spellbooks[i].s[j].effect);
                effects.append(" \" ");
                effects.append(spellbooks[i].s[j].effect);
                effects.append(" \", ");
            }

            size_t death = effects.find("death");
            size_t poison = effects.find("poison");
            if (death != std::string::npos)
            {
            }
            else if (poison != std::string::npos)
            {
            }
            else
            {
                file << spellbooks[i].title << endl;
                file << spellbooks[i].num_pages << endl;
                file << " " << endl;
            }
        }
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            file << spellbooks[i].title << " " << endl;
            file << spellbooks[i].num_pages << " " << endl;
            file << "" << endl;
        }
    }
}

/*********************************************************************
** Function: print_success
** Description: prints the spellbooks by average success rate and will hide spellbooks containing poison and death effect spells
** Parameters: double pointer array, integer, integer
** Pre-Conditions: spellbooks are unsorted
** Post-Conditions: sorts the spellbooks by average success rate and prints them
*********************************************************************/
void print_success(spellbook *spellbooks, int size, int status)
{
    if (status == 0)
    {
        for (int i = 0; i < size; i++)
        {
            string effects;
            for (int j = 0; j < spellbooks[i].num_spells; j++)
            {
                effects.append(" \" ");
                effects.append(spellbooks[i].s[j].effect);
                effects.append(" \", ");
            }

            size_t death = effects.find("death");
            size_t poison = effects.find("poison");
            if (death != std::string::npos)
            {
            }
            else if (poison != std::string::npos)
            {
            }
            else
            {
                cout << spellbooks[i].title << endl;
                cout << spellbooks[i].avg_success_rate << endl;
                cout << endl;
            }
        }
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            cout << spellbooks[i].title << " " << endl;
            cout << spellbooks[i].avg_success_rate << endl;
            cout << endl;
        }
    }
}

/*********************************************************************
** Function: writefile_success
** Description: writes the spellbooks to file organized by pages and will hide spellbooks containing poison and death effect spells
** Parameters: double pointer array, integer, integer
** Pre-Conditions: spellbooks are unsorted
** Post-Conditions: spellbooks are sorted and written to a file
*********************************************************************/
void writefile_success(spellbook *spellbooks, int size, int status, ofstream &file)
{
    file << "-------------------------------" << endl;
    file << "AVERAGE SUCCESS RATE OF SPELLS" << endl;
    file << "-------------------------------" << endl;
    if (status == 0)
    {
        for (int i = 0; i < size; i++)
        {
            string effects;
            for (int j = 0; j < spellbooks[i].num_spells; j++)
            {
                //temp = map_string_to_int(spellbooks[i].s[j].effect);
                effects.append(" \" ");
                effects.append(spellbooks[i].s[j].effect);
                effects.append(" \", ");
            }

            size_t death = effects.find("death");
            size_t poison = effects.find("poison");
            if (death != std::string::npos)
            {
            }
            else if (poison != std::string::npos)
            {
            }
            else
            {
                file << spellbooks[i].title << endl;
                file << spellbooks[i].avg_success_rate << endl;
                file << endl;
            }
        }
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            file << spellbooks[i].title << " " << endl;
            file << spellbooks[i].avg_success_rate << endl;
            file << endl;
        }
    }
}

/*********************************************************************
** Function: check_open
** Description: helper function to check if text files are open
** Parameters: ifstream
** Pre-Conditions: file is open
** Post-Conditions: file is open
*********************************************************************/
void check_open(ifstream &file)
{
    if (!file.is_open())
    {
        cout << "Could not open file" << endl;
        exit(1);
    }
}
/*********************************************************************
** Function: output_open
** Description: checks if the output file has been opened
** Parameters: ofstream
** Pre-Conditions: output file open
** Post-Conditions: output file open
*********************************************************************/
void output_open(ofstream &file)
{
    if (!file.is_open())
    {
        cout << "Error opening file to write!" << endl;
        exit(1);
    }
}

/*********************************************************************
** Function: get_size
** Description: gets the first line of text from the wizards.txt and spellbooks.txt file because they are the sizes of the array 
** Parameters: ifstream
** Pre-Conditions: size of arrays not determined
** Post-Conditions: first line read in and size of arrays determined
*********************************************************************/
int get_size(ifstream &text)
{
    int size;
    string number;
    getline(text, number);
    size = atoi(number.c_str());
    return size;
}
/*********************************************************************
** Function: display_text
** Description: asks the user how they would like to display the text and does so
** Parameters: pointer array, integer, integer, integer
** Pre-Conditions: arrays ahve been sorted
** Post-Conditions: prints results or writes them to a file
*********************************************************************/
void display_text(spellbook *spellbooks, int size, int status, int x)
{
    bool choose = false;
    while (choose == false)
    {
        cout << "How would you like the information displayed?" << endl;
        cout << "1. Printed to screen" << endl;
        cout << "2. Printed to file" << endl;
        int p = check_int_input();
        if (p == 1)
        {

            switch (x)
            {
            case 1:
                print_pages(&spellbooks, size, status);
                choose = true;
                break;
            case 2:
                if (status == 0)
                {
                    print_group_by_effect_student(spellbooks, size);
                }
                else
                {
                    print_group_by_effect_wizard(spellbooks, size);
                }
                choose = true;
                break;
            case 3:
                print_success(spellbooks, size, status);
                choose = true;
                break;
            }
        }
        else if (p == 2)
        {
            string filename;
            cout << "What would you like to name your file?" << endl;
            cin >> filename;
            ofstream MyFile;
            MyFile.open(filename.c_str(), ios::app);
            output_open(MyFile);

            switch (x)
            {
            case 1:
                writefile_pages(spellbooks, size, status, MyFile);
                choose = true;
                break;
            case 2:
                if (status == 0)
                {
                    writefile_group_by_effect_student(spellbooks, size, MyFile);
                }
                else
                {
                    writefile_group_by_effect_wizard(spellbooks, size, MyFile);
                }
                choose = true;
                break;
            case 3:
                writefile_success(spellbooks, size, status, MyFile);
                choose = true;
                break;
            }
            cin.clear();
            cin.ignore(256, '\n');
            MyFile.close();
        }
        else
        {
            cout << "Sorry but that is not an option. Hit enter to try again" << endl;
            cin.clear();
            cin.ignore(256, '\n');
        }
    }
}
/*********************************************************************
** Function: options
** Description: provides options to the user for sorting or grouping the spellbooks and spells. Continues to prompt the user to sort until user chooses quit
** Parameters: pointer array, pointer array, integer, integer
*********************************************************************/
void options(wizard *wizards, spellbook *spellbooks, int sb_size, int status)
{
    bool choose = false;

    while (choose == false)
    {
        cout << "Please choose an option from below: " << endl;
        cout << "1. Sort spellbooks by number of pages" << endl;
        cout << "2. Group spells by effect" << endl;
        cout << "3. Sort spellbooks by average success rate" << endl;
        cout << "4. Quit" << endl;
        int x = check_int_input();

        switch (x)
        {
        case 1:
            sort_by_pages(spellbooks, sb_size);
            display_text(spellbooks, sb_size, status, x);
            break;
        case 2:
            display_text(spellbooks, sb_size, status, x);
            break;
        case 3:
            sort_by_avg(spellbooks, sb_size);
            display_text(spellbooks, sb_size, status, x);
            break;
        case 4:
            cout << "Goodbye!" << endl;
            choose = true;
            //   delete_info(wizards, spellbooks, sb_size);
            // exit(1);
            break;
        default:
            cout << "Sorry but that is not an option. Hit enter to try again" << endl;
            break;
            //review these 2 below
            cin.clear();
            cin.ignore(256, '\n');
        }
    }
}
