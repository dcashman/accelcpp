#include <string>
#include "String_list.h"

using namespace std;

String_list::String_list() : head(NULL), tail(NULL), size(0) { }

void String_list::push_back(string s) {
    Node *n = new Node(&s);
    if (tail == NULL) {
        tail = n;
        head = n;
    } else {
        tail->next = n;
        n->prev = tail;
        tail = n;
    }
    size++;
}

string String_list::pop_back() {
    string ret;
    if (tail == NULL) {
        throw domain_error("Cannot pop_back() on empty String list!");
    } else if (head == tail) {
        ret = *tail->s;
        delete tail;
        tail = NULL;
        head = NULL;
    } else {
        ret = *tail->s;
        tail->prev->next = NULL;
        Node *tmp = tail->prev;
        delete tail;
        tail = tmp;
    }
    size--;
    return ret;
}

String_list::iterator String_list::begin() {
    return iterator(head);
}

String_list::iterator String_list::rbegin() {
    return iterator(tail);
}

String_list::iterator String_list::end() {
    return iterator(tail + 1);
}

String_list::iterator String_list::rend() {
    return iterator(head - 1);
}

// Node methods
String_list::Node::Node() { };

String_list::Node::Node(string *s) : s(s), next(NULL), prev(NULL) { }

// iterator methods
String_list::iterator::iterator(Node *n) : n(n) { }

string String_list::iterator::operator*() const {
    return *n->s;
}
