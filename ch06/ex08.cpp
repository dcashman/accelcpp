#include <iostream>
#include <numeric>
#include <string>
#include <vector>

using std::accumulate;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

string conc_vec(vector<string> v) {
    string s;
    return accumulate(v.begin(), v.end(), s);
}

int main() {
    vector<string> v;

    // read all the records, separating them based on pass/fail
    string s;
    while (getline(cin, s)) {
        v.push_back(s);
    }

    cout << "Concatenated:" << endl;
    cout << conc_vec(v) << endl;

    return 0;
}
