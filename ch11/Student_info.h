#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H

#include <istream>
#include <string>
#include <vector>

class Student_info {
 public:
    Student_info();
    Student_info(bool pf);
    Student_info(std::istream&, bool pf);
    Student_info(const Student_info&); // copy
    Student_info& operator=(const Student_info&); // assignment
    ~Student_info();
    std::string name() const { return n; }
    bool valid() const { return !homework.empty(); }
    std::istream& read(std::istream&); // p157
    double grade() const; // p158
    bool fgrade() const;
    bool passfail() const;
    static size_t construct, copy, assign, destruct;

 private:
    std::string n;
    bool pf;
    double midterm, final, final_grade;
    std::vector<double> homework;

};

bool compare(const Student_info&, const Student_info&);

#endif // STUDENT_INFO_H
