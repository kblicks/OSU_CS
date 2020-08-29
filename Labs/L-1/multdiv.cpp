#include <iostream>
#include <stdlib.h>
#include <cmath>
#include "multdiv.h"

using namespace std;

bool is_valid_dimensions(char *m, char *n)
{

    if (*m <= '0' || *n <= '0')
    {
        cout << "Invalid number of rows. Number must be positive and greater than 0" << endl;
        return false;
    }
    else
    {

        return true;
    }
}

multdiv_entry **create_table(int row, int col)
{

    multdiv_entry **tables = new multdiv_entry *[row];
    for (int i = 0; i < row; i++)
    {
        tables[i] = new multdiv_entry[col];
    }
    //Populate mult
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            tables[i - 1][j - 1].mult = (i * j);
        }
    }
    //Populate div
    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {

            tables[i - 1][j - 1].div = ((float)i / (float)j);
        }
    }
    return tables;
}

void print_table(multdiv_entry **tables, int row, int col)
{
    cout << "Multiplication Table" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << tables[i][j].mult << "\t";
        }
        //Newline
        cout << endl;
    }
    cout << " " << endl;
    cout << " " << endl;
    cout << "Division Table" << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << tables[i][j].div << "\t";
        }
        //Newline
        cout << endl;
    }
}

void delete_table(multdiv_entry **tables, int row)
{
    for (int i = 0; i < row; i++)
    {
        delete[] tables[i];
    }
    delete[] tables;
}
