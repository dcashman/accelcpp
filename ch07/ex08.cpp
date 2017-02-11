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
using std::vector;


// p107
bool not_url_char(char c) {
    // characters, in addition to alphanumerics, that can appear in an URL
    static const string url_ch = "~;/?:@=&$-_.+!*'(),";

    // see whether c can appear in a URL and return the negation
    return !(isalnum(c) || find(url_ch.begin(), url_ch.end(), c) != url_ch.end());
}

// p108
string::const_iterator url_beg(string::const_iterator b, string::const_iterator e) {
    static const string sep = "://";

    typedef string::const_iterator iter;

    // i marks where the separator was found
    iter i = b;

    while ((i = search(i, e, sep.begin(), sep.end())) != e) {

        // make sure separator isn't at the beginning or the end of the line
        if (i != b && i + sep.size() != e) {

            // beg marks the beginning of the protocol name
            iter beg = i;
            while (beg != b && isalpha(beg[-1]))
                --beg;

            // is there at least one appropriate character before and after the
            // separator?
            if (beg != i && !not_url_char(i[sep.size()]))
                return beg;
        }

        // the separator we found wasn't part of a URL; advance
        i += sep.size();
    }
    return e;
}

// p107
string::const_iterator url_end(string::const_iterator b, string::const_iterator e) {
    return find_if(b, e, not_url_char);
}

// p106
vector<string> find_urls(const string& s) {
    vector<string> ret;
    typedef string::const_iterator iter;
    iter b = s.begin(), e = s.end();

    // look through the entire input
    while( b != e) {

        // look for one or more letters followed by ://
        b = url_beg(b, e);

        // if found
        if (b != e) {
            // get teh rest of the url
            iter after = url_end(b, e);

            // remember the URL
            ret.push_back(string(b, after));

            // advance b and check for more URLs on this line
            b = after;
        }
    }
    return ret;
}

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
    map<string, vector<int> > ret = xref(cin, find_urls);

    for (map<string, vector<int> >::const_iterator it = ret.begin();
         it != ret.end(); ++it) {
        if (it->second.size() == 1)
            cout << it->first << " occurs on line: ";
        else
            cout << it->first << " occurs on lines: ";

        vector<int>::const_iterator line_it = it->second.begin();
        cout << *line_it++;
        while (line_it != it->second.end())
            cout << ", " << *line_it++;
        cout << endl;
    }
    return 0;
}
