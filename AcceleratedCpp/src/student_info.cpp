#include "student_info.h"
#include "compute_grade.h"

using std::istream;
using std::vector;

bool CompareStudentInfos(const StudentInfo &x, const StudentInfo &y)
{
    return x.name < y.name; // Alphabetical order
}

istream &Read(istream &is, StudentInfo &s)
{
    is >> s.name >> s.midterm >> s.final;

    ReadHomework(is, s.homework);
    return is;
}

istream &ReadHomework(istream &in, vector<double> &hw)
{
    if (in)
    {
        // get rid of previous contexts
        hw.clear();

        double x;
        while (in >> x)
        {
            hw.push_back(x);
        }

        // clear the stream so that input will work for the next student. istream::clear() is not
        // like vector<T>::clear()!! It instead resets error indications so that input can continue.
        in.clear();
    }
    return in;
}