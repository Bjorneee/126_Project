#include "burger.h"
//using namespace std;
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

    ifstream ifs;

    stack<int> temp = items;
    while(!temp.empty()){
        
        ifs.open("..\\asciiburger.txt");
        if(ifs.fail()){
            std::cout << "\nFile open error." << std::endl;
            exit(-1);
        }

        string input;

        do{
            getline(ifs, input, '\n');
        } while(input != ingredient_map[temp.top()] && !ifs.eof());

        getline(ifs, input, '$');

        std::cout << input << std::endl;;
        temp.pop();
        ifs.close();
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
