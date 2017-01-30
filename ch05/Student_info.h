// from p68
#ifndef STUDENT_INFO
#define STUDENT_INFO

#include <iostream>
#include <string>
#include <vector>

struct Student_info {
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};

bool compare(const Student_info&, const Student_info&);
std::istream& read(std::istream&, Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);
void print_Student_info(const Student_info&, std::string::size_type,
                        double (*grade)(const Student_info&), std::ostream&);

#endif //STUDENT_INFO
