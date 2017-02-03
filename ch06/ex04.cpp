#include <algorithm>
#include <iostream>
#include <vector>

using std::back_inserter;
using std::copy;
using std::cout;
using std::endl;
using std::vector;


int main() {
    vector<int> u(10, 100);
    vector<int> v1;
    vector<int> v2;

    // method one - use back_inserter
    copy(u.begin(), u.end(), back_inserter(v1));

    // method two - allocate space
    v2.resize(u.size());
    copy(u.begin(), u.end(), v2.begin());

    // verify same:
    cout << "u: " << endl;
    for (auto& i : u)
        cout << i << endl;

    cout << endl << "v1: " << endl;
    for (auto& i : v1)
        cout << i << endl;

    cout << endl << "v2: " << endl;
    for (auto& i : v2)
        cout << i << endl;
    return 0;
}
