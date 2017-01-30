#include <iostream>
#include <unordered_map>
#include <vector>

using std::cin;
using std::cout;
using std::istream;
using std::string;
using std::vector;

vector<string> instream_to_vec(istream& input) {
    vector<string> vec;
    string in;
    while (input >> in) {
        vec.push_back(in);
    }
    return vec;
}

int main() {
    // create input vector of words
    vector<string> myvec = instream_to_vec(cin);

    // report total number of input
    cout << "Total words: " << myvec.size() << std::endl;

    // report total for each word (at this point in book, probably just expect
    // us to use n^2 iteration on vector, but why not do it right and use a map?
    std::unordered_map<string, size_t> count_map;
    for (auto& s: myvec) {
        count_map[s]++;
    }
    for (auto& s: count_map) {
        cout << s.first << " was encountered " << s.second << " times." << std::endl;
    }
    return 0;
}
