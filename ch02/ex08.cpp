#include <iostream>

int main()
{
    int prod = 1;
    for (int i = 1; i < 10; i++) {
        prod *= i;
    }
    std::cout << "Product of [1,10) is: " << prod  << std::endl;
}
