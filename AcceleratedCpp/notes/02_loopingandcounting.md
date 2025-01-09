# Looping and Counting (more stuff we already know)

The program we wrote in the previous chapter to ask for input and output a greeting had a problem: we wrote the output one line at a time, when we could have used loops to do it more easily.

We can think of our output as a rectangular array of characters, which we write one row at a time. We can try to compute the number of rows.

```c++
const in pad = 1; // number of blank rows surrounding the greeting
const int rows = pad * 2 + 3;
```

## The While Loop

```c++
while (CONDITION)
{
    STATEMENT;
}
```

A while loop executes code in the curly braces under the while over and over until the condition specified after while evaluates to true.

We could syntactically write the whole thing on one line but this is less readable:
```c++
// Note that STATEMENT could either be an expression followed by a semicolon,
// or a set of expressions enclosed in curly braces.
while (CONDITION) STATEMENT
```

`!=` is an *inequality operator*.

`++r` is using what's called an *increment operator*. This evaluates to `r = r + 1`

### What is a Loop Invariant?

> A property that we assert will be true about a while each time it is about to test its condition.

It can be helpful to write what the loop invariant is in a comment above the while:

```c++
// invariant: we have written r rows so far
int r = 0;
// setting r to 0 makes the invariant true
while (r != rows) {
    // we can assume that the invariant is true here

    // writing a row of output makes the invariant false
    std::cout << std::endl;

    // incrementing r makes the invariant true again
    ++r;
}
// we can conclude that the invariant is true here
```

## Writing a Row

`std::string::size_type` is a type we should use whenever we want to store the size of a string in a variable. We might not want to use `int` for the same purpose in case we receive input that is somehow longer than an `int` can contain.

> Whenever we define a variable that contains the size of a particular data structure, it is a good habit to use the type that the library defines as being appropriate for that specific purpose.

## If Statements

```c++
if (CONDITION)
    STATEMENT

if (CONDITION) STATEMENT

if (CONDITION)
    STATEMENT1
else
    STATEMENT2
```

If statements perform whatever is specified in the STATEMENT if the CONDITION evaluates to true.

`==` equality operator, true if the two operands are equal

`||` logical-or operator, true if *at least one* of the two operands are also true

`||` is left-associative, meaning:
```c++
if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
{
    // ...
}

// evaluates to
if (((r == 0 || r == (rows - 1)) || c == 0) || c == (cols - 1))
{
    // ...
}
```

`&&` logical-and operator, true if *both* of the operands are true

`+=` compound assignment operator, `c += x` evaluates to `c = c + x`

`using std::cout` at the top of the program is using what's known as a *using declaration*. It imports that particular namespace into your file, allowing you to omit the `std::` in `std::cout` statements, and just write `cout`.

## For Statements

```c++
for (INIT_STATEMENT; CONDITION; EXPRESSION) // for header
{   // for body
    STATEMENT;
}
```

We used a *half-open range* to specify the range of this for loop, denoted by `[begin, off-the-end)`. The range is asymmetric, meaning that it is left inclusive and right exclusive. In our program, the range is `[0, numRows)`.

## Types in this chapter:

bool
> Built-in type representing truth values; may be either trueor false

unsigned
> Integral type that contains only non-negative values

short
> Integral type that must hold at least 16 bits

long
> Integral type that must hold at least 32 bits

size_t
> Unsigned integral type (from <cstddef>) that can hold any object's size

string::size_type
> Unsigned integral type that can hold the size of any string