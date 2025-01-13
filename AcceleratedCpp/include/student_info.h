#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H

#include <iostream>
#include <string>
#include <vector>
#include <list>

struct StudentInfo
{
    std::string name;
    double midterm;
    double final;
    std::vector<double> homework;
}; // Note that the semicolon is required.

bool compare_StudentInfo_predicate(const StudentInfo &x, const StudentInfo &y);
bool is_f_grade(const StudentInfo &s);

/// <summary>
/// Reads values from an istream into a referenced StudentInfo object, and returns the stream.
/// </summary>
std::istream &read_StudentInfo(std::istream &is, StudentInfo &s);

std::istream &read_homework(std::istream &in, std::vector<double> &hw);

#endif // !STUDENT_INFO_H
