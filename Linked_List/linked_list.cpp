#include "linked_list.h"
#include <iostream>
#include <string>

using std::cout, std::endl, std::string, std::ostream;

void MyList::add(const std::string& name, int score) {
    MyNode* newNode = new MyNode(name, score);
    newNode->prev = this->_tail;
    if(!this->empty()) {
        this->_tail->next = newNode;
    }
    else {
        this->_head = newNode;
    }
    this->_tail = newNode;
    ++this->_size;    
}

void MyList::clear() {
    
    if(this->empty()) {
        return;
    }
    MyNode* current = this->head()->next;
    while(head() != NULL) {
        MyNode* current = this->head()->next;
        delete this->head();
        this->_head = current;
    }
    this->_size = 0;
    }

/*bool MyList::remove(const std::string& name) {
    // TODO(student)
    return false;
}*/

bool MyList::insert(const std::string& name, int score, size_t index) {
    // TODO(student)
    return false;
}

MyList::MyList()
  : _size(0), _head(nullptr), _tail(nullptr) { }

MyList::~MyList() {
    clear();
}

size_t MyList::size() const {
    return _size;
}

bool MyList::empty() const {
    return _head == nullptr;
}

MyNode* MyList::head() const {
    return _head;
}

ostream& operator<<(ostream& os, const MyList& myList) {
    MyNode* _current = myList.head();
    if (_current == nullptr) {
        os << "<empty>" << endl;
        return os;
    }

    os << "[ " << _current->name << ", " << _current->score << " ]";
    _current = _current->next;
    while (_current != nullptr) {
        os << " --> [ " << _current->name << ", " << _current->score << " ]";
        _current = _current->next;
    }
    
    return os;
}

MyNode::MyNode(const std::string& name, int score)
    : name{name}, score{score}, next{nullptr}, prev{nullptr} {}
