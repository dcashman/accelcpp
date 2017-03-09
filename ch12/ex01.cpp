#include <iostream>

#include "Str.h"

using namespace std;

int main() {
    Str s1, s2;
    cin >> s1;
    cin >> s2;
    if (s1 == s2)
        cout << "Two strings are equal" << endl;
    if (s1 != s2)
        cout << "Two strings are not equal" << endl;
    s1 += " " + s2;
    cout << s1 << " test!" << endl;
    return 0;
}
