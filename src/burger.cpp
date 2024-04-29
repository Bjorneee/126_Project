#include "burger.h"

Burger::Burger(int size) {

    // Initialize random seed
    srand(time(nullptr));

    items.push(0); // All burgers start with a bottom bun
    for (int i = 0; i < size; i++) {
        items.push((rand() % 6) + 2); // Push random ingredient ids into the stack
    }
    items.push(1); // All burgers end with a top bun
}

Burger::Burger(stack<int>& burgerStack) {

    items.push(0);
    while(!burgerStack.empty()){
        items.push(burgerStack.top());
    }
    items.push(1);

}

void Burger::display(map<int, string>& ingredient_map){

    stack<int> temp = items;
    while(!temp.empty()){
        std::cout << ingredient_map[temp.top()] << std::endl;
        temp.pop();
    }
}

bool operator==(const Burger& comp1, const Burger& comp2) {

    return comp1.items == comp2.items;
}