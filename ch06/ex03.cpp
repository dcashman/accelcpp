#include <algorithm>
#include <vector>

using std::copy;
using std::vector;


int main() {
    vector<int> u(10, 100);
    vector<int> v;
    copy(u.begin(), u.end(), v.begin());
    return 0;
}
