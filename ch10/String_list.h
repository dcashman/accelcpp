#ifndef String_list_H
#define String_list_H

#include <list>
#include <string>

class String_list {

    // nested classes
 private:
    class Node {     // the real list
    public:
        Node();
        Node(std::string *s);

        std::string *s;
        Node *next;
        Node *prev;
    };

 public:
    class iterator {

    public:
        iterator(String_list::Node *n);
        std::string operator*() const;
        /*
        bool operator==();
        iterator& operator++();  // prefix
        iterator operator++(int); // postfix
        iterator& operator--();  // prefix
        iterator operator--(int); // postfix
*/

    private:
        Node *n;
    };

    // our class
 public:
    String_list();
    void push_back(std::string s);
    std::string pop_back();
    iterator begin();
    iterator rbegin();
    iterator end();
    iterator rend();

 private: 
    Node *head;
    Node *tail;
    size_t size;
};

#endif // String_list_H
