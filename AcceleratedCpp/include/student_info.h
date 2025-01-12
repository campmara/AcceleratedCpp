#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H

#include <iostream>
#include <string>
#include <vector>

struct StudentInfo
{
    std::string name;
    double midterm;
    double final;
    std::vector<double> homework;
}; // Note that the semicolon is required.

bool CompareStudentInfos(const StudentInfo &x, const StudentInfo &y);

/// <summary>
/// Reads values from an istream into a referenced StudentInfo object, and returns the stream.
/// </summary>
std::istream &Read(std::istream &is, StudentInfo &s);

std::istream &ReadHomework(std::istream &in, std::vector<double> &hw);

#endif // !STUDENT_INFO_H
