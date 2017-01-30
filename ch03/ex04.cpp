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

    string smallest, largest;
    string::size_type min = largest.max_size(), max = 0;
    for (auto s : words) {
        string::size_type sz = s.size();
        if (sz < min) {
            smallest = s;
            min = sz;
        }
        if (sz > max) {
            largest = s;
            max = sz;
        }
    }

    cout << "Smallest string: " << smallest << " size: " << min << endl;
    cout << "Largest string: " << largest << " size: " << max << endl;
    return 0;
}
