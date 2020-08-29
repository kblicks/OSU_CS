#include "./vector.hpp"
#include <vector>
#include <iostream>

//We do not want to include either stmt. We wouldn't 
//be able to compare our vector template to the Standard 
//using namespace std;
//using std::vector;
using std::cout;
using std::endl;


int main() {
    vector<int> v;   //Our vector class
    std::vector<int> stdv; //Standard vector

    vector<int> vop; //Overload assignment operator called

    //Compare operation of our vector to std
    v.push_back(23);
    v.push_back(22);
    stdv.push_back(23);

    //Copy Constructor called
    vector<int> vv = v;
    //Assignment overloading
    vop = vv;

    vv.push_back(4);
    vv.push_back(5);


    cout << "Our vector size: " << v.size() << endl;
    cout << "STL vector size: " << stdv.size() << endl;
    cout << "Copy constructor size: " << vv.size() << endl;
    cout << "Overloaded assignment vector size: " << vop.size() << endl;
    //int loc = v.at(1);
    //cout << "loc: " << loc << endl;

    return 0;
}
