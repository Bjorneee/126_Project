#include <iostream>
#include <stdlib.h>
#include "burger.h"

using namespace std;

//temp calls
void playGame() {

    //system("cls"); // Clear terminal for every new game. Buggy in vscode terminal. Works when you run the .exe

    cout << "Playing the game\n"<< endl;

    // Functionality for playing the game
    srand(time(nullptr));

    int random = rand() % 10 + 1;
    Burger order(random);

    order.display();

}

//temp calls
void newGame() {

    //system("cls");

    // Functionality for starting a new game
    cout << "Starting a new game...\n";
}

int main() {
    int choice;
    do {
        // Display menu options
        cout << "\n=== Game Menu ===\n";
        cout << "1. Play Game\n";
        cout << "2. New Game\n";
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