#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

// as yet unchanged
#include "../ch09/Student_info.h"

using namespace std;

// p178

string letter_grade(double grade) {
    static const double numbers[] = { 97, 94, 90, 87, 84, 80, 77, 74, 70, 67, 64, 60, 0 };
    static const char* const letters[] = { "A+", "A", "A-", "B+", "B", "B-",
                                           "C+", "C", "C-", "D+", "D", "D-", "F" };

    for (size_t i = 0; i < sizeof(numbers)/sizeof(numbers[0]); i++) {
        if (grade > numbers[i])
            return string(letters[i]);
    }
    return "\?\?\?";
}

int main() {
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    while (record.read(cin)) {
        maxlen = max(maxlen, record.name().size());
        students.push_back(record);
    }

    sort(students.begin(), students.end(), compare);
    for (vector<Student_info>::size_type i = 0;
         i != students.size(); i++) {
        cout << students[i].name() << string(maxlen + 1 - students[i].name().size(), ' ');
        try {
            string fg = letter_grade(students[i].grade());
            streamsize prec = cout.precision();
            cout << fg << endl;
        } catch (domain_error e) {
            cout << e.what() << endl;
        }
    }
    return 0;
}
