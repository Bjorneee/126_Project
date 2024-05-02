#ifndef BURGER_H
#define BURGER_H

//#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <map>
#include <stack>
#include <string>

using namespace std;

class Burger {

    stack<int> items;//burger items
    map<int, string> ingredients;

public:

    Burger(int size);

    void display(map<int, string>& ingredients);

    void stack_item(const int& item);
    
    friend bool operator==(const Burger& comp1, const Burger& comp2);
    
};

#endif //BURGER_H
