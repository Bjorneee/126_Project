#include "burgerQueue.h"

burgerQueue::Node::Node(const int& n_val) {

    val = n_val;
    next = nullptr;
    prev = nullptr;
}

burgerQueue::burgerQueue(std::map<int, std::string>& i_map) {

    ingredient_map = i_map;

    front = nullptr;
    back = nullptr;
}

burgerQueue::~burgerQueue() {

    if(!empty){
        Node* it = front;
        while(it != back){
            Node* temp = it->next;
            delete it;
            it = temp;
        }
    }   
}

void burgerQueue::push(const int n_val) {

    Node* n_item = new Node(n_val);
    if(!front){
        front = n_item;
        back = front;
    }
    else{
        back->next = n_item;
        n_item->prev = back;
        n_item->next = front;
        back = back->next;
        front->prev = back;
    }
}

void burgerQueue::pop() {

    back = back->prev;
}