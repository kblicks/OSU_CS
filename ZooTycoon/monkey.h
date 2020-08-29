#ifndef MONKEY_H
#define MONKEY_H

#include "animal.h"

#include <iostream>

using namespace std;

class Monkey : public Animal
{
private:
    int num_monkey;

public:
    Monkey();
    Monkey(int);
    void display_type();
    void set_adult();

    //Getters and setters
};

#endif