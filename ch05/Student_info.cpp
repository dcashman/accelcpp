// from p68
#include <iomanip>
#include <stdexcept>

#include "Student_info.h"

using std::domain_error;
using std::endl;
using std::istream;
using std::setprecision;
using std::streamsize;
using std::string;
using std::vector;

bool compare(const Student_info& x, const Student_info& y) {
    return x.name < y.name;
}

// from p62
istream& read(istream& is, Student_info& s) {
    // read and store the student's name and midterm and final exam grades
    is >> s.name >> s.midterm >> s.final;

    read_hw(is, s.homework);  // read and store all the student's hw grades
    return is;
}

// from p57
istream& read_hw(istream& in, vector<double>& hw) {
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

void print_Student_info(const Student_info& s, string::size_type maxlen,
                        double (*grade)(const Student_info&), std::ostream& out) {
        // write the name, padded on teh rigth to maxlen +1 chars
        out << s.name << string(maxlen + 1 - s.name.size(), ' ');

        // compute and write the grade
        try {
            double final_grade = grade(s);
            streamsize prec = out.precision();
            out << setprecision(3) << final_grade << setprecision(prec);
        } catch (domain_error e) {
            out << e.what();
        }
        out << endl;
}
