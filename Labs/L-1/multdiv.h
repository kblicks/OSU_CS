#include <iostream>
using namespace std;

struct multdiv_entry
{
    int mult;
    float div;
};

bool is_valid_dimensions(char *, char *);
multdiv_entry **create_table(int, int);
void print_table(multdiv_entry **, int, int);
void delete_table(multdiv_entry **, int);
