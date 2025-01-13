#include "student_info.h"
#include "compute_grade.h"

using std::istream;
using std::vector;
using std::list;

bool compare_StudentInfo_predicate(const StudentInfo &x, const StudentInfo &y)
{
    return x.name < y.name; // Alphabetical order
}

bool is_f_grade(const StudentInfo &s)
{
    return compute_grade(s) < 60.0;
}

istream &read_StudentInfo(istream &is, StudentInfo &s)
{
    is >> s.name >> s.midterm >> s.final;

    read_homework(is, s.homework);
    return is;
}

istream &read_homework(istream &in, vector<double> &hw)
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

list<StudentInfo> extract_failures(list<StudentInfo> &students)
{
    list<StudentInfo> fail;
    list<StudentInfo>::iterator iter = students.begin();

    while (iter != students.end())
    {
        if (is_f_grade((*iter)))
        {
            fail.push_back(*iter);
            iter = students.erase(iter);
        }
        else
        {
            // we only increment iter if the student passed, because removal above in the fail state
            // will automatically make i point to the next element in students
            ++iter;
        }
    }

    return fail;
}