#include "SimpleList.hpp"
#include<iostream>
#include<sstream>
#include <string>

using namespace std;

list::list() {
    head = NULL;
    _size = 0;
}

list::list(const list& other) {
    head = NULL;
    _size = 0;
    node* otherp = other.head;
    for (int i = 0; i < other._size; i++) {
        insert(i, otherp->data);
        otherp = otherp->next;
    }
}

list& list::operator=(const list& other) {
    clear();
    if (other._size != 0) {
        node* otherp = other.head;
        for (int i = 0; i < other._size; i++) {
            insert(i, otherp->data);
            otherp = otherp->next;
        }
    }
    return *this;
}

list::~list() {
    clear();
}

bool list::empty(void) const {
    return _size;
}

int list::size(void) const {
    return _size;
}


std::string list::toString(void) const {
    stringstream st;
    node* temp = head;
    while (temp != NULL) {
        st << temp->data;  // some problems
        st << "->";
        temp = temp->next;
    }
    st << "NULL";
    return st.str();
}

void list::insert(int position, const int& data) {
    if (position > _size) return;
    if (position == 0) {
        if (head == NULL) {
            head = new node(data, NULL);
        } else {
             node* NewNode = new node(data, head);
             head = NewNode;
        }
        _size++;
        return;
    }
    node* temp = head;
    for (int i = 0; i < position - 1; i++) {
         temp = temp->next;
    }
    node* NewNode = new node;
    NewNode->data = data;
    NewNode->next = temp->next;
    temp->next = NewNode;
    _size++;
}

void list::erase(int position) {
    if (_size == 0 || position > _size - 1) return;

    node* temp = head;
    if (position == 0) {
        head = head->next;
        delete temp;
        temp = NULL;
        _size--;
        return;
    }
    for (int i = 0; i < position - 1; i++) {
         temp = temp->next;
    }
    node* targetnode = temp->next;
    temp->next = targetnode->next;
    delete targetnode;
    targetnode = NULL;
    _size--;
    return;
}

list& list::sort(void) {
    if (head == NULL) return *this;
    node* temp = head;
    int* a = new int[_size];
    for (int i = 0; i < _size; i++) {
        *(a + i) = temp->data;
        temp = temp->next;
    }
    for (int i = 0; i < _size - 1; i++) {
        for (int j = i + 1; j < _size; j++) {
            if (*(a + i) > *(a + j)) {
                int t =  *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = t;
            }
        }
    }
    temp = head;
    for (int i = 0; i < _size; i++) {
        temp->data = *(a + i);
        temp = temp->next;
    }
    delete []a;
    return *this;
}
