#ifndef COMPUTE_GRADE_H
#define COMPUTE_GRADE_H

#include <vector>

#include "student_info.h"

double compute_grade(double midterm, double final, double homework);
double compute_grade(double midterm, double final, const std::vector<double> &homework);
double compute_grade(const StudentInfo &s);

#endif // !COMPUTE_GRADE_H
