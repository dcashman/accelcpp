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
    stable_partition(students.begin(), students.end(),
                     [](Student_info& s) -> bool { return !s.fgrade(); });
    for (vector<Student_info>::size_type i = 0;
         i != students.size(); i++) {
        cout << students[i].name() << string(maxlen + 1 - students[i].name().size(), ' ');
        try {
            bool fg = !students[i].fgrade();
            streamsize prec = cout.precision();
            cout << setprecision(3);
            if (fg)
                cout << "P";
            else
                cout << "F";
            cout << setprecision(prec) << endl;
        } catch (domain_error e) {
            cout << e.what() << endl;
        }
    }
    return 0;
}
