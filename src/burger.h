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
    void display();

};

#endif //BURGER_H
