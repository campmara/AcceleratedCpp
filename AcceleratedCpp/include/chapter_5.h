#ifndef CHAPTER_5_H
#define CHAPTER_5_H

#include "student_info.h"
#include "compute_grade.h"
#include "string_rotation.h"

#include <vector>
#include <string>
#include <cctype>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::getline;

void test_split_string()
{
    string s;

    while (getline(cin, s))
    {
        vector<string> v = split(s);

        // write each word in v
        for (vector<string>::size_type i = 0; i != v.size(); ++i)
        {
            cout << v[i] << endl;
        }
    }
}

void test_library_split()
{
    string s;
    while (cin >> s)
    {
        cout << s << endl;
    }
}

string::size_type width(const vector<string>& v)
{
    string::size_type max_len = 0;

    for (vector<string>::size_type i = 0; i != v.size(); ++i)
    {
        max_len = std::max(max_len, v[i].size());
    }

    return max_len;
}

vector<string> frame(const vector<string>& v)
{
    vector<string> ret;
    string::size_type max_len = width(v);
    string border(max_len + 4, '*');

    // write the top border
    ret.push_back(border);

    // write each iterator row, bordered by an asterisk and a space
    for (vector<string>::size_type i = 0; i != v.size(); ++i)
    {
        ret.push_back("* " + v[i] + string(max_len - v[i].size(), ' ') + " *");
    }

    // write the bottom border
    ret.push_back(border);
    return ret;
}

vector<string> v_cat(const vector<string>& top, const vector<string>& bottom)
{
    // copy the top picture
    vector<string> ret = top;

    // copy entire bottom picture
    /* We could have done this, but what follows is shorthand for this:
    for (vector<string>::const_iterator it = bottom.begin(); it != bottom.end(); ++it)
    {
        ret.push_back(*it);
    }
    */

    ret.insert(ret.end(), bottom.begin(), bottom.end());

    return ret;
}

vector<string> h_cat(const vector<string>& left, const vector<string>& right) 
{
    vector<string> ret;

    // add 1 to leave a space between pictures
    string::size_type width1 = width(left) + 1;

    // indices to look at elements from left and right respectively
    vector<string>::size_type i = 0, j = 0;

    // continue until we've seen all rows from both pictures
    while (i != left.size() || j != right.size())
    {
        // construct a new string to hold characters from both pictures
        string s;

        // copy a row from the left hand size, if there is one
        if (i != left.size())
        {
            s = left[i++];
        }

        // pad to full width
        s += string(width1 - s.size(), ' ');

        // copy a row from the right hand side, if there is one
        if (j != right.size())
        {
            s += right[j++];
        }

        // add s to the picture we're creating
        ret.push_back(s);
    }

    return ret;
}

void program_5_1()
{

}

#endif // !CHAPTER_5_H
