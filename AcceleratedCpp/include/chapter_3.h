#ifndef CHAPTER_3_H
#define CHAPTER_3_H

#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

void ComputeStudentGradesProgram()
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

    // the number and sum of grades read so far
    int count = 0;
    double sum = 0;

    // a variable into which to read
    double x;

    // invariant: we have read count grades so far, and sum is the sum of the first count grades
    while (cin >> x)
    {
        ++count;
        sum += x;
    }

    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3)
         << 0.2 * midterm + 0.4 * final + 0.4 * sum / count << setprecision(prec) << endl;
}

int ComputeGradesWithMedianProgram()
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

    // invariant: we have read count grades so far, and sum is the sum of the first count grades
    while (cin >> x)
    {
        homework.push_back(x);
    }

    typedef vector<double>::size_type vec_sz;
    vec_sz size = homework.size();

    if (size == 0)
    {
        cout << endl << "You must enter your grades. Please try again." << endl;
        return 1;
    }

    sort(homework.begin(), homework.end());

    vec_sz mid = size / 2;
    double median;
    median = size % 2 == 0 ? (homework[mid] + homework[mid - 1]) / 2 : homework[mid];

    streamsize prec = cout.precision();
    cout << "Your final grade is " << setprecision(3) << 0.2 * midterm + 0.4 * final + 0.4 * median
         << setprecision(prec) << endl;

    return 0;
}

void Program_3_2()
{
    cout << "Please enter a set of integers, followed by an end-of-file: ";

    vector<int> numbers;
    int currentNumber = 0;

    while (cin >> currentNumber)
    {
        numbers.push_back(currentNumber);
    }

    typedef vector<int>::size_type VSIZE;
    VSIZE size = numbers.size();

    if (size == 0)
    {
        cout << "No integers specified, please try again." << endl;
        return;
    }

    sort(numbers.begin(), numbers.end());

    VSIZE quarterSize = size / 4;

    vector<int> first;
    vector<int> second;
    vector<int> third;
    vector<int> fourth;

    for (int i = 0; i < quarterSize; ++i)
    {
        first.push_back(numbers[i]);
    }

    for (int i = quarterSize; i < quarterSize * 2; ++i)
    {
        second.push_back(numbers[i]);
    }

    for (int i = quarterSize * 2; i < quarterSize * 3; ++i)
    {
        third.push_back(numbers[i]);
    }

    for (int i = quarterSize * 3; i < size; ++i)
    {
        fourth.push_back(numbers[i]);
    }

    cout << endl;
    cout << "Highest quarter: ";
    for (int i = 0; i < fourth.size(); ++i)
    {
        cout << fourth[i] << " ";
    }

    cout << endl;
    cout << "2nd-highest quarter: ";
    for (int i = 0; i < third.size(); ++i)
    {
        cout << third[i] << " ";
    }

    cout << endl;
    cout << "3rd-highest quarter: ";
    for (int i = 0; i < second.size(); ++i)
    {
        cout << second[i] << " ";
    }

    cout << endl;
    cout << "Lowest quarter: ";
    for (int i = 0; i < first.size(); ++i)
    {
        cout << first[i] << " ";
    }
}

void Program_3_3()
{
    cout << "Please enter a series of words with no punctuation: ";

    vector<string> words;
    vector<int> counts;
    string currentWord;

    typedef vector<string>::size_type vsize;
    vsize size;

    while (cin >> currentWord)
    {
        size = words.size();

        int foundAtIndex = -1;
        for (vsize i = 0; i < size; ++i)
        {
            if (currentWord == words[i])
            {
                foundAtIndex = i;
            }
        }

        if (foundAtIndex >= 0)
        {
            counts[foundAtIndex]++;
        }
        else
        {
            words.push_back(currentWord);
            counts.push_back(1);
        }
    }

    size = words.size();
    cout << "Here is each word in the string and how many times it appears: " << endl;

    for (vsize i = 0; i < size; ++i)
    {
        cout << words[i] << " appears " << counts[i] << " times." << endl;
    }
}

void Program_3_4()
{
    cout << "Please enter a series of words with no punctuation: ";

    vector<string> words;
    string longest, shortest;
    string currentWord;

    typedef vector<string>::size_type vsize;
    vsize size;

    int loopIteration = 0;
    while (cin >> currentWord)
    {
        if (loopIteration == 0)
        {
            longest = shortest = currentWord;
        }
        else
        {
            if (currentWord.size() > longest.size())
            {
                longest = currentWord;
            }
            else if (currentWord.size() < shortest.size())
            {
                shortest = currentWord;
            }
        }

        loopIteration++;
    }

    size = words.size();
    cout << "The longest word is " << longest << endl;
    cout << "The shortest word is " << shortest << endl;
}

void Program_3_5()
{
    // ask for and read the student's name
    cout << "Please enter your first name, \nyour midterm and final exam grades, \nfollowed by "
            "your three homework "
            "grades: ";
    string name;
    vector<string> names;
    vector<double> grades;
    const int HW_COUNT = 3;

    while (cin >> name)
    {
        names.push_back(name);
        double midterm, final;
        double homeworkSum = 0.0;

        // ask for and read the midterm and final grades
        cin >> midterm >> final;

        for (int i = 0; i < HW_COUNT; ++i)
        {
            double grade;
            cin >> grade;
            homeworkSum += grade;
        }

        double grade = 0.2 * midterm + 0.4 * final + 0.4 * (homeworkSum / HW_COUNT);
        grades.push_back(grade);
    }

    cout << endl;

    typedef vector<string>::size_type vec_sz;
    for (vec_sz i = 0; i < names.size(); ++i)
    {
        cout << names[i] << "'s grade is " << grades[i] << endl;
    }
}

void Program_3_6()
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

    // the number and sum of grades read so far
    int count = 0;
    double sum = 0;

    // a variable into which to read
    double x;

    // invariant: we have read count grades so far, and sum is the sum of the first count grades
    while (cin >> x)
    {
        ++count;
        sum += x;
    }

    if (count == 0)
    {
        cout << "No homework grades were entered, treating it as if there was no homework." << endl;

        streamsize prec = cout.precision();
        cout << "Your final grade is " << setprecision(3)
             << 0.2 * midterm + 0.4 * final + 0.4 * 100.0 << setprecision(prec) << endl;
    }
    else
    {
        streamsize prec = cout.precision();
        cout << "Your final grade is " << setprecision(3)
             << 0.2 * midterm + 0.4 * final + 0.4 * sum / count << setprecision(prec) << endl;
    }
}


#endif // !CHAPTER_3_H
