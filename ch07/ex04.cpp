#include <iostream>
#include <istream>
#include <map>
#include <string>
#include <vector>

#include "split.h"

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::map;
using std::string;
using std::to_string;
using std::vector;

map<string, vector<int> > xref(istream& in,
                               vector<string> find_words(const string&) = split)
{
    string line;
    int line_number = 0;
    map<string, vector<int> > ret;

    while (getline(in, line)) {
        ++line_number;
        vector<string> words = find_words(line);
        map<string, bool> seen; // just used as a set (bool not needed)
        for (vector<string>::const_iterator it = words.begin();
             it != words.end(); ++it) {
            if (seen.find(*it) != seen.end())
                continue;
            ret[*it].push_back(line_number);
            seen[*it] = true;
        }
    }
    return ret;
}

// p128
int main() {
    map<string, vector<int> > ret = xref(cin);

    for (map<string, vector<int> >::const_iterator it = ret.begin();
         it != ret.end(); ++it) {
        cout << it->first << " occurs on line(s): " << endl;
        vector<int>::const_iterator line_it = it->second.begin();
        static const string::size_type LINE_LEN = 80;
        string::size_type curr_len = to_string(*line_it).size();
        cout << *line_it++;

        while (line_it != it->second.end()) {
            cout << ",";
            curr_len++;
            string::size_type len = to_string(*line_it).size();
            if (curr_len + len + 2 > LINE_LEN) { // +1 for comma +1 for space
                cout << endl;
                curr_len = len;
                cout << *line_it++;
            } else {
                curr_len += len;
                cout << " " << *line_it++;
            }
        }
        cout << endl;
    }

    return 0;
}
