#include "burger_game.h"
using namespace std;


void game_state::write_score(int score){//this both works indepndently and should work find just depends where you want to call it
    ofstream outputFile("scores.txt", ios::app);//it currently creates a new scores.txt within the src I'll see if we can move it 
    if (!outputFile.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }
    outputFile <<score<< ",";
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
            file << entry.first << " " << entry.second << endl;
        }
        file.close();
        cout << "Scores saved to " << filename << " successfully." << endl;
    } else {
        cerr << "Unable to open file: " << filename << endl;
    }
}

int game_state::getScore(const unordered_map<string, int>& scores, const string& playerName) {
    auto it = scores.find(playerName);
    if (it != scores.end()) {
        return it->second;
    } else {
        cerr << "Player " << playerName << " not found!" << endl;
        return -1; // Return a negative value to indicate player not found
    }
}