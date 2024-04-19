#ifndef BURGER_H
#define BURGER_H
using namespace std;
#include <vector>

class Burger {
private:
    vector<int> items; 

public:
    Burger(int size);
    void display();
};

#endif
