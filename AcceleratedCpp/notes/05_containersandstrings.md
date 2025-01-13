# Using Sequential Containers and Analyzing Strings

The stl is constructed so that working with similar container types has a consistent and intuitive interface for doing so. For example, a lot of the operations that we've been doing on vectors, we can also be doing on strings!

`vector` element removal is SLOW! Be careful using it at scale.

`vector` has no `erase` function that supports indices. We must use iterators to remove things. Syntax:

```c++
// students is a vector<StudentInfo>
students.erase(students.begin() + i);
```
In this example, we indicate what element to erase in `students` by adding an integer value to the iterator returned by the `students.begin()` function.

`vector<T>::size()` is usually a pretty fast call.

By using an `int` to index into a vector, we implicitly are saying that even though we might be accessing vector elements sequentially, we theoretically could be accessing elements anywhere in the vector.

Sometimes it might be better to restrict your functions to sequential access of the vectors it operates on. To that end, C++ offers the `iterator`.

## Iterators

An `iterator` is a value that:
* identifies a container and an element within that container
* lets us examine the value stored in an element
* provides operations for moving between elements in the container
* restricts the available operations in ways that correspond to what the container can handle efficiently

Example with `StudentInfo`:
```c++
for (vector<StudentInfo>::const_iterator iter = students.begin(); iter != students.end(); ++iter)
{
    cout << (*iter).name << endl;
}
```

Every standard container implements `container-type::const_iterator` and `container-type::iterator`. If we want to use an iterator to change the container values, we use `iterator`, and if we only need read-only access we use `const_iterator`.

We can assign an iterator from `students.begin()` or `students.end()` to a `const_iterator` because the return type of those two functions is a regular `iterator`. A regular iterator can be assigned to a const_iterator, but not the other way around. Remember this!

We can compare iterators with const_iterators and the implementation knows how to handle this. (Was probably done with operator overloading).

`dereference operator` is the `(*iter)` that we use in the above example. This is how we access the individual element in the students vector. When we apply the `*` operator to an iterator, it returns an lvalue which is the element to which the iterator refers.

Also note the parentheses. The `.` operator has higher precedence than `*`, so the parentheses forces the dereference operator to evaluate first, allowing us to access element properties after the dot.

### Syntax sugar on that dereference operator

This sort of operation is exceedingly common. Because of this, there is another operator that does the same thing with less characters and annoyance: `->`.

```c++
(*iter).name;

// is the same as writing
iter->name;
```

Remember that if you're calling `erase` on a vector with an iterator that the erase function invalidates that iterator. In order to keep using that iterator, you can instead assign the iterator to the result of this function, like so:

```c++
iter = students.erase(iter); // returns an iterator that points to the element that follows the one just erased
```

`vector::erase()` also invalidates any iterators pointing at elements past what was erased. So be careful trying to store `vector::end()` in an iterator and then calling `vector::erase()`!

## `std::list`

Vectors are optimized for fast random access. But lists are optimized for fast insertion and deletion anywhere within the container. This makes them ideal for situations where we need to do a lot of adding and removing in the middle of a container.

They are slower than vectors if you only access them sequentially, remember this!

Vectors and lists share many operations, so it can sometimes be an easy optimization to switch between them as the requirements of your program change.

Lists do not support indexing with `[]`.

## Differences between `std::vector` and `std::list`

`std::vector`:
* when using `vector::erase()`, we invalidate all iterators pointing at elements past the erased element.
* using `vector::push_back()` invalidates all iterators pointing to the entire vector.
  * the vector might be reallocated in this instance which is why the iterators get invalidated.

You have to be careful when saving `vector::start()` and `vector::end()` to variables!

`std::list`:
* `list::erase()` and `list::push_back()` do not invalidate iterators.
* only iterators that refer to an erased element in `erase()` are invalidated.
* you cannot use `sort()` on a list because lists do not support full random access.
  * however, the list class provides its own `list::sort()` function instead.

### Data structure choices matter for performance!!!!

Example performance data between `list` and `vector`:

| File size | list | vector |
| --------- | ---- | ------ |
| 735       | 0.1  | 0.1    |
| 7,350     | 0.8  | 6.7    |
| 73,500    | 8.8  | 597.1  |

## Taking `std::string` Apart

Strings can be operated on in similar ways to vectors! They implement iterators, and can also be indexed.

`<cctype>` header defines a function called `isspace()` which takes a char and returns a value that indicates whether or not that char is whitespace.

The `!` operator is known as the *logical negation* operator.

## `<cctype>` header functions

* `isspace(c)` true if c is a whitespace character.
* `isalpha(c)` true if c is an alphabetic character.
* `isdigit(c)` true if c is a digit character.
* `isalnum(c)` true if c is a letter or a digit.
* `ispunct(c)` true if c is a punctuation character.
* `isupper(c)` true if c is an uppercase letter.
* `islower(c)` true if c is a lowercase letter.
* `toupper(c)` Yields the uppercase equivalent to c
* `tolower(c)` Yields the lowercase equivalent to c