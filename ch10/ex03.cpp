#include <iostream>
#include <list>
#include <string>

#include "String_list.h"

using namespace std;

int main() {
    cout << "Creating String_list, which could easily be templated..." << endl;
    String_list sl;
    sl.push_back("Hello");
    sl.push_back("World");
    string s = sl.pop_back();
    cout << "popped: " << s << endl;
    String_list::iterator i = sl.begin();
    cout << "iterator begin(): " << *i << endl;
    *i = "changed";
    cout << "iterator begin() after assignment: " << *i << endl;
    return 0;
}
