#ifndef BURGER_H
#define BURGER_H

using namespace std;

//#include <vector>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <stack>


class Burger {

    stack<int> items;//burger items
    stack<int> user_burger;
    map<int, string> ingredients;


    void initialize_ingredients();

public:

    Burger(int size);

    Burger(stack<int>& burgerStack);

    void display(map<int, string>& ingredients);
    
    friend bool operator==(const Burger& comp1, const Burger& comp2);
    
    bool order_Issame() const;

};

#endif //BURGER_H
