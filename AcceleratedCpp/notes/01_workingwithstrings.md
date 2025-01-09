# Working with Strings (more stuff we know)

Use `std::cin >> variable_name` to read user input into a variable.

Example with string:
```c++
std::string stringVar; // Declares a variable of type std::string called stringVar
std::cin >> stringVar; // Writes user input into the stringVar variable
```

What is a variable? *An object that has a name.*

What is an object? *Part of computer memory that has a specific type*

Note: It is possible to have an object that doesn't have a name, so it's important to remember the difference between a variable and an object.

What is a __local variable__? 
* A variable whose scope (the context in which it has meaning) only exists within the bounds of a function, struct, or class's curly braces. 
* Once the program reaches the end of the curly brace, it destroys that variable. 
  * This is called *going out of scope*.

What is an __interface__?
* The collection of operations that are possible on an object of a particular type.

When we read a string with `std::cin`, it reads characters until it reaches a whitespace character or end of file. This is why if you type more than one word separated by spaces into `std::cin`, it only will store the first word of the input.

Concatenating strings:
```c++
std::string name = firstName + "last name"; // Using a '+' between a string and a string literal concatenates them.

// note that two string literals cannot be concatenated:
std::string name = "help" + "me"; // this is invalid and will produce an error
```

## Const

Const tells the compiler that, for as long as that variable is in scope, it will not be changed. If you then try to go and change it down the line it will produce a nice error!

## Calling Constructors

Objects can be constructed in the variable declaration with the following syntax:
```c++
TYPE VARIABLE_NAME(PARAM0, PARAM1, etc.);
```

## Member Functions

These are functions that are specified within a given type. Here is an example:

```c++
std::string name = "Bartley";
int size = name.size(); // size() is a member function of the type std::string
```

## Details

char:
* built in type that holds an ordinary character

wchar_t:
* built in type that holds a "wide character", which is big enough to hold characters for languages like Japanese.

std::string s;
* Defines s as a variable of type std::string that is initially empty.

std::string t = s;
* Defines t as a variable of type std::string that initially contains a copy
of the characters in s, where s can be either a string or a string literal.

std::string z(n, c);
* Defines z as a variable of type std::string that initially contains n copies
of the character c. Here, c must be a char, not a string or a string literal.

os << s
* Writes the characters contained in s, without any formatting changes, on the
output stream denoted by os. The result of the expression is os.

is >> s
* Reads and discards characters from the stream denoted by is until encountering
a character that is not whitespace. Then reads successive characters
from is into s, overwriting whatever value s might have had, until the next
character read would be whitespace. The result is is.

s + t
* The result of this expression is an std::string that contains a copy of the
characters in s followed by a copy of the characters in t. Either s or t, but
not both, may be a string literal or a value of type char.

s.size()
* The number of characters in s.