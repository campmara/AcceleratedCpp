#ifndef CHAPTER_2_H
#define CHAPTER_2_H

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

void FramedInputProgramWithLoops()
{
    cout << "Please enter your first name: ";
    string name;
    cin >> name;

    // build the message that we intend to write
    const string greeting = "Hello, " + name + "!";

    // build the second and fourth lines of the output
    const string spaces(greeting.size(), ' ');
    const string second = "* " + spaces + " *";

    // build the first and fifth lines of the output
    const string first(second.size(), '*');

    const int pad = 1;
    const int numRows = pad * 2 + 3;
    const string::size_type numCols = greeting.size() + pad * 2 + 2;

    cout << endl;

    int r = 0;
    // loop invariant: we have written r rows so far
    for (int r = 0; r < numRows; ++r)
    {
        // write a row of output
        string::size_type c = 0;

        // invariant: we have written c characters so far in the current row
        while (c != numCols)
        {
            // should we write the greeting?
            if (r == pad + 1 && c == pad + 1)
            {
                cout << greeting;
                c += greeting.size();
            }
            else
            {
                // are we on the border?
                if (r == 0 || r == numRows - 1 || c == 0 || c == numCols - 1)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
                ++c;
            }
        }

        cout << endl;
    }
}

void Program_2_2()
{
    cout << "Please enter your first name: ";
    string name;
    cin >> name;

    // build the message that we intend to write
    const string greeting = "Hello, " + name + "!";

    // build the second and fourth lines of the output
    const string spaces(greeting.size(), ' ');
    const string second = "* " + spaces + " *";

    // build the first and fifth lines of the output
    const string first(second.size(), '*');

    const int padRows = 3;
    const int padCols = 2;
    const int numRows = padRows * 2 + 3;
    const string::size_type numCols = greeting.size() + padCols * 2 + 2;

    cout << endl;

    int r = 0;
    // loop invariant: we have written r rows so far
    for (int r = 0; r < numRows; ++r)
    {
        // write a row of output
        string::size_type c = 0;

        // invariant: we have written c characters so far in the current row
        while (c != numCols)
        {
            // should we write the greeting?
            if (r == padRows + 1 && c == padCols + 1)
            {
                cout << greeting;
                c += greeting.size();
            }
            else
            {
                // are we on the border?
                if (r == 0 || r == numRows - 1 || c == 0 || c == numCols - 1)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
                ++c;
            }
        }

        cout << endl;
    }
}

void Program_2_3()
{
    cout << "Please enter your first name: ";
    string name;
    cin >> name;

    cout << endl;
    cout << "Please enter the padding coefficient: ";
    int pad;
    cin >> pad;

    // build the message that we intend to write
    const string greeting = "Hello, " + name + "!";

    // build the second and fourth lines of the output
    const string spaces(greeting.size(), ' ');
    const string second = "* " + spaces + " *";

    // build the first and fifth lines of the output
    const string first(second.size(), '*');

    const int numRows = pad * 2 + 3;
    const string::size_type numCols = greeting.size() + pad * 2 + 2;

    cout << endl;

    int r = 0;
    // loop invariant: we have written r rows so far
    for (int r = 0; r < numRows; ++r)
    {
        // write a row of output
        string::size_type c = 0;

        // invariant: we have written c characters so far in the current row
        while (c != numCols)
        {
            // should we write the greeting?
            if (r == pad + 1 && c == pad + 1)
            {
                cout << greeting;
                c += greeting.size();
            }
            else
            {
                // are we on the border?
                if (r == 0 || r == numRows - 1 || c == 0 || c == numCols - 1)
                {
                    cout << "*";
                }
                else
                {
                    cout << " ";
                }
                ++c;
            }
        }

        cout << endl;
    }
}

void Program_2_4()
{
    cout << "Please enter your first name: ";
    string name;
    cin >> name;

    // build the message that we intend to write
    const string greeting = "Hello, " + name + "!";

    // build the second and fourth lines of the output
    const string spaces(greeting.size(), ' ');
    const string second = "* " + spaces + " *";

    // build the first and fifth lines of the output
    const string first(second.size(), '*');

    const int pad = 3;
    const int numRows = pad * 2 + 3;
    const string::size_type numCols = greeting.size() + pad * 2 + 2;

    cout << endl;

    int r = 0;
    // loop invariant: we have written r rows so far
    for (int r = 0; r < numRows; ++r)
    {
        // write a row of output
        string::size_type c = 0;

        // invariant: we have written c characters so far in the current row
        while (c != numCols)
        {
            // should we write the greeting?
            if (r == pad + 1 && c == pad + 1)
            {
                cout << greeting;
                c += greeting.size();
            }
            else
            {
                // are we on the border?
                if (r == 0 || r == numRows - 1 || c == 0 || c == numCols - 1)
                {
                    cout << "*";
                    ++c;
                }
                else
                {
                    string padOutput("");
                    int paddingNeeded = r == pad + 1 ? pad : numCols - 2;
                    for (int i = 0; i < paddingNeeded; ++i)
                    {
                        padOutput += " ";
                    }
                    cout << padOutput;
                    c += padOutput.size();
                }
            }
        }

        cout << endl;
    }
}

void Program_2_5()
{
    // square
    const int squareWidth = 5;

    for (int x = 0; x < squareWidth; ++x)
    {
        for (int y = 0; y < squareWidth; ++y)
        {
            // Are we on the border?
            if (x == 0 || x == squareWidth - 1 || y == 0 || y == squareWidth - 1)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    // rectangle
    cout << endl;
    const int rectWidth = 10;
    const int rectHeight = 3;

    for (int x = 0; x < rectHeight; ++x)
    {
        for (int y = 0; y < rectWidth; ++y)
        {
            // Are we on the border?
            if (x == 0 || x == rectHeight - 1 || y == 0 || y == rectWidth - 1)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }

    // triangle
    cout << endl;
    const int triangleWidth = 8;
    const int triangleHeight = 5;

    int starOffsetFromCenter = 0;
    int halfPos = triangleWidth / 2;

    for (int x = 0; x < triangleHeight; ++x)
    {
        for (int y = 0; y < triangleWidth; ++y)
        {
            // Are we on the edge of the triangle?
            if (x == triangleHeight - 1 || y == halfPos - starOffsetFromCenter ||
                y == halfPos + starOffsetFromCenter)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
        starOffsetFromCenter++;
    }
}

void Program_2_7()
{
    for (int i = 10; i >= -5; --i)
    {
        cout << i << endl;
    }

    cout << "OR!!!" << endl;

    int i = 10;
    while (i >= -5)
    {
        cout << i << endl;
        --i;
    }
}

void Program_2_8()
{
    int product = 1;
    for (int i = 1; i < 10; ++i)
    {
        product *= i;
    }

    cout << "Product of numbers in the range [1, 10): " << product << endl;
}

void Program_2_9()
{
    cout << "Enter a number: ";
    int first;
    cin >> first;

    cout << endl;
    cout << "Enter another number: ";
    int second;
    cin >> second;

    if (first > second)
    {
        cout << first << " is larger than " << second << endl;
    }
    else if (first < second)
    {
        cout << second << " is larger than " << first << endl;
    }
    else
    {
        cout << "The numbers are equal!";
    }
}



#endif