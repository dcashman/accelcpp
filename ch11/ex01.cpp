#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "Student_info.h"

using namespace std;

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
            double final_grade = students[i].grade();
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec) << endl;
        } catch (domain_error e) {
            cout << e.what() << endl;
        }
    }

    cout << "Stats for Student_info big 4: " << endl;
    cout << "# Constructor calls: " << Student_info::construct << endl;
    cout << "# Copy calls: " << Student_info::copy << endl;
    cout << "# Assignment calls: " << Student_info::assign << endl;
    cout << "# Destructor calls: " << Student_info::destruct << endl;
    return 0;
}
