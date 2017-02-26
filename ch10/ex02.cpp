#include <algorithm>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <type_traits>
#include <vector>

using namespace std;

template <class Ran>
typename iterator_traits<Ran>::value_type median(Ran b, Ran e) {

    typedef typename iterator_traits<Ran>::value_type it_val;
    vector<it_val> tmp;
    copy(b, e, back_inserter(tmp));
    sort(tmp.begin(), tmp.end());

    typename vector<it_val>::size_type size = tmp.size();
    if (size == 0)
        throw domain_error("median of an empty sequence");

    typename vector<it_val>::size_type mid = size/2;

    return size % 2 == 0 ? (tmp[mid] + tmp[mid - 1])/2 : tmp[mid];
}

int main() {
    // test median
    double arr[] = { 0, 1, 2, 3, 4 };
    vector<double> vec;
    for (double i = 0; i < 6; i++)
        vec.push_back(i);

    cout << "Median of 0 - 4 on array: " << median(arr, arr + sizeof(arr)/sizeof(arr[0]))
         << endl;

    cout << "Median of 0 - 5 on vec: " << median(vec.begin(), vec.end()) << endl;

    return 0;
}
