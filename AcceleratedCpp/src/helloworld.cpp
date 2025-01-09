#include <iostream>
#include <string>

void HelloWorldProgram()
{
    std::cout << "Hello, world!" << std::endl;
    std::cout << "This (\") is a quote, and this (\\) is a backslash." << std::endl;
    std::cout << "\t This is a tabbed line." << std::endl;

    std::cout << "int main()\n{\n    std::cout << \"Hello, world!\" << std::endl;\n}" << std::endl;

    std::cout << "H\ne\nl\nl\no\n,\n \nw\no\nr\nl\nd\n!\n" << std::endl;
}

void InputProgram()
{
    // Ask for name
    std::cout << "Please enter your first name: ";

    // Read name input
    std::string name;
    std::cin >> name;

    // Write the greeting
    std::cout << "Hello, " << name << "!" << std::endl;
}

void FramedInputProgram()
{
    std::cout << "Please enter your first name: ";
    std::string name;
    std::cin >> name;

    // build the message that we intend to write
    const std::string greeting = "Hello, " + name + "!";

    // build the second and fourth lines of the output
    const std::string spaces(greeting.size(), ' ');
    const std::string second = "* " + spaces + " *";

    // build the first and fifth lines of the output
    const std::string first(second.size(), '*');

    // write it all
    std::cout << std::endl;
    std::cout << first << std::endl;
    std::cout << second << std::endl;
    std::cout << "* " << greeting << " *" << std::endl;
    std::cout << second << std::endl;
    std::cout << first << std::endl;
}

void Program_1_4()
{
    {
        const std::string s = "a string";
        std::cout << s << std::endl;
        {
            const std::string s = "another string";
            std::cout << s << std::endl;
        }
    }
}

void Program_1_5()
{
    {
        std::string s = "a string";
        {
            std::string x = s + ", really";
            std::cout << s << std::endl;
            std::cout << x << std::endl;
        }
    }
}

void Program_1_6()
{
    std::cout << "What is your name? ";
    std::string name;
    std::cin >> name;
    std::cout << "Hello, " << name << std::endl << "And what is yours? ";
    std::cin >> name;
    std::cout << "Hello, " << name << "; nice to meet you too!" << std::endl;
}

int main()
{
    Program_1_6();
    return 0;
}