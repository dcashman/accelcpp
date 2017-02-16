#include <algorithm>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <type_traits>
#include <vector>

using namespace std;

// http://www.cplusplus.com/reference/iterator/iterator/
template <class Ran>
typename iterator_traits<Ran>::value_type median(Ran b, Ran e) {
    typedef typename Ran::difference_type it_sz;

    it_sz size = distance(b,e);
    if (size == 0)
        throw domain_error("median of an empty sequence");

    sort(b, e);
    it_sz mid = size/2;
    return size % 2 == 0 ? (*(b + mid) + *(b + mid - 1))/2 : *(b + mid);
}

int main() {
    vector<double> t1;
    for (int i = 0; i < 5; i++)
        t1.push_back(i);
    vector<double> t2(t1);
    t1.push_back(5);

    if (median(t1.begin(), t1.end()) == 2.5
        && median(t2.begin(), t2.end()) == 2)
        cout << "median PASSED" << endl;
    else
        cout << "median FAILED" << endl;

    return 0;
}
