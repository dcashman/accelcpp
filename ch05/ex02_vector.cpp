// Complete new grading program - revised pgrogram from chapter 4 (p70) plus
// chapter 5 changes.

#include <algorithm>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

#include "grade.h"
#include "student_info.h"

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::sort;
using std::string;
using std::vector;

vector<Student_info> extract_fails(vector<Student_info>& students) {
    vector<Student_info> fail;
    vector<Student_info>::iterator iter = students.begin();

    while (iter != students.end()) {
        if (fgrade(*iter)) {
            fail.push_back(*iter);
            iter = students.erase(iter);
        } else {
            ++iter;
        }
    }
    return fail;
}

int main() {
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;  // len of longest name

    // read and store all the students' data
    while (read(cin, record)) {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    // alphabetize the student records
    sort(students.begin(), students.end(), compare);

    // write the names and grades
    vector<Student_info> failing_students = extract_fails(students);
    cout << "Failing Students and Grades (SHAME!):" << endl;
    for (vector<Student_info>::const_iterator i = failing_students.begin();
         i != failing_students.end(); ++i)
        print_Student_info(*i, maxlen, grade, cout);

    cout << "Passing Students and Grades:" << endl;
    for (vector<Student_info>::const_iterator i = students.begin();
         i != students.end(); ++i)
        print_Student_info(*i, maxlen, grade, cout);

    return 0;
}
