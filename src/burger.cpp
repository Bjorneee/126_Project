#include "burger.h"
#include <cstdlib> 
#include <iostream>
#include <ctime>   
#include <map>
using namespace std;
Burger::Burger(int size) {
    // Initialize random seed
    srand(time(nullptr));
    items.push_back(0);
    for (int i = 0; i < size-2; ++i) {
        items.push_back(rand() % 10); //check if the raindom is correct
    }
    items.push_back(0);
}

void Burger::display() {
    map<int, string> ingredients = {
    {0, "Bun"},
    {1, "Tomato"},
    {2, "Onion"},
    {3, "Cheese"},
    {4, "Bacon"},
    {5, "Pickles"},
    {6, "Ketchup"},
    {7, "Mustard"},
    {8, "Patty"},
    {9, "Lettuce"}
};
    cout << "Burger Items:"<<endl;
    for (int i = 0; i < items.size(); ++i) {
        cout << ingredients[items[i]] << endl;
    }
    cout << endl;
}