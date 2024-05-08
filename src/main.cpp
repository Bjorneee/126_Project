#include <iostream>
#include "burger_ui.h"
#include "burger_game.h"

using namespace std;

const string score_file = "assets\\scores.txt";

void initialize(map<int, string>& i_map, unordered_map<string, int>& s_map);
void new_game(map<int, string>& i_map, unordered_map<string, int>& s_map);
void load_game(map<int, string>& i_map, unordered_map<string, int>& s_map);
void load_scores(unordered_map<string, int>& s_map);

int main() {

    map<int, string> ingredients;
    unordered_map<string, int> scores;

    initialize(ingredients, scores);

    int choice;
    do {
        // Display menu options
        cout << "\n=== Game Menu ===\n" << endl;
        cout << "1) New Game\n";
        cout << "2) Load Game\n";

        cout << "0) Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        fflush(stdin);

        // Process user choice
        switch (choice) {
            case 0:
                cout << "\nExiting the game..." << endl;
                break;
            case 1:
                new_game(ingredients, scores);
                break;
            case 2:
                load_game(ingredients, scores);
                break;
            default:
                cout << "\nInvalid choice. Please try again.\n";
        }
    } while(choice);

    return 0;
}

// initialize game assets
void initialize(map<int, string>& i_map, unordered_map<string, int>& s_map) {

    i_map = { {0, "bottom_bun"},
              {1, "top_bun"},
              {2, "patty"},
              {3, "cheese"},
              {4, "lettuce"},
              {5, "onion"},
              {6, "pickle"},
              {7, "tomato"}};

    load_scores(s_map);
}

void new_game(map<int, string>& i_map, unordered_map<string, int>& s_map) {

    game_state new_game;

    string username;
    cout << "\nEnter username: ";
    //getline(cin, username); // clear cache trying using fflush
    getline(cin, username);
    
    new_game.set_user_score(0);
    new_game.set_username(username);

    new_game.run_game(i_map, s_map);
    
}

void load_game(map<int, string>& i_map, unordered_map<string, int>& s_map) {

    if(s_map.empty()){
        cout << "\nNo saved games." << endl;
        return;
    }

    game_state load_game;

    string username;
    cout << "\nEnter username: ";
    getline(cin, username);
    getline(cin, username);

    cout << "\nUser score: " << load_game.getScore(score_file, username) << endl;
    //int highest_score = load_game.find_highest_score();
    //cout << "Highest Score: " << highest_score <<endl;
    load_game.set_user_score(load_game.getScore(score_file, username));
    load_game.set_username(username);

    load_game.run_game(i_map, s_map);

}

void load_scores(unordered_map<string, int>& s_map) {

    ifstream ifs;
    ifs.open(score_file);
    if(ifs.fail()){
        ifs.open("..\\assets\\scores.txt");
        if(ifs.fail()){
            cout << "\nUnable to load scores. File open failure." << endl;
            exit(-1);
        }
    }
    string line;
    while(getline(ifs, line)){
        size_t pos = line.find(',');
        if(pos != string::npos){
            string name = line.substr(0, pos);
            int score = stoi(line.substr(pos + 1));
            s_map[name] = score;
        }
    }
    ifs.close();

}