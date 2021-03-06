#include <iomanip>
#include <iostream>
static const size_t num_elems = 1000;

int main() {

    int test_val = num_elems - 1;
    test_val *= test_val;
    size_t width = 1; // make sure we leave a space
    while(test_val != 0) {
        width++;
        test_val /= 10;
    }
    for (int i = 0; i < num_elems; i++)
        std::cout << i << std::setw(width) << i * i << std::endl;

    return 0;
}
