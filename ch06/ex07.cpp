#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

// unchanged since ch05 exercises
#include "../ch05/grade.h"
#include "../ch05/median.h"
#include "../ch05/Student_info.h"

using std::back_inserter;
using std::cin;
using std::copy;
using std::cout;
using std::endl;
using std::max;
using std::stable_partition;
using std::string;
using std::vector;

vector<Student_info> split_if(vector<Student_info>& students,
                              bool pred(const Student_info& s)) {
    vector<Student_info> negatives;
    vector<Student_info>::iterator split;
    split = stable_partition(students.begin(), students.end(), pred);
    copy(split, students.end(), back_inserter(negatives));
    students.erase(split, students.end());
    return negatives;
}

int main() {
    vector<Student_info> passed, failed;
    Student_info student;
    string::size_type maxlen = 0;  // len of longest name

    // read all the records, separating them based on pass/fail
    while (read(cin, student)) {
        maxlen = max(maxlen, student.name.size());
        failed.push_back(student);
    }

    passed = split_if(failed, fgrade);

    // write the names and grades
    cout << "Failing Students and Grades (SHAME!):" << endl;
    for (vector<Student_info>::const_iterator i = failed.begin();
         i != failed.end(); ++i)
        print_Student_info(*i, maxlen, grade, cout);

    cout << "Passing Students and Grades:" << endl;
    for (vector<Student_info>::const_iterator i = passed.begin();
         i != passed.end(); ++i)
        print_Student_info(*i, maxlen, grade, cout);

    return 0;
}

