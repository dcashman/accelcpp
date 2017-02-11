#include <cstdlib>
#include <iostream>
#include <list>
#include <vector>

using namespace std;

/*
 * nrand greater than RAND_MAX - we can only get random numbers in RAND_MAX
 * intervals, so we need to comprise our number from that.  By representing
 * a number base RAND_MAX, we can make a minimal number of rand() calls:
 * one for each digit.  To do this without many wasted queries, we limit
 * the possible otuputs for each digit when approaching the upper-limit of
 * our range and allow specification of the rmax value.
 */

// book implementation p135
int nrand_helper(int n) {
    const int bucket_size = RAND_MAX/n;
    int r;

    do r = rand()/bucket_size;
    while (r >=n);
    return r;
}

int nrand(int n, int rmax) {
    if (n <= 0 || rmax > RAND_MAX)
        throw domain_error("Argument to nrand is out of range");
    // get base rmax representation of highest number in our range
    int tmp = n - 1;
    list<int> repr;
    do {
        repr.insert(repr.begin(), tmp % rmax);
        tmp /= rmax;
    } while (tmp);

    int ret = 0;
    bool limit = true;
    // for each digit in our range, get a random value and add it to result
    // making sure not to add numbers above our range
    list<int>::const_iterator i = repr.begin();
    while (i != repr.end()) {
        int new_digit;
        ret *= rmax;
        new_digit = nrand_helper(rmax);
        ret += new_digit;
        if (limit && new_digit < *i) {
            // we're no longer in danger of going over
            limit = false;
            i++;
        } else if (limit && new_digit > *i) {
            // went over, try whole thing again
            ret = 0;
            i = repr.begin();
        } else {
            i++;
        }
    }
    return ret;
}

int main() {

    // test this with non RAND_MAX values for RAND_MAX just to see how the
    // distribution goes
    static constexpr int RMAX = RAND_MAX;
    static constexpr int LRG_RND = 100;
    static constexpr size_t SAMP_SZ = 10;
    vector<int> results(LRG_RND, 0);
    for (int i = 0; i < SAMP_SZ; ++i) {
        int rand = nrand(LRG_RND, RMAX);
        results[rand]++;
    }

    for (int i = 0; i< results.size(); i++) {
        cout << i << " received " << (double) results[i]/SAMP_SZ  * 100 << " percent"
             << ", expected: " << (double) 1/LRG_RND * 100 << " percent." << endl;
    }
    return 0;
}
