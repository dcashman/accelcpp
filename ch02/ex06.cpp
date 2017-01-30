#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    cout << "Please enter your shape...\n";
    cout << "1 rectangle\n";
    cout << "2: triangle\n";
    int type;
    cin >> type;
    if (type != 1 && type != 2) {
        cout << "Invalid choice: SELF DESTRUCT!\n";
        return 1;
    }

    cout << "Please enter the shape dimensions...\n";
    cout << "Height:";
    size_t height;
    cin >> height;
    cout << "Width:";
    size_t wid;
    cin >> wid;


    if (type == 1) {
        /*
         * rectangle
         * could put this in a function, but whatever, that gets intro'd later,
         * reuse the framing program, but without greeting complication
         */

        const int rows = height;
        const string::size_type cols = wid;

        cout << endl;

        for (int r = 0; r != rows; ++r) {
            string::size_type c = 0;

            while (c != cols) {
                if (r == 0 || r == rows - 1) {
                    // write full top or bottom border
                    string tmp(cols, '*');
                    cout << tmp;
                    c += cols;
                } else if (c == 0 || c == cols - 1) {
                    // write side border
                    cout << "*";
                    ++c;
                } else {
                    string tmp(cols - 2, ' ');
                    cout << tmp;
                    c += cols -2;
                }
            }
            cout << endl;
        }
        return 0;
    } else {
        /*
         * triangle
         * don't get fancy, just start with one star, then two for each row
         * until one before the last.  This ignores the width, but that was
         * not originally requested, and requires trig, so meh.
         */
        const int rows = height;
        unsigned int pos1 = height -1;
        unsigned int pos2 = height -1;
        const string::size_type cols = rows * 2 - 1;
        for (int r = 0; r < rows - 1; r++) {
            string::size_type c = 0;
            while ( c != cols) {
                if (c == pos1 || c == pos2) {
                    cout << "*";
                } else {
                    cout << " ";
                }
                c++;
            }
            cout << endl;
            pos1--;
            pos2++;
        }
        // final line
        string tmp(cols, '*');
        cout << tmp;
        cout << endl;
    }
}
