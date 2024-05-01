#include "burgerQueue.h"

burgerQueue::Node::Node(const int& n_val) {

    val = n_val;
    next = nullptr;
}

burgerQueue::burgerQueue(std::map<int, std::string>& i_map) {

    ingredient_map = i_map;
    front = nullptr;
}

burgerQueue::~burgerQueue() {

    if(!empty()){
        Node* it = front;
        while(it){
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
    }
    else{
        Node* temp = front;
        while(temp->next){
            temp = temp->next;
        }
        temp->next = n_item;
    }
}

void burgerQueue::pop() {

    if(!empty()){
        Node* temp = front;
        front = front->next;
        delete temp;
    }
}

bool burgerQueue::empty() const {

    return front == nullptr;
}

void burgerQueue::scroll_to_next() {

    srand(time(nullptr));
    int rand_ingredient = rand() % 6 + 2;
    pop();
    push(rand_ingredient);
}