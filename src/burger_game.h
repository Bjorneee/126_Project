#ifndef BURGER_GAME_H
#define BURGER_GAME_H
#include <unordered_map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
using namespace std;
class game_state
{
private:
    unordered_map<string, int> scores;
    int user_score;
    string user_name;



public:
    void write_score(int score);
    int find_highest_score();
    void saveScores(const unordered_map<string, int> &scores, const string &filename);
    int getScore(const string &playerName, const string &filename);
    void set_username(string username);
    void set_user_score(int userscore);

};

#endif