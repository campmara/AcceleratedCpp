#include <stdexcept>
#include <vector>

#include "median.h"
#include "student_info.h"

using std::domain_error; 
using std::vector;

/// <summary>
/// Compute the grade based on midterm, final, and homework scores.
/// </summary>
double compute_grade(double midterm, double final, double homework)
{
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

/// <summary>
/// Compute the grade based on midterm, final, and homework scores, using the median homework score
/// as part of the final grade.
/// </summary>
double compute_grade(double midterm, double final, const vector<double> &homework)
{
    if (homework.size() == 0)
    {
        throw domain_error("Student has no homework grades.");
    }

    return compute_grade(midterm, final, median(homework));
}

double compute_grade(const StudentInfo &s)
{
    return compute_grade(s.midterm, s.final, s.homework);
}