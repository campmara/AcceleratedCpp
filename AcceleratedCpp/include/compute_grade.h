#ifndef COMPUTE_GRADE_H
#define COMPUTE_GRADE_H

#include <vector>

#include "student_info.h"

double ComputeGrade(double midterm, double final, double homework);
double ComputeGrade(double midterm, double final, const std::vector<double> &homework);
double ComputeGrade(const StudentInfo &s);

#endif // !COMPUTE_GRADE_H
