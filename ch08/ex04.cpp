#include <algorithm>
#include <iostream>
#include <istream>
#include <map>
#include <string>
#include <vector>

#include "../ch07/split.h"

using namespace std;

string p2s(pair<string, vector<int> > p) {
    string s;
    s.append(p.first + " occurs on line(s): ");
    vector<int>::const_iterator line_it = p.second.begin();
    s.append(to_string(*line_it++));

    while (line_it != p.second.end()) {
        s.append(string(", "));
        s.append(to_string(*line_it++));
    }
    return s;
}

template <class Out>
Out xref(istream& in, Out o, vector<string> find_words(const string&) = split)
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
    // not sure how to fill in iterator directly for a map, so we're copying the map over
    copy(ret.begin(), ret.end(), o);
    return o;
}

// p128
int main() {
    map<string, vector<int> > ret;

    // http://en.cppreference.com/w/cpp/iterator/inserter
    xref(cin, inserter(ret, ret.end()));

    cout << "Output to map:" << endl;
    for (map<string, vector<int> >::const_iterator it = ret.begin();
         it != ret.end(); ++it) {
        cout << it->first << " occurs on line(s): ";
        vector<int>::const_iterator line_it = it->second.begin();
        cout << *line_it++;

        while (line_it != it->second.end())
            cout << ", " << *line_it++;

        cout << endl;
    }

    cout << endl << "Output to stdout:" << endl;
    transform(ret.begin(), ret.end(), ostream_iterator<string>(cout, "\n"), p2s);

    return 0;
}
