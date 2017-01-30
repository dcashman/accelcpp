#include <iomanip>
#include <iostream>

int main() {
    for (int i = 0; i < 1000; i++)
        std::cout << i << std::setw(3) << i * i << std::endl;
    return 0;
}
