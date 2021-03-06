#include <istream>

#include "median.h"
#include "Student_info.h"

using namespace std;

/* helper funcs, keep private */
// from p57
static istream& read_hw(istream& in, vector<double>& hw) {
    if (in) {
        // get rid of previous contents
        hw.clear();

        // read hw grades
        double x;
        while (in >> x)
            hw.push_back(x);

        // clear the stream so that input will work for the next student
        in.clear();
    }
    return in;
}

// keep this private to Student_info now
static double grade(double midterm, double final, double homework) {
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// keep this private to Student_info now
static double grade(double midterm, double final) {
    return 0.33 * midterm + 0.67 * final;
}

static double grade(double midterm, double final, const vector<double>& hw) {
    if (hw.size() == 0)
        throw domain_error("student has done no homework");
    return ::grade(midterm, final, median(hw));
}

/* core class funcs */
Student_info::Student_info() : midterm(0), final(0), final_grade(0), pf(false) { }

Student_info::Student_info(bool pf) : midterm(0), final(0), final_grade(0), pf(pf) { }

Student_info::Student_info(istream& is, bool pf) {
    this->pf = pf;
    read(is);
}

istream& Student_info::read(istream& in) {
    in >> n >> midterm >> final;
    read_hw(in, homework);
    if (pf)
        final_grade = ::grade(midterm, final);
    else
        final_grade = ::grade(midterm, final, homework);
    return in;
}

double Student_info::grade() const {
    return final_grade;
}

bool Student_info::fgrade() const {
    return grade() < 60;
}

bool Student_info::passfail() const {
    return pf;
}

bool compare(const Student_info& x, const Student_info& y) {
    return x.name() < y.name();
}
