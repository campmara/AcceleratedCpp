# Working With Batches of Data

`<ios>` header defines `streamsize`, which is the size type for the input output library.

`<iomanip>` header defines `setprecision` manipulator, which lets us specify the amount of significant digits we want our output to contain.

Most io manipulators reside in the `<iomanip>` header, but `endl` is used so often it was placed in `<iostream>` instead.

End-of-file signal: begin a new line of input, hit `ctrl+z` on windows or `ctrl+d` on unix / linux systems.

`double`: a builtin type for double-precision floating point numbers.

`float`: a builtin type for single-precision floating point numbers.

This book says that double is better to use than float, and that sometimes it's even faster. That doesn't really make much sense to me, as I've been using floats as a best practice in games for years with no significant drawbacks.

```c++
cin >> midterm >> final;

// is the same as:
cin >> midterm;
cin >> final;
```

String literals that are next to each other in the program will be automatically concatenated by the compiler. Example:
```c++
cout << "Here is the first string literal, "
        "followed by a second string literal."

// is the same as writing:
cout << "Here is the first string literal, followed by a second string literal."
```

## Default Initialization

If we don't give variables an initial value when declared, like so: `int count;`, the compiler uses a `default initialization` to fill the variable with a default value. We can avoid this by specifying a value, like the following: `int count = 0;`.

This is fine in the case of declaring a class maybe, as it will call the default constructor and as long as that is set up properly the value will be initialized, but in the cast of built-in types (like `int`, `double`, `float`, etc.) the behavior is different.

Local variables of a built-in type that are not explicitly initialized are `undefined`. This means that whatever memory the variable is currently pointing to is most likely *garbage*. It is illegal in C++ to do anything with an undefined value except to overwrite it with a valid value. Some compilers don't prevent you from doing this however, and accessing a variable that is undefined will lead to a crash.

Random Note: if we initialize a `double` with an `int`, like so: `double d = 0;`, the variable will still be initialized and the compiler will most likely perform a compile-time conversion of that value to the desired type.

## Other Notes

Arithmetic operations in a conditional evaluate to true if the number is nonzero, and false if the number is 0.

We were able to use `cin >> x` in a while loop conditional because there is a conversion within the `istream` class that allows it to be converted to a bool.

`cin` will evaluate to false in the following cases:
* reached the end of input file
* encountered input which is incompatible with the type of the variable we're trying to read into
* hardware failure on the input device

## Vectors

If we ever need to store similar values in one collection, `<vector>` is available for us to use. It is an array type that grows and shrinks as needed to fit the number of elements. All of the values in an individual vector are the same type.

The vector type uses what's known as *template classes* to achieve its type-agnosticism. This is similar to generics in c# but works a little differently.

`vector::push_back()` pushes a value onto the end of the collection, increasing the size by one.

## Typedefs

If a type is ever unwieldy to write it can sometimes be useful to use a `typedef` statement. This can be done either globally or locally in your functions.

```c++
// example: creates a NEW_TYPE_NAME typedef linked to TARGET_TYPE.
typedef TARGET_TYPE NEW_TYPE_NAME

// now, using NEW_TYPE_NAME will be analogous to using TARGET_TYPE.

// another example: this creates a uint32 typedef that compiles down to 'unsigned int' at compile time.
typedef unsigned int uint32;
```

## std::sort

The `<algorithm>` header defines a bunch of useful algorithms (these are probably slow for games). One such algorithm is a basic sort function that can sort a vector's elements.

```c++
std::sort(homework.begin(), homework.end()); // .begin() and .end() signify the beginning and end points of the homework vector
```

`sort` is guaranteed to run in *n*log(*n*) time.

## More random notes

`%` operator returns the remainder that results from dividing the left operand by the right operand.

`? :` operator is a conditional operator. also known as the *ternary operator*.

If ordinary integers and unsigned integers combine in an expression, the ordinary integer gets converted to unsigned.