#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

#include "student_db.h"

using namespace std;

student *create_student_db(int size)
{
    //Create the dynamic array to hold student information organized by the struct
    student *students = new student[size];

    return students;
}

void populate_student_db_info(student *students, int size, ifstream &input)
{
    for (int i = 0; i < size; i++)
    {
        input >> students[i].id >> students[i].name >> students[i].last >> students[i].major;
    }
}

void delete_student_db_info(student **students, int size)
{
    delete[] * students;
    *students = NULL;
}

//Temp
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

//Sort students by ID
void sortID(student **students, int size)
{
    bool swapped;
    for (int i = 0; i < size - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if ((*students)[j].id > (*students)[j + 1].id)
            {
                swap((*students)[j], (*students)[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
        {
            break;
        }
    }
}

//Sort students by Last Name
void sortLast(student **students, int size)
{
    bool swapped;
    for (int i = 0; i < size - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if ((*students)[j].last > (*students)[j + 1].last)
            {
                swap((*students)[j], (*students)[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
        {
            break;
        }
    }
}

//Count distinct majors
int majors(student **students, int size)
{
    int count = 1;

    // Pick all elements one by one
    for (int i = 1; i < size; i++)
    {
        int j = 0;
        for (j = 0; j < i; j++)
            if ((*students)[i].major == (*students)[j].major)
                break;

        // If not printed earlier, then print it
        if (i == j)
            count++;
    }
    return count;
}

//Print sorted array
void printArray(student *students, int size, ofstream &MyFile)
{
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        MyFile << students[i].id << " " << endl;
        MyFile << students[i].name << " " << endl;
        MyFile << students[i].last << " " << endl;
        MyFile << students[i].major << " " << endl;
        MyFile << " " << endl;
    }
}
