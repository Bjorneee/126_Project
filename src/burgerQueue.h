#ifndef BURGERQUEUE_H
#define BURGERQUEUE_H

#include <map>
#include <string>

class burgerQueue {

    struct Node{

        int val;
        Node* next;
        Node* prev;

        Node(const int& n_val);

    };

    std::map<int, std::string> ingredient_map;

    Node* front;
    Node* back;

    void push(const int val);
    void pop();
    bool empty() const;

public:

    burgerQueue(std::map<int, std::string>& i_map);

    ~burgerQueue();

    void display() const;

    void scroll_to_next();

    void scroll_to_prev();

};

#endif //BURGERQUEUE_H