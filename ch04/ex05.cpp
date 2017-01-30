#include <iostream>
#include <vector>

double vector_avg(const std::vector<double>& vec) {
    double total = 0;
    for (auto& d: vec) {
        total += d;
    }
    return total/vec.size();
}
int main() {
    std::vector<double> testvec = {1.0, 2.0, 3.0, 3.5, 4.5};
    std::cout << "average of testvec: " << vector_avg(testvec) << std::endl;
    return 0;
}
