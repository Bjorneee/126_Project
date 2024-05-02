#include <iostream>
#include <stdlib.h>
#include <map>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include "burger.h"
#include "burgerQueue.h"
//#include "burger.cpp" //leave this here or my compiler breaks
//#include "burgerQueue.cpp"// temp for standard run 
using namespace std;

map<int, string> ingredients;

// initialize game assets
void initialize() {

    ingredients = { {0, "bottom_bun"},
                    {1, "top_bun"},
                    {2, "patty"},
                    {3, "cheese"},
                    {4, "lettuce"},
                    {5, "onion"},
                    {6, "pickle"},
                    {7, "tomato"}};
}

//temp calls
void playGame() {
    
    srand(time(nullptr));
    int random_burgersize = rand() % 10 + 1;//How are we going to save score give me the var name some where so I know
    Burger order(random_burgersize);
    Burger user_burger(0);
    burgerQueue bq(ingredients); // Burger Queue test
    bq.fill(3);

    int user_input = 1;
    while(user_input){

        system("cls"); // Clear terminal for every new game. Buggy in vscode terminal. Works when you run the .exe

        cout << "\nBurger to make:\n" << endl;
        order.display(ingredients);
        //call game inputs    

        cout << "\nYour burger:\n" << endl;
        user_burger.display(ingredients);

        for(int i = 0; i < 3; i++){
            bq.display(i);
            cout << " | ";
        }
        cout << endl; // End Burger Queue test

        cout << "\n1) Stack leftmost item from queue." << endl;
        cout << "2) Scroll" << endl;
        cout << "\n0) Finish" << endl;
        cout << "\nEnter choice: ";
        cin >> user_input;

        switch(user_input){
            case 0:
                if(user_burger == order){
                    cout << "\nYou Win!\n" << endl;
                }
                else{
                    cout << "\nYou Lose.\n" << endl;
                }
                break;
            case 1:
                user_burger.stack_item(bq.getFront());
                bq.scroll_to_next();
                break;
            case 2:
                bq.scroll_to_next();
                break;
            default:
                cout << "\nInvalid Input\n" << endl;
        }

    }
}

//temp calls
void newGame() {

    system("cls");

    // Functionality for starting a new game
    cout << "Starting a new game...\n";
}



int main() {
    initialize();
    int choice;
    do {
        // Display menu options
        cout << "\n=== Game Menu ===\n";
        cout << "1. Play Game\n";
        cout << "2. New Game\n";//load game
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        fflush(stdin);
        // Process user choice
        switch (choice) {
            case 1:
                playGame();
                break;
            case 2:
                newGame();//would change to resume game
                break;
            case 3:
                cout << "Exiting the game.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}