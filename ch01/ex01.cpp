// ask for a person's name and greet the person
#include <iostream>
#include <string>

int main()
{
    std::cout << "Please enter your first name: ";
    // read the name
    std::string name;  // define the name
    std::cin >> name;  // read the name

    // write a greeting
    std::cout << "Hello, " << name << "!" << std::endl;
    return 0;
}
