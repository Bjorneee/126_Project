#include <iostream>
#include <stdlib.h>
#include <map>
#include "burger.h"
#include "burger.cpp" //leave this here or my compiler breaks
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

    //system("cls"); // Clear terminal for every new game. Buggy in vscode terminal. Works when you run the .exe
    cout << "Playing the game\n"<< endl;
    // Functionality for playing the game
    
    srand(time(nullptr));
    int random_burgersize = rand() % 10 + 1;
    Burger order(random_burgersize);

    order.display(ingredients);

}

//temp calls
void newGame() {

    //system("cls");

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
        cout << "2. New Game\n";//should adjust the game idk (not sure if needed)
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Process user choice
        switch (choice) {
            case 1:
                playGame();
                break;
            case 2:
                newGame();
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