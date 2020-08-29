#ifndef SEA_OTTER_H
#define SEA_OTTER_H

#include "animal.h"

#include <iostream>

using namespace std;

class Sea_otter : public Animal
{
private:
    int num_otters;

public:
    Sea_otter();
    Sea_otter(int);

    void display_type();
    void set_adult();
};

#endif