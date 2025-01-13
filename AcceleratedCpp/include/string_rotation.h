#ifndef STRING_ROTATION_H
#define STRING_ROTATION_H

#include <string>
#include <vector>
#include <cctype>

struct StringRotation
{
    std::vector<std::string> words;
    std::vector<std::string>::size_type start_index;
};

std::vector<std::string> split(const std::string &sentence);
std::vector<StringRotation> compute_rotations(const std::string &s);
bool compare_rotations(const StringRotation &a, const StringRotation &b);

#endif // !STRING_ROTATION_H
