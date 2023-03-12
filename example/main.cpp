#include "prime_gen.hpp"
#include <iostream>

int main() {
    auto x = residue_class::prime_gen_must(1024, 10);
    std::cout << x << '\n';
}