#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    cout << "Please enter two numbers, separated by a space: ";
    int num1, num2;
    cin >> num1 >> num2;
    if (num1 == num2)
        cout<< "They are the same size, you trickster!" << endl;
    else if (num1 > num2)
        cout<< "The first number is larger." << endl;
    else
        cout<< "The second number is larger." << endl;
    return 0;
}
