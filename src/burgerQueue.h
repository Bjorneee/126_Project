#ifndef BURGERQUEUE_H
#define BURGERQUEUE_H

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>

class burgerQueue {

    struct Node{

        int val;
        Node* next;

        Node(const int& n_val);

    };

    std::map<int, std::string> ingredient_map;

    Node* front;

    void push(const int val);
    void pop();
    bool empty() const;

public:

    burgerQueue(std::map<int, std::string>& i_map);

    ~burgerQueue();

    void display(int index) const;

    void scroll_to_next();

    void fill(const int n);

    int getFront() const;

};

#endif //BURGERQUEUE_H