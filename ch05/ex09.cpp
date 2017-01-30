#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

bool isPalindrome(string& s) {
    string::size_type i = 0, j = s.size() - 1;
    while (i <= j && s[i] == s[j]) {
        i++;
        j--;
    }
    if (i > j)
        return true;
    else
        return false;
}

int main() {
    vector<string> palies;
    string::size_type max_len = 0;
    string s, biggest_pali;

    while (cin >> s) {
        if (isPalindrome(s)) {
            palies.push_back(s);
            if (s.size() > max_len) {
                biggest_pali = s;
                max_len = s.size();
            }
        }
    }

    cout << "Palindromes encountered: " << endl;

    for (const auto& s : palies)
        cout << s << endl;

    cout << "Biggest palindrome encountered: " << biggest_pali << endl;
    return 0;
}
