#ifndef BURGER_H
#define BURGER_H

using namespace std;

//#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stack>
#include <map>
#include <string>

class Burger {

    stack<int> items;
    map<int, string> ingredients;

    void initialize_ingredients();

public:

    Burger(int size);

    Burger(stack<int>& burgerStack);
    
    void display();

    friend bool operator==(const Burger& comp1, const Burger& comp2);

};

#endif //BURGER_H
