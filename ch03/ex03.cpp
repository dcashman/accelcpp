#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

int main()
{
    cout << "Please enter your words: ";
    string x;
    vector<string> words;
    while (cin >> x)
        words.push_back(x);

    typedef vector<string>::size_type vec_sz;
    vec_sz size = words.size();
    if (size == 0) {
        cout << endl << "Didn't get any words.  Please try again." << endl;
        return 1;
    }

    // most efficient way to answer this is to use a hash map, but we'll ignore
    // that as not yet having been introduced in-book and use sort() instead.
    sort(words.begin(), words.end());

    size_t count = 0;
    string tmp = *words.begin();
    for (auto s : words) {
        if (s.compare(tmp)) {
            cout << tmp << ": " << count << endl;
            tmp = s;
            count = 1;
        } else {
            count++;
        }
    }

    return 0;
}
