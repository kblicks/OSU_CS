#include <iostream>
using namespace std;

#ifndef STUDENTDB_H
#define STUDENTDB_H

struct student
{
    int id;
    string name;
    string last;
    string major;
};

#endif

//Function definitions
student *create_student_db(int size);
void populate_student_db_info(student *students, int size, ifstream &input);
void delete_student_db_info(student **students, int size);
void swap(int *xp, int *yp);
void sortID(student **students, int size);
void sortLast(student **students, int size);
int majors(student **students, int size);
void printArray(student *students, int size, ofstream &MyFile);
