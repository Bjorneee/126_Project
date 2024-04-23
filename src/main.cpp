#include <iostream>
#include <set>
#include <map>
// #include "burger.h"
#include "burger.cpp"
// #include "\lib\burger.h"
using namespace std;
//temp calls
void playGame() {
    // Functionality for playing the game
    cout << "Playing the game\n"<<endl;
    srand(time(nullptr));
    int random = rand() % 10 + 1;
    Burger burger(random);
    burger.display();

}
//temp calls
void newGame() {
    // Functionality for starting a new game
    cout << "Starting a new game...\n";
}

int main() {
    int choice;
    do {
        // Display menu options
        cout << "=== Game Menu ===\n";
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