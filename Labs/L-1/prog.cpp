#include <iostream>
#include <stdlib.h>
#include <cmath>
#include "multdiv.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        cout << "Please enter 3 arguements! Usage: [exe_name] [# rows] [# columns]" << endl;
        return 1;
    }

    bool valid = is_valid_dimensions(argv[1], argv[2]);
    multdiv_entry **tables;
    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);

    if (valid = true)
    {
        tables = create_table(rows, cols);
        print_table(tables, rows, cols);
        delete_table(tables, rows);
    }
    else
    {
        return 1;
    }

    /* Print out argv
    for (int i = 0; i < argc; ++i)
    {
        cout << argv[i] << endl;
    }
    */
    return 1;
}