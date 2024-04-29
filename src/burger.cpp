#include "burger.h"
//using namespace std;
Burger::Burger(int size) {

    // Setup ingredients map
    initialize_ingredients();

    // Initialize random seed
    srand(time(nullptr));

    items.push(0); // All burgers start with a bottom bun
    for (int i = 0; i < size; i++) {
        items.push((rand() % 7) + 2); // Push random ingredient ids into the stack
    }
    items.push(1); // All burgers end with a top bun
}

Burger::Burger(stack<int>& burgerStack) {

    initialize_ingredients();

    items.push(0);
    while(!burgerStack.empty()){
        items.push(burgerStack.top());
    }
    items.push(1);

}

// Map ingredients to specific id's.
void Burger::initialize_ingredients() {

    this->ingredients = {

        {0, "bottom_bun"},
        {1, "top_bun"},
        {2, "patty"},
        {3, "cheese"},
        {4, "lettuce"},
        {5, "tomato"},
        {6, "onion"},
        {7, "pickle"},
        {8, "sauce"}

    };
}

void Burger::display() {
    
    // Setup text file with ascii art for each item
    // Go through ids in stack and print each item from ascii art file

    // Temp display code
    stack<int> temp = this->items;
    while(!temp.empty()){
        std::cout << temp.top() << " | " << ingredients[temp.top()] << std::endl;
        temp.pop();
    }
}

bool operator==(const Burger& comp1, const Burger& comp2) {

    return comp1.items == comp2.items;
}

//stack comapre idk if you want to user this
bool Burger:: order_Issame() const {
        stack<int> items_copy = items;
        stack<int> user_burger_copy = user_burger;

        // Compare the sizes of the stacks
        if (items_copy.size() != user_burger_copy.size()) {
            return false; // Stacks are of different sizes
        }
        while (!items_copy.empty()) {
            if (items_copy.top() != user_burger_copy.top()) {
                return false; // Elements at the top of both stacks are different
            }
            items_copy.pop();
            user_burger_copy.pop();
        }

        return true;
};
