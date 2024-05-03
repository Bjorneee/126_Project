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
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& entry : scores) {
            file << entry.first << "," << entry.second << endl;//deliminator
        }
        file.close();
        cout << "Scores saved to " << filename << " successfully." << endl;
    } else {
        cerr << "Unable to open file: " << filename << endl;
    }
}

int game_state::getScore(const string& filename, const string& playerName) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return -1;
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