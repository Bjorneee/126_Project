#include <iostream>
#include <stdlib.h>
#include <map>
#include <fstream>
#include <sstream>
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
    int random_burgersize = rand() % 10 + 1;//How are we going to save score give me the var name some where so I know
    Burger order(random_burgersize);

    order.display(ingredients);
    //call game inputs
}

//temp calls
void newGame() {

    //system("cls");

    // Functionality for starting a new game
    cout << "Starting a new game...\n";
}
void write_score(int score){//this both works indepndently and should work find just depends where you want to call it
    ofstream outputFile("scores.txt", ios::app);//it currently creates a new scores.txt within the src I'll see if we can move it 
    if (!outputFile.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }
    outputFile <<score<< ",";
    outputFile.close();
}

int find_highest_score() {
    ifstream inputFile("scores.txt");
    if (!inputFile.is_open()) {
        cout << "Error opening file!" << endl;
        return -1; // Return -1 to indicate error
    }

    int highest_score = -1;
    string line;
    while (getline(inputFile, line)) {
        stringstream ss(line);
        string score_str;
        while (getline(ss, score_str, ',')) {
            int score = stoi(score_str);
            highest_score = max(highest_score, score);
        }
    }
    inputFile.close();
    return highest_score;
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