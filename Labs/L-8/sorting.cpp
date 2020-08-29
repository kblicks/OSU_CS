#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int check_int_input()
{
    cin.clear();
    string input_str;
    int input;
    getline(cin, input_str);

    while (cin.fail() || cin.eof() || input_str.find_first_not_of("0123456789") != string::npos)
    {
        if (input_str.find_first_not_of("0123456789") == string::npos)
        {
            cin.clear();
            cin.ignore(256, '\n');
        }

        cout << " Re-Enter a valid number" << endl;
        getline(cin, input_str);
    }

    input = atoi(input_str.c_str());
    return input;
}

void display(int **array, int size)
{
    cout << "Array values: " << endl;
    for (int j = 0; j < size; j++)
    {

        cout << (*array)[j] << " ";
    }
    cout << endl;
}

void merge(int **array, int left, int m, int right)
{
    int i, j, k;
    int n1 = m - left + 1;
    int n2 = right - m;
    cout << "n2 is " << n2 << endl;
    //temp arrays
    int L[n1], R[n2];
    //  cout << "gcop" << endl;
    //Put data into temp arrays
    for (i = 0; i < n1; i++)
    {
        L[i] = (*array)[left + i];
    }
    // cout << "copy2" << endl;
    cout << m + 1 + 0 << endl;

    for (j = 0; j < n2; j++)
    {
        R[j] = *(array)[m + 1 + j];
    }
    //cout << "going to merg" << endl;
    //merging
    i = 0;    // Initial index of first subarray
    j = 0;    // Initial index of second subarray
    k = left; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            (*array)[k] = L[i];
            i++;
        }
        else
        {
            (*array)[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1)
    {
        (*array)[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2)
    {
        (*array)[k] = R[j];
        j++;
        k++;
    }
}

void mergesort(int **array, int left, int right)
{
    cout << "left " << left << endl;
    cout << "right " << right << endl;

    if (left < right)
    {
        int m = left + (right - 1) / 2;

        //Sort first and second halves
        mergesort(array, left, m);
        mergesort(array, m + 1, right);

        merge(array, left, m, right);
    }
}

void copy(int **array, int size)
{

    //create the copy array
    int *copy = new int[size];

    for (int i = 0; i < size; i++)
    {
        copy[i] = (*array)[i];
    }
    cout << "copied array is" << endl;
    display(&copy, size);

    mergesort(&copy, 0, size - 1);

    cout << "Sorted array is" << endl;
    display(&copy, size);
}

int main(int argc, char const *argv[])
{
    int size = 0;
    bool accepted = false;

    while (accepted == false)
    {
        cout << "How long would you like the array to be?" << endl;
        size = check_int_input();

        if (size <= 0)
        {
            cout << "The size must be greater than 0" << endl;
            accepted = false;
        }
        else if (size > 20)
        {
            cout << "The size cannot be larger than 20" << endl;
            accepted = false;
        }
        else
        {
            accepted = true;
        }
    }

    //Dynamic array
    int *array = new int[size];

    //Initialize time
    srand(time(NULL));
    //populate array
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 100;
    }
    //print out the array
    display(&array, size);

    //Create a copy of the array
    copy(&array, size);
}