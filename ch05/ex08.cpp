#include <cctype>
#include <iostream>
#include <list>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::isupper;
using std::list;
using std::string;

int main() {
    list<string> words;

    string s;
    while(cin >> s)
        words.push_back(s);

    list<string> upcase;
    for (list<string>::const_iterator s = words.begin(); s != words.end(); s++) {
        for (const auto& c: *s) {
            if (isupper(c)) {
                upcase.push_back(*s);
                words.erase(s);
                break;
            }
        }
    }

    for (const auto& s : words)
        cout << s << endl;

    for (const auto& s : upcase)
        cout << s << endl;

    return 0;
}
