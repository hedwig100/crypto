#include "prime_gen.hpp"
#include <iostream>

int main() {
    auto x = residue_class::prime_gen(128, 20, 10);
    std::cout << x << '\n';
}