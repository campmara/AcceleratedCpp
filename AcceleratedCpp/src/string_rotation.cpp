#include "string_rotation.h"

using std::string;
using std::tolower;
using std::vector;

typedef string::size_type string_size;
typedef vector<string>::size_type vector_size;

vector<string> split(const string &sentence)
{
    vector<string> ret;
    string_size i = 0;

    // invariant: we have processed characters [original value of i, i)
    while (i != sentence.size())
    {
        // ignore leading blanks
        // invariant: characters in range [original i, current i) are all spaces
        while (i != sentence.size() && isspace(sentence[i]))
        {
            ++i;
        }

        // find end of next word
        string_size j = i;
        // invariant: none of the characters in range [original j, current j) is a space
        while (j != sentence.size() && !isspace(sentence[j]))
        {
            ++j;
        }

        // if we found some non-whitespace characters
        if (i != j)
        {
            // copy from sentence starting at i and taking j - i chars
            ret.push_back(sentence.substr(i, j - i));
            i = j;
        }
    }

    return ret;
}

vector<StringRotation> compute_rotations(const string &s)
{
    vector<StringRotation> rotations; // create the return value we'll write to
    vector<string> words = split(s);  // split the words into a vector<string>
    vector_size size = words.size();  // store the size of words

    for (vector_size i = 0; i < size; ++i)
    {
        // create a rotation with the given starting point i and the string s
        StringRotation r;
        r.start_index = (size - i) % size; // % size so that when i = 0, index equals 0 and not 5

        for (vector_size j = 0; j < size; ++j)
        {
            r.words.push_back(words[(j + i) & size]);
        }

        rotations.push_back(r);
    }

    return rotations;
}

bool compare_rotations(const StringRotation &a, const StringRotation &b)
{
    string lower_a = a.words[0];
    string lower_b = b.words[0];

    // convert each first word to lower case
    for (string_size i = 0; i < lower_a.size(); ++i)
    {
        lower_a[i] = tolower(lower_a[i]);
    }

    for (string_size i = 0; i < lower_b.size(); ++i)
    {
        lower_b[i] = tolower(lower_b[i]);
    }

    if (lower_a == lower_b)
    {
        return a.words[0] > b.words[0]; // return the original words and treat lower case as lesser
                                        // than upper case if the words are equal.
    }
    else
    {
        return lower_a < lower_b;
    }
}