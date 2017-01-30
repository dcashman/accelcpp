#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Please specify the amount of vertical padding: ";
    int vert_pad;
    cin >> vert_pad;
    cout << "Please specify the amount of horizontal padding: ";
    int hor_pad;
    cin >> hor_pad;

    const string greeting = "Hello, " + name + "!";

    const int rows = vert_pad * 2 + 3;
    const string::size_type cols = greeting.size() + 2 * hor_pad + 2;

    cout << endl;

    for (int r = 0; r != rows; ++r) {
        string::size_type c = 0;

        while (c != cols) {
            if (r == vert_pad + 1 && c == hor_pad + 1) {
                cout << greeting;
                c += greeting.size();
            } else if (r == 0 || r == rows - 1) {
                // write full top or bottom border
                string tmp(cols, '*');
                cout << tmp;
                c += cols;
            } else if (c == 0 || c == cols - 1) {
                // write side border
                    cout << "*";
                    ++c;
            } else if (r != vert_pad + 1) {
                // non-greeting line, just fill with spaces (except border)
                string tmp(cols - 2, ' ');
                cout << tmp;
                c += cols -2;
            } else if (r == vert_pad + 1 && (c == 1 || c == 1 + hor_pad + greeting.size())) {
                // write horizontal padding
                string tmp(hor_pad, ' ');
                cout << tmp;
                c += hor_pad;
            }
        }
        cout << endl;
    }
    return 0;
}
