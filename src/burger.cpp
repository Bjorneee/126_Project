#include "burger.h"
using namespace std;
Burger::Burger(int size) {

    // Initialize random seed
    srand(time(nullptr));

    items.push(0); // All burgers start with a bottom bun
    for (int i = 0; i < size; i++) {
        items.push((rand() % 6) + 2); // Push random ingredient ids into the stack
    }
    items.push(1); // All burgers end with a top bun
}

void Burger::display(map<int, string>& ingredient_map){

    ifstream ifs;

    stack<int> temp = items;
    while(!temp.empty()){
        
        ifs.open("asciiburger.txt");
        if(ifs.fail()){
            ifs.open("..\\asciiburger.txt");
            if(ifs.fail()){
                std::cout << "\nFile open error." << std::endl;
                exit(-1);
            }
        }

        string input;

        do{
            getline(ifs, input, '\n');
        } while(input != ingredient_map.at(temp.top()) && !ifs.eof());

        getline(ifs, input, '$');

        std::cout << input << std::endl;;
        temp.pop();
        ifs.close();
    }
}

void Burger::stack_item(const int& item) {

    int temp = items.top();
    items.pop();
    items.push(item);
    items.push(temp);
}

bool operator==(const Burger& comp1, const Burger& comp2) {

    return comp1.items == comp2.items;
}