#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

struct rotation {
    vector<string>::size_type num_first;
    vector<string> rotated_str;
};

// given on p88 of accel c++ (copied exactly)
vector<string> split(const string& s) {
    vector<string> ret;
    typedef string::size_type string_size;
    string_size i = 0;

    // invariant: we have processed characters [original value of i,i)
    while (i != s.size()) {
        // ignore leading blanks
        // invariant: characters in range (original i, current i) are all spaces
        while (i != s.size() && isspace(s[i]))
            ++i;

        // find end of next word
        string_size j = i;
        // invariant: none of the characters in range [original j, current j) is a space
        while(j  != s.size() && !isspace(s[j]))
            ++j;

        // if we found some nonwhitewpace characters
        if (i != j) {
            // copy from s starting at i and taking j - i chars
            ret.push_back(s.substr(i, j - i));
            i = j;
        }
    }
    return ret;
}

bool compare(const struct rotation& x, const struct rotation& y) {
    vector<string>::const_iterator i = x.rotated_str.begin();
    vector<string>::const_iterator j = y.rotated_str.begin();

    // both vectors still have elements, compare
    while (i < x.rotated_str.end() && j < y.rotated_str.end()) {
        if (*i == *j) {
            i++;
            j++;
            continue;
        } else {
            return *i < *j;
        }
    }
    if (i < x.rotated_str.end())
        return false;
    if (j < y.rotated_str.end())
        return true;
    return false;  // lists are equal
}

vector<struct rotation> get_rotations(string::size_type& max_width) {
    string s;
    max_width = 0;
    vector<struct rotation> rotations;

    // get lines and rotations, also record longest line
    while(getline(std::cin, s)) {
        if (s.size() >= max_width)
            max_width = s.size();
        // create rotations
        vector<string> tokens = split(s);
        if (tokens.size() == 0)
            continue;
        vector<string>::const_iterator t = tokens.begin();
        vector<string>::size_type num_first = 0;
        while (t != tokens.end()) {
            struct rotation r;
            r.num_first = num_first++;
            // copy remaining part, with front part added at the back
            vector<string>::const_iterator i = tokens.begin();
            vector<string>::const_iterator j = t;
            while (j != tokens.end()) {
                r.rotated_str.push_back(*j);
                j++;
            }
            while (i != t) {
                r.rotated_str.push_back(*i);
                i++;
            }
            rotations.push_back(r);
            t++;
        }
    }
    return rotations;
}

void print_index(vector<struct rotation> rotations, string::size_type width) {
    // create index output based on original phrase
    for (auto& r : rotations) {
        string first, second;
        vector<string>::size_type i = r.rotated_str.size() - r.num_first;
        vector<string>::const_iterator s = r.rotated_str.begin() + i;
        while (s < r.rotated_str.end())
            first += *s++ + " ";
        s = r.rotated_str.begin();
        while (s < r.rotated_str.begin() + i)
            second += *s++ + " ";
        std::cout << std::setw(width) << first << "     " << second << std::endl;
    }
}

int main() {
    string::size_type width;
    vector<struct rotation> rotations = get_rotations(width);
    sort(rotations.begin(), rotations.end(), compare);
    print_index(rotations, width);
    return 0;
}
