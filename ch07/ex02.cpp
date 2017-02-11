#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>


#include "grade.h"

// unchanged since ch05 exercises
#include "../ch05/median.h"
#include "../ch05/Student_info.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::map;
using std::max;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

int main() {
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    while (read(cin, record)) {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    sort(students.begin(), students.end(), compare);

    map<string, size_t> grade_counts; // just aggregate
    for (vector<Student_info>::const_iterator i = students.begin();
         i != students.end(); ++i) {

        cout << i->name << string(maxlen + 1 - i->name.size(), ' ');

        try {
            double final_grade = grade(*i);
            grade_counts[letter(final_grade)]++;
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;
    }

    cout << endl << "Grade distribution:" << endl;
    for (map<string, size_t>::const_iterator it = grade_counts.begin();
         it != grade_counts.end(); ++it) {
        cout << it->second << " " << it->first;
        if (it->second == 1)
            cout << " student";
        else
            cout << " students";
        cout << endl;
    }
    return 0;
}
