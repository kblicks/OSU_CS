/*********************************************************************
** Program Filename: catalog.h
** Author: Katie Blickenstaff
** Date: 7/5/2020
** Description: Contains the struct definitions and function headers
*********************************************************************/
#include <iostream>
using namespace std;

#ifndef CATALOG_H
#define CATALOG_H

//Struct definitions
struct wizard
{
    string name;
    int id;
    string password;
    string position_title;
    float beard_length;
};

struct spellbook
{
    string title;
    string author;
    int num_pages;
    int edition;
    int num_spells;
    float avg_success_rate;
    struct spell *s;
};

struct spell
{
    string name;
    float success_rate;
    string effect;
};

#endif

//Funciton definitions
spell *create_spells(int size);
spellbook *create_spellbooks(int size);
void populate_spell_data(spell *s, int size, ifstream &spellb_text);
void populate_spellbook_db(spellbook *spellbooks, int size, ifstream &spellb_text);
wizard *create_wizard_db(int size);
void populate_wizard_db(wizard *wizards, int size, ifstream &wizard_text);
void delete_info(wizard **wizards, spellbook **spellbooks, int sb_size);
int check_int_input();
int Login(wizard **wizards, int size);
void swap(int *xp, int *yp);
void sort_by_pages(spellbook *spellbooks, int size);
void sort_by_avg(spellbook *spellbooks, int size);
void print_group_by_effect_student(spellbook *spellbooks, int size);
void print_group_by_effect_wizard(spellbook *spellbooks, int size);
void writefile_group_by_effect_student(spellbook *spellbooks, int size, ofstream &file);
void writefile_group_by_effect_wizard(spellbook *spellbooks, int size, ofstream &file);
void print_pages(spellbook **spellbooks, int size, int status);
void writefile_pages(spellbook *spellbooks, int size, int status, ofstream &file);
void print_success(spellbook *spellbooks, int size, int status);
void writefile_success(spellbook *spellbooks, int size, int status, ofstream &file);
void check_open(ifstream &file);
void output_open(ofstream &file);
int get_size(ifstream &text);
void display_text(spellbook *spellbooks, int size, int status, int x);
void options(wizard *wizards, spellbook *spellbooks, int sb_size, int status);
