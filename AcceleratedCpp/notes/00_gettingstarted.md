# Getting Started (we know all this already)

Comments are denoted with `// comment here` or `/* comment here */` and are readability and organizational tools for your program. Use comments to specify to readers peculiarities about your code so that they can better understand *why* it works the way it does.

Items from the C++ standard library are included in the program via `#include <header_name>` at the top of a file. These refer to a part of the C++ standard library and are called *standard headers*.

Every program must include an `int main()` function, which acts as the entry point for the program. The `int` return value is 0 for success, and any other number for something wrong happening to the program.

Every function you write must be contained within *curly braces*, like so:
```c++
void Foo(int bar) // Function declaration
{                 // Start curly brace
                  // Whatever this function does lies between the braces.
}                 // End curly brace
```

In a `std::cout` call, the `<<` operator is the standard library's *output operator*.

The characters preceding `cout`, being `std::` indicate that `cout` is part of the `std` *namespace*. Namespaces are collections of related names (functions, classes, etc.).

Any return value other than void must return a value of that return type. Return ends processing of the function.

*Expressions* contain both operators (+, -, <<, etc.) and operands (things that the operators, well, operate on). Every operand has a *type*.

Every expression statement must end with a semicolon `;`.

Types have names. `int` is the type that represents integers. `std::ostream` is the type of the `std::cout` operand.

The `<<` operator is *left-associative*, meaning the operator will consolidate what's to the left of it first in order to evaluate the operation on the right. So, the order of operations for this expression:

`std::cout << "Hello, world!" << std::endl;`
 
will evaluate to:

`(std::cout << "Hello, world!") << std::endl;`

The `std::endl` operand is known as a *manipulator*, which means it manipulates the stream specified in `std::cout` in some way.

`std::cout` is what's known as a *qualified name*.

The `::` operator is known as a *scope operator*. *Scope* is the context in which a name has meaning. `cout` without the preceding `std::` means nothing to our program.

There is also what's known as *function scope*, which is a scope that exists within the context of two curly braces.

## String Literals

`"Hello, world"`, being a set of characters between quotes, is what's known as a *string literal*.

Some characters in a string literal have special functionality when preceded by a backslash `\`. Some of them look like this:
* `\n` newline
* `\t` tab
* `\b` backspace
* `\"` treat this quote as part of the string and not the terminator of it
* `\'` same meaning as `\"` in string literals, for consistency with char literals
* `\\` includes a `\` in the string