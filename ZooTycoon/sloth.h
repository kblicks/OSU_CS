#ifndef SLOTH_H
#define SLOTH_H

#include "animal.h"

#include <iostream>

using namespace std;

class Sloth : public Animal
{
private:
public:
    Sloth();
    Sloth(int);
    void display_type();
    void set_adult();
};

#endif