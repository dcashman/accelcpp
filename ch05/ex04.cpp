#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::string;
using std::vector;

// from p92
string::size_type width(const vector<string>& v) {
    string::size_type maxlen = 0;
    for (vector<string>::size_type i = 0; i != v.size(); ++i)
        maxlen = max(maxlen, v[i].size());
    return maxlen;
}

vector<string> center(const vector<string>& v) {
    vector<string> ret;
    string::size_type maxlen = width(v);

    // determine padding of each string and center it (half before/half after)
    for(auto& s : v) {
        string::size_type padding = maxlen - s.size();

        // if there is an odd number of padding characters needed, add more
        // padding at the beginning to be consitent
        string tmp;
        if (padding % 2 != 0)
            tmp += ' ';
        tmp += string(padding/2, ' ') + s + string(padding/2, ' ');
        ret.push_back(tmp);
    }
    return ret;
}

int main() {
    // get input frame
    string s;
    vector<string> picture;
    while(getline(cin, s)) {
        picture.push_back(s);
    }

    // center picture
    vector<string> centered = center(picture);

    // let's see it
    for (auto& s : centered)
        cout << s << endl;

    return 0;
}
