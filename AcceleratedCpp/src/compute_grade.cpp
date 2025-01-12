#include <stdexcept>
#include <vector>

#include "median.h"
#include "student_info.h"

using std::domain_error; 
using std::vector;

/// <summary>
/// Compute the grade based on midterm, final, and homework scores.
/// </summary>
double ComputeGrade(double midterm, double final, double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

/// <summary>
/// Compute the grade based on midterm, final, and homework scores, using the median homework score
/// as part of the final grade.
/// </summary>
double ComputeGrade(double midterm, double final, const vector<double> &homework)
{
    if (homework.size() == 0)
    {
        throw domain_error("Student has no homework grades.");
    }

    return ComputeGrade(midterm, final, Median(homework));
}

double ComputeGrade(const StudentInfo &s)
{
    return ComputeGrade(s.midterm, s.final, s.homework);
}