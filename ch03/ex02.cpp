#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

int main()
{
    cout << "Please enter your integers: ";
    int x;
    vector<int> intys;
    while (cin >> x)
        intys.push_back(x);

    typedef vector<int>::size_type vec_sz;
    vec_sz size = intys.size();
    if (size == 0) {
        cout << endl << "Didn't get any integers.  Please try again." << endl;
        return 1;
    }

    sort(intys.begin(), intys.end());

    vec_sz mid = size/2;
    /* [mid - 1] is the 'top' of the first quartile:
     * either mid is the median and it is discarded
     * or median is mid - 1 and mid, in which case we want the lower one.
     * This means that mid is the number of elements in the quartile */
    double q2 = (size % 2 == 0) ? (double) (intys[size/2] + intys[size/2 - 1])/2 : intys[size/2];
    double q1 = (mid % 2 == 0) ? (double) (intys[mid/2] + intys[mid/2 - 1])/2 : intys[mid/2];
    double q3 = (mid % 2 == 0) ? (double) (intys[mid/2 + mid] + intys[mid/2 - 1 + mid])/2 : intys[mid/2 + mid];

    cout << "size: " << size << endl;
    cout << "quartile 1 value: " << q1 << endl;
    cout << "quartile 2 value: " << q2 << endl;
    cout << "quartile 3 value: " << q3 << endl;
    return 0;
}
