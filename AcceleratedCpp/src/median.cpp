#include <algorithm>
#include <stdexcept>

#include <median.h>

// using directives like these are probably fine to use in a .cpp file, but notice how the .h file
// does not specify them? perhaps it is a best practice not to put using directives in a header
// file!
using std::domain_error;
using std::sort;
using std::vector;

/// <summary>
/// Compute the median of a vector of doubles. Note that calling this function copies the vector.
/// </summary>
double Median(vector<double> vec)
{
    typedef vector<double>::size_type vsize;
    vsize size = vec.size();

    if (size == 0)
    {
        throw domain_error("Tried to calculate the median of an empty vector. This cannot be.");
    }

    sort(vec.begin(), vec.end());

    vsize mid = size / 2;

    return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}