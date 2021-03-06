#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::max;
using std::string;
using std::vector;

string::size_type width(const vector<string>& v) {
    string::size_type maxlen = 0;
    for (vector<string>::size_type i = 0; i != v.size(); ++i)
        maxlen = max(maxlen, v[i].size());
    return maxlen;
}

vector<string> frame(const vector<string>& v) {
    vector<string> ret;
    string::size_type maxlen = width(v);
    string border(maxlen + 4, '*');

    // write the top border
    ret.push_back(border);

    // write each interior row
    for (vector<string>::size_type i = 0; i != v.size(); ++i)
        ret.push_back("* " + v[i] + string(maxlen - v[i].size(), ' ') + " *");

    // write bottom border
    ret.push_back(border);
    return ret;
}

int main() {
    vector<string> v;
    vector<string> ret = frame(v);

    for (auto& s : ret)
        cout << s << endl;

    return 0;
}
