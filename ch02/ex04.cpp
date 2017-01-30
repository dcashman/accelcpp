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
            } else {
                if (r == 0 || c == 0 || r == rows - 1 || c == cols - 1)
                    cout << "*";
                else
                    cout << " ";
                ++c;
            }
        }
        cout << endl;
    }
    return 0;
}
