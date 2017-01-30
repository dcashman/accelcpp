// Complete new grading program - revised pgrogram from chapter 4 (p70) plus
// chapter 5 changes.

#include <ios>
#include <iostream>
#include <string>
#include <list>

#include "grade.h"
#include "Student_info.h"

using std::cin;
using std::cout;
using std::endl;
using std::max;
using std::string;
using std::list;

list<Student_info> extract_fails(list<Student_info>& students) {
    list<Student_info> fail;
    list<Student_info>::iterator iter = students.begin();

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
    list<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;  // len of longest name

    // read and store all the students' data
    while (read(cin, record)) {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    // alphabetize the student records
    students.sort(compare);

    // write the names and grades
    list<Student_info> failing_students = extract_fails(students);
    cout << "Failing Students and Grades (SHAME!):" << endl;
    for (list<Student_info>::const_iterator i = failing_students.begin();
         i != failing_students.end(); ++i)
        print_Student_info(*i, maxlen, grade, cout);

    cout << "Passing Students and Grades:" << endl;
    for (list<Student_info>::const_iterator i = students.begin();
         i != students.end(); ++i)
        print_Student_info(*i, maxlen, grade, cout);

    return 0;
}
