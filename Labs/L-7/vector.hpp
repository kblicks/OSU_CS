#include <stdlib.h>
#include <iostream>

using std::cout;
using std::endl;
//using std::out_of_range;
template <class T>
class vector {
private:
    T *v;
    int s;
public:
    vector() {
        s=0;
        v=NULL;
    }

    vector(vector &other) {
        s = other.s;
        v = new T[s];
    }

    void operator = (vector<T> &other) {
        s = other.s;
        v = new T[s];
    }

    ~vector() {
        delete[] v;
    }

    int size() {
        return s;
    }

    void push_back(T ele) {
        T *temp;
        temp = new T[++s];
        for (int i=0; i<s-1; i++)
            temp[i]=v[i];

        delete[] v;
        v=temp;
        v[s-1]=ele;
    }

    T operator[](int) {

    } //Only perform address arithmetic 
/*
    T at(int element) {

        try {
            element < s;
        }
        catch (const std::out_of_range& oor) {
            std::cerr << "out of range error" << oor.what() << '\n';
        }

        return v[element];
    } //Check to make sure not out of bounds
    */
};