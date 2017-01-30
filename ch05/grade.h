// from p69
#ifndef GRADE_H
#define GRADE_H

// grade.h

#include <vector>
#include "Student_info.h"

double grade(double, double, double);
double grade(double, double, const std::vector<double>&);
double grade(const Student_info&);
bool fgrade(const Student_info& s);

#endif // GRADE_H
