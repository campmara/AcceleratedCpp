#ifndef CHAPTER_4_H
#define CHAPTER_4_H

#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

#include "compute_grade.h"
#include "student_info.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::max;
using std::setprecision;
using std::setw;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;
using std::fixed;
using std::istream;

int grading_functions_program()
{
    // ask for and read the student's name
    cout << "Please enter your first name: ";
    string name;
    cin >> name;
    cout << "Hello, " << name << "!" << endl;

    // ask for and read the midterm and final grades
    cout << "Please enter your midterm and final exam grades: ";
    double midterm, final;
    cin >> midterm >> final;

    // ask for the homework grades
    cout << "Enter all your homework grades, followed by end-of-file: ";

    // a variable into which to read
    double x;
    vector<double> homework;

    read_homework(cin, homework);

    try
    {
        double final_grade = compute_grade(midterm, final, homework);

        streamsize prec = cout.precision();
        cout << "Your final grade is " << setprecision(3) << final_grade << setprecision(prec)
             << endl;
    }
    catch (domain_error)
    {
        cout << endl << "You must enter your grades. Please try again." << endl;
        return 1;
    }
    return 0;
}

int student_info_program()
{
    vector<StudentInfo> students;
    StudentInfo record;
    string::size_type max_length = 0;

    // read and store all the records, and find the length of the longest name
    while (read_StudentInfo(cin, record))
    {
        max_length = max(max_length, record.name.size());
        students.push_back(record);
    }

    // alphabetize the records
    sort(students.begin(), students.end(), compare_StudentInfo_predicate);

    for (vector<StudentInfo>::size_type i = 0; i != students.size(); ++i)
    {
        // write the name, padded on the right to max_length + 1 characters
        cout << students[i].name << string(max_length + 1 - students[i].name.size(), ' ');

        // compute and write the grade
        try
        {
            double final_grade = compute_grade(students[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec);
        }
        catch (domain_error e)
        {
            cout << e.what(); // what??!?! ew!
        }

        cout << endl;
    }

    return 0;
}

int get_num_digits(int number)
{
    int length = 1;
    while (number / 10 > 0)
    {
        number /= 10;
        length++;
    }
    return length; 
}

void program_4_2_and_3()
{
    const int maxNumber = 1000;

    for (int i = 1; i <= maxNumber; ++i)
    {
        int maxNumberDigits = get_num_digits(maxNumber);
        int maxNumberDigitsSquared = get_num_digits(maxNumber * maxNumber);
        const int padding = 20 + maxNumberDigitsSquared;

        cout << setw(maxNumberDigits) << i << setw(padding) << i * i << endl;
    }
}

int get_num_digits(double number, streamsize numDecimals)
{
    int length = 1;
    while (number / 10.0 > 1.0)
    {
        number /= 10.0;
        length++;
    }
    return length + numDecimals + 1;
}

void program_4_4()
{
    const double maxNumber = 100.0;
    const streamsize numDecimals = 2;

    for (double i = 1; i <= maxNumber; ++i)
    {
        int maxNumberDigits = get_num_digits(maxNumber, numDecimals);
        int maxNumberDigitsSquared = get_num_digits(maxNumber * maxNumber, numDecimals);
        const double padding = 20 + maxNumberDigitsSquared + 1;

        double value = i;
        double valueSquared = i * i;

        streamsize precision = cout.precision();
        cout << fixed << setw(maxNumberDigits) << setprecision(numDecimals) << value << setw(padding) << valueSquared << setprecision(precision) << endl;
    }
}

istream &read_words_into_vector(istream &in, vector<string> &words)
{
    if (in)
    {
        // get rid of previous contexts
        words.clear();

        string x;
        while (in >> x)
        {
            words.push_back(x);
        }

        // clear the stream so that input will work for the next student. istream::clear() is not
        // like vector<T>::clear()!! It instead resets error indications so that input can continue.
        in.clear();
    }
    return in;
}

void program_4_5()
{
    cout << "Please enter a sentence: ";

    vector<string> words;

    read_words_into_vector(cin, words);

    cout << endl << "Number of words: " << words.size() << endl;

    vector<string> unique_words;
    vector<int> counts;

    for (int i = 0; i < words.size(); ++i)
    {
        bool found_word = false;

        for (int j = 0; j < unique_words.size(); ++j)
        {
            if (words[i] == unique_words[j])
            {
                found_word = true;
                counts[j]++;
            }
        }

        if (!found_word)
        {
            unique_words.push_back(words[i]);
            counts.push_back(1);
        }
    }

    cout << "Unique word instances: " << endl;
    for (int i = 0; i < unique_words.size(); ++i)
    {
        cout << unique_words[i] << setw(5) << counts[i] << endl;
    }
}

#pragma region Rewritten StudentInfo Nonsense

struct StudentInfoRewritten
{
    std::string name;
    double final_grade;
};

// bastard!!!
istream &read_and_compute(istream &is, StudentInfoRewritten &s)
{
    double midterm, final;
    vector<double> homework;

    is >> s.name >> midterm >> final;

    if (is)
    {
        read_homework(is, homework);

        // compute and write the grade
        try
        {
            double final_grade = compute_grade(midterm, final, homework);
            s.final_grade = final_grade;
        }
        catch (std::domain_error e)
        {
            std::cout << e.what(); // what??!?! ew!
        }
    }

    return is;
}

bool compare_student_infos(const StudentInfoRewritten &x, const StudentInfoRewritten &y)
{
    return x.name < y.name; // Alphabetical order
}

void program_4_6()
{
    vector<StudentInfoRewritten> students;
    StudentInfoRewritten record;
    string::size_type max_length = 0;

    // read and store all the records, and find the length of the longest name
    while (read_and_compute(cin, record))
    {
        max_length = max(max_length, record.name.size());
        students.push_back(record);
    }

    // alphabetize the records
    sort(students.begin(), students.end(), compare_student_infos);

    for (vector<StudentInfoRewritten>::size_type i = 0; i != students.size(); ++i)
    {
        // write the name, padded on the right to max_length + 1 characters
        cout << students[i].name << string(max_length + 1 - students[i].name.size(), ' ');

        streamsize prec = cout.precision();
        cout << setprecision(3) << students[i].final_grade << setprecision(prec);

        cout << endl;
    }
}

void program_4_7()
{
    vector<double> doubles;
    double x;
    while (cin >> x)
    {
        doubles.push_back(x);
    }

    // get the sum
    double sum = 0.0;
    for (vector<double>::size_type i = 0; i < doubles.size(); ++i)
    {
        sum += doubles[i];
    }

    cout << "Average of vector of doubles: " << sum / doubles.size() << endl;
}

#pragma endregion

#endif // !CHAPTER_4_H
