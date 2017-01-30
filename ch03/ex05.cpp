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
    vector<string> names;
    vector<double> grades;
    const size_t NUM_HW = 4;
    do {
        cout << "Please enter your first name: ";
        string name;
        if (!(cin >> name))
            break;
        cout << "Hello, " << name << "!" << endl;
        cout << "Please enter your midterm and final exam grades: ";
        double midterm, final;
        cin >> midterm >> final;

        cout << "Enter all " << NUM_HW << " of your homework grades: ";
        vector<double> homework;
        double x;
        for (size_t i = 0; i < NUM_HW; i++) {
            cin >> x;
            homework.push_back(x);
        }

        typedef vector<double>::size_type vec_sz;
        vec_sz size = homework.size();
        if (size == 0) {
            cout << endl << "You must uenter your grades. Please try again." << endl;
            return 1;
        }

        sort(homework.begin(), homework.end());

        vec_sz mid = size/2;
        double median;
        median = size % 2 == 0 ? (homework[mid] + homework[mid - 1])/2
            : homework[mid];

        double grade = 0.2 * midterm + 0.4 * final + 0.4 * median;
        names.push_back(name);
        grades.push_back(grade);
    } while (cin);

    cout << endl;
    for (int i = 0; i < names.size(); i++) {
        streamsize prec = cout.precision();
        cout << names[i] << " final grade is " << setprecision(3)
             << grades[i] << setprecision(prec) << endl;
    }

    return 0;
}
