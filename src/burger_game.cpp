#include "burger_game.h"
using namespace std;


void game_state::write_score(int score){//this both works indepndently and should work find just depends where you want to call it
    ofstream outputFile("scores.txt", ios::app);//it currently creates a new scores.txt within the src I'll see if we can move it 
    if (!outputFile.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }
    outputFile <<score<< ",";//deliminator
    outputFile.close();
}

int game_state::game_state::find_highest_score() {
    ifstream inputFile("..\\scores.txt");
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


/*HOW TO USE
SAVE SCORE

need to create a unordered_map
unordered_map<string, int> scores;

saveScores(scores, "save_score.txt");

GET SCORE
string playerName = "Player2";
int playerScore = getScore(scores, playerName);
if (playerScore != -1) {
    cout << "Score of " << playerName << ": " << playerScore << endl;
}

*/
void game_state::saveScores(const unordered_map<string, int>& scores, const string& filename) {
    ofstream file;
    file.open(filename);
    if(file.fail()) {
        file.open("..\\assets\\scores.txt");
        if(file.fail()){
            cerr << "Could not save scores. Unable to open file: " << filename << endl;
            exit(-1);
        }
    } 
    else {
        for (const auto& entry : scores) {
            file << entry.first << "," << entry.second << endl;//deliminator
        }
        file.close();
        cout << "Scores saved to " << filename << " successfully." << endl;
    }
}

int game_state::getScore(const string& filename, const string& playerName) {
    ifstream file;
    file.open(filename);
    if (file.fail()) {
        file.open("..\\assets\\scores.txt");
        if(file.fail()){
            cerr << "Coult not get score. Error opening file: " << filename << endl;
            exit(-1);
        }
    }
    string line;
    while (getline(file, line)) {
        size_t pos = line.find(',');
        if (pos != string::npos) {
            string name = line.substr(0, pos);
            if (name == playerName) {
                int score = stoi(line.substr(pos + 1));
                file.close();
                return score;
            }
        }
    }
    cerr << "Player " << playerName << " not found in file: " << filename << endl;
    file.close();
    return -1; 
}


/*
IT will be saved as player, score
    USE CASE

    string filename = "save_score.txt";
    string playerName = "Player3"; // Example player name to search for

    int score = getScoreFromFile(filename, playerName);
    */

//set function to just set the user name
void game_state::set_username(string username){
    user_name = username;
}

void game_state::set_user_score(int userscore){
    user_score = userscore;
}

void game_state::run_game(map<int, string>& ingredient_map, unordered_map<string, int>& score_sheet) {

    srand(time(nullptr));
    int random_burgersize = rand() % 10 + 1;

    Burger order(random_burgersize);
    Burger user_burger(0);
    
    burgerQueue bq(ingredient_map);
    bq.fill(3);

    int user_input = 1;
    while(user_input){

        system("cls"); // Clear terminal for every new game. Buggy in vscode terminal. Works when you run the .exe

        cout << user_name << endl;
        cout << user_score << endl;

        cout << "\nBurger to make:\n" << endl;
        order.display(ingredient_map);
        //call game inputs    

        cout << "Your burger:\n" << endl;
        user_burger.display(ingredient_map);

        //display_burgers(order, user_burger, ingredient_map);

        for(int i = 0; i < 3; i++){
            bq.display(i);
            cout << " | ";
        }
        cout << endl;

        cout << "\n1) Stack leftmost item from queue." << endl;
        cout << "2) Scroll" << endl;
        cout << "\n0) Finish" << endl;
        cout << "\nEnter choice: ";
        cin >> user_input;

        switch(user_input){
            case 0:
                if(user_burger == order){
                    cout << "\nYou Win!\n" << endl;
                    user_score++;
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

    score_sheet[user_name] = user_score;
    saveScores(score_sheet, "assets\\scores.txt");

}