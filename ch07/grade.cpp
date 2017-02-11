// from p69
#include <stdexcept>
#include <string>
#include <vector>

#include "grade.h"

// unchanged since ch05
#include "../ch05/median.h"
#include "../ch05/Student_info.h"

using std::domain_error;
using std::string;
using std::vector;

double grade(double midterm, double final, double homework) {
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

double grade(double midterm, double final, const vector<double>& hw) {
    if (hw.size() == 0)
        throw domain_error("student has done no homework");
    return grade(midterm, final, median(hw));
}

double grade(const Student_info& s) {
    return grade(s.midterm, s.final, s.homework);
}

bool fgrade(const Student_info& s) {
    return grade(s) < 60;
}

string letter(double grade) {
    if (grade >= 90.0)
        return "A";
    else if (grade >= 80.0)
        return "B";
    else if (grade >= 70.0)
        return "C";
    else if (grade >= 60.0)
        return "D";
    else
        return "F";
}
