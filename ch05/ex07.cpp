#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::max;
using std::string;
using std::vector;

// p92
string::size_type width(const vector<string>& v) {
    string::size_type maxlen = 0;
    for (vector<string>::size_type i = 0; i != v.size(); ++i)
        maxlen = max(maxlen, v[i].size());
    return maxlen;
}

vector<string> hcat(const vector<string>& l, const vector<string>& r) {
    vector<string> ret;

    // add 1 to leave a space between pictures
    string::size_type width1 = width(l) + 1;

    // indices to look at elements from l and r respectiely
    vector<string>::size_type i = 0, j = 0;

    string s;
    while(i != l.size() || j != r.size()) {
        //string s; // original placementa

        // copy a row from the l-hand side if there is one
        if (i != l.size())
            s = l[i++];

        // pad to full-width
        s += string(width1 - s.size(), ' ');

        // copy a row from the r-hand side if there is one
        if (j != r.size())
            s += r[j++];

        // add it to the result picture
        ret.push_back(s);
    }
    return ret;
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
    vector<string> left = { "this is an", "example", "to", "illustrate", "framing" };
    vector<string> right = frame(left);
    vector<string> smushed = hcat(left, right);

        for (auto& s : smushed)
            cout << s << endl;

}
