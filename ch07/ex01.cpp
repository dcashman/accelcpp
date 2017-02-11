#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;

int main() {
    string s;
    map<string, int> counters; // store each word and an associated counter
    map<int, vector<string> >rev_counters; // reverse mapping

    while (cin >> s)
        ++counters[s];

    for (map<string, int>::const_iterator it = counters.begin();
         it != counters.end(); ++it) {
        rev_counters[it->second].push_back(it->first);
    }

    // http://stackoverflow.com/questions/7648756/is-the-order-of-iterating-through-stdmap-known-and-guaranteed-by-the-standard
    for(map<int, vector<string> >::const_iterator it = rev_counters.begin();
        it != rev_counters.end(); ++it) {
        cout << "Words with count: " << it->first << endl;
        for (auto& s : it->second)
            cout << s << endl;
    }

    return 0;
}
