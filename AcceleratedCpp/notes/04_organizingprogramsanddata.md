# Organizing Programs and Data

## Functions

Functions allow us to repeat functionality without having to rewrite code.

Functions have a name, which forces us to think about the computations performed there more abstractly. What is this function doing? How does the name communicate that? Is it communicating most effectively?

Function syntax:
```c++
RETURN_TYPE FUNCTION_NAME(PARAM_TYPE PARAM0, PARAM_TYPE PARAM1, ...)
{
    // Do something...

    return OBJECT_OF_RETURN_TYPE;
}
```

The parameters specified after the parentheses are called the *parameter list*.

Calling the function then has the following syntax:

```c++
RETURN_TYPE objectName = FUNCTION_NAME(PARAM0, PARAM1, ...);
```

When we fill those parentheses with different objects, we are supplying it with function *arguments*.

Arguments don't have to just be variables, they can also be expressions, like `sum / count` being supplied for the homework argument in the grade function.

## Throwing Exceptions

Sometimes when user input is incorrect, we need to express that gracefully to the user. One way (albeit a controversial way) is to throw an exception. When we throw, execution stops in that part of the program and passes to another part of the program, taking with it an *exception object*.

The problem with exceptions, however, is that once you use an exception in one place, then your entire program has to use them, and exceptions can slow things down!

## Pass By Value (copying)

When we pass values through function arguments without &, we are passing them *by value*. This means that whatever is passed in is copied through the function, and your function acts on only a copy of that data. This allows us to do things like `sort()` without worrying about influencing the vector that's coming in in the `median(vector<double> vec)` function. The thing to be careful of, however, is that passing by value can sometimes be an expensive operation if the value being passed is huge. Copying takes cycles!

## Pass By Reference

If we want to pass a value through a function without copying, we have to specify that by using the *reference operator* before the variable name in the function parameter, like so:

```c++
// The homework variable is specified const and passed by value with &
double ComputeGradeWithMedian(double midterm, double final, const vector<double> &homework)
{
    if (homework.size() == 0)
    {
        throw domain_error("Student has no homework grades.");
    }

    return ComputeGrade(midterm, final, ComputeMedian(homework));
}

// Then call the function like so:
double finalGrade = ComputeGradeWithMedian(midterm, final, &homework);
```

Through the reference operator, we can create variables that are *synonyms* for other variables, like so:

```c++
vector<double> homework;
vector<double> &homeworkSynonym = homework; // synonymous with homework, or homeworkSynonym is another name for homework.

// anything we do now to &homeworkSynonym is equivalent to doing the same thing to homework.
```

If we add a const to the mix, we make the reference read-only:

```c++
// chw is a read only synonym for homework! we are promising we won't change its internal data! the compiler will enforce this!
const vector<double> &chw = homework;
```

There is no such thing as a reference to a reference. It will still refer to that original piece of memory:

```c++
// hw1 and chw1 are synonyms for homework; chw1 is read-only
vector<double>& hw1 = hw;
const vector<double>& chw1 = chw;
```

If we define a non-const reference, we cannot make it refer to a const object or reference.

```c++
const vector<double> &chw = homework;
vector<double> &hw2 = chw; // this is illegal. it will produce an error.
```

Specifying a `const` parameter in a function means we can call this function with both const and non-const values and the parameter promises not to modify the data coming in.

## Overloading Functions

Specifying two different functions with the same name but different parameter lists is called *overloading* that function. This is perfectly legal in C++.

## Multiple return values? Not possible in the way you expect!

If we want to return more than one value in a function, it is very common to specify a reference parameter that more output will be written to, on top of the function's return type.

```c++
istream& ReadHomework(istream& in, vector<double>& hw) // hw is written to in this function, so it is, in essence, returned!
{
    // read the homework

    return in;
}
```

A reference parameter without the `const` modifier is usually a signal of intent to modify the object that is the function's argument!

## lvalue

We cannot call a function that uses a reference parameter with just any expression. Instead, we have to pass an `lvalue` argument.

### `lvalue`: a value that denotes a non-temporary object.
* a variable is an lvalue
* a reference is an lvalue
* the result of a function that returns a reference is an lvalue.

An expression that generates an arithmetic value, such as `sum / count`, is not an lvalue, and therefore cannot be passed by reference.]

Arguments that are passed by value can really be any value!

So this is perfectly legal:

```c++
vector<double> emptyvec()
{
    vector<double> v; // no elements
    return v;
}

grade(midterm, final, emptyvec()); // because the last parameter of the grade function is of type vector<double> passed by value, this is legal.

// but in the case of the ReadHomework function, we cannot do the same thing, as it expects a reference parameter, which means anything passed in must be an lvalue
ReadHomework(cin, emptyvec()); // this is illegal, and the compiler will complain.
```

## pass by const reference

This is a really useful thing to do if you can ensure that your functions won't change the argument being passed and doesn't need to copy the data for whatever reason.

Doing this with builtin types like `int` or `double` is usually not worth the trouble as they're small enough that it's really fast to pass them by value anyway!

## try-catch blocks

We can use try catch blocks when dealing with exceptions to 'catch' those exceptions and handle them in the catch block. Anything that you call or do in the try block that produces an exception will carry that exception over to the catch block and you can use that information to 'fail gracefully' or whatever.

Be careful with where you call functions that produce exceptions in the try block. If we were to call `ComputeGrade()` within the `cin` calls the exceptions might not work as intended based on the C++ implementation used.

A good rule of thumb is to avoid more than one side effect in a single statement. Throwing an exception is a side effect!

## structs!

We can define a struct to hold a lot of arbitrary data so that it is all collected in one place! Super useful. Here is the syntax:

```c++
struct STRUCT_NAME
{
    TYPE MEMBER_VARIABLE0;
    TYPE MEMBER_VARIABLE1;
    // etc.
}; // note the semicolon
```

## sorting a vector of a custom type?

In order for the sort function to work on a vector, it uses the `<` operator to do so, which for custom types you will either have to overload yourself, or specify a separate `predicate` function as the third argument for the `sort()` function.

other note: you can compare two strings with `<`-type operators.

## `<algorithm>`'s `std::max`

The arguments of `max` must have the same type!

## Header and Implementation Files

We can take functions and data structures and put them into their own .h and .cpp files, in order to improve project organization.

When we `#include` a header file with double quotes instead of angle brackets, we are saying to the compiler to copy the entire contents of the header file into our program in place of the #include directive.

To specify a function signature in a header file but not implement the functionality is to *declare* the function. Generally, headers should contain only declarations and all the functionality should be implemented in .cpp files. Generally... Also in a function declaration we don't need to name the function parameters, just specify the type... yikes...

IMPORTANT: HEADER FILES SHOULD NOT HAVE USING DECLARATIONS IN THEM!

## Include Guards

Syntax:
```c++
#ifndef FILE_NAME_H
#define FILE_NAME_H

// header file goes here.

#endif
```

The `#define` macro defines a *preprocessor variable*. Go somewhere else to find out what the heck this means.

The include guard must be the *first* lines of code in a header file. MUST!

