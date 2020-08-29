
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

#include "student_db.h"

using namespace std;

int main(int argc, char *argv[])
{

    ifstream input(argv[1]);

    if (argc != 2)
    {
        cout << "Please enter file into the argument" << endl;
        return 1;
    }

    if (!input)
    {
        cout << "Failed to open the file" << endl;
        return 1;
    }
    //Create and open a text file
    string filename;
    cout << "What would you like to name your file?" << endl;
    cin >> filename;

    ofstream MyFile(filename.c_str());
    //Check to see if file opened
    if (!MyFile)
    {
        cout << "Failed to create and open the new file" << endl;
        return 1;
    }

    student *students;

    //Get the first line of the text and set it to int
    string number;
    getline(input, number);
    int size = atoi(number.c_str());

    //Create the database
    students = create_student_db(size);
    //Populate database from input file
    populate_student_db_info(students, size, input);

    //Sort students by ID and write to file
    sortID(&students, size);
    MyFile << "------------------------" << endl;
    MyFile << "STUDENTS BY ID NUMBER" << endl;
    MyFile << "------------------------" << endl;
    printArray(students, size, MyFile);
    //Sort students by Last Name
    sortLast(&students, size);
    MyFile << "------------------------" << endl;
    MyFile << "STUDENTS BY LAST NAME" << endl;
    MyFile << "------------------------" << endl;
    printArray(students, size, MyFile);

    //Find the number of unique majors
    int unique = majors(&students, size);
    MyFile << "------------------------" << endl;
    MyFile << "NUMBER OF UNIQUE MAJORS" << endl;
    MyFile << "------------------------" << endl;
    MyFile << unique << endl;
    //Delete the array
    delete_student_db_info(&students, size);

    //Close the files
    input.close();
    MyFile.close();
}