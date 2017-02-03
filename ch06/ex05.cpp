#include <iostream>
#include <stdexcept>
#include <vector>

// unchanged since ch05 exercises
#include "../ch05/grade.h"
#include "../ch05/median.h"
#include "../ch05/Student_info.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::find;
using std::ostream;
using std::remove_copy;
using std::string;
using std::transform;
using std::vector;

bool did_all_hw(const Student_info& s) {
    return ((find(s.homework.begin(), s.homework.end(), 0)) == s.homework.end());
}

double optimistic_grade_aux(const Student_info& s) {
    vector<double> attempted_hw;
    remove_copy(s.homework.begin(), s.homework.end(),
                back_inserter(attempted_hw), 0.0);
    try {
        return grade(s.midterm, s.final, attempted_hw);
    } catch (domain_error) {
        return grade(s.midterm, s.final, 0);
    }
}

double optimistic_analysis(const vector<Student_info>& students) {
    vector<double> grades;

    transform(students.begin(), students.end(),
              back_inserter(grades), optimistic_grade_aux);
    return median(grades);
}

// from p113
void write_analysis(ostream& out, const string& name,
                    double analysis(const vector<Student_info>&),
                    const vector<Student_info>& did,
                    const vector<Student_info>& didnt) {
    out << name << ": median(did) = " << analysis(did)
        << ", median(didn't) = " << analysis(didnt) << endl;
}

// from p114
int main() {
    vector<Student_info> did, didnt;

    Student_info student;
    while(read(cin, student)) {
        if (did_all_hw(student))
            did.push_back(student);
        else
            didnt.push_back(student);
    }

    if (did.empty()) {
        cout << "No student did all of the homework!" << endl;
        return 1;
    }

    if (didnt.empty()) {
        cout << "Every student did all the homework!" << endl;
        return 1;
    }

    write_analysis(cout, "optimistic median", optimistic_analysis, did, didnt);

    return 0;
}

