#ifndef BURGUER_UI_H
#define BURGUER_UI_H

#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <map>
#include "burger.h"
#include "burgerQueue.h"

using namespace std;

const string ascii_burger_txt = "assets/asciiburger.txt";
const char ascii_burger_delim = '$';

void safe_open(const string& filename, ifstream& ifs);

/*

if ref stack > usr stack
    - print ref stack until ref stack == usr stack
if ref stack == usr stack
    - print 1 ref stack line until delim
    - print 1 usr stack line until \n delim
if ref stack < usr stack
    - print blank space then print 1 usr stack line until \n delim

*/
void display_burgers(const Burger& reference_burger, const Burger& user_burger, const map<int, string>& ingredient_map);

#endif //BURGER_UI_H