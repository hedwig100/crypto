#include "euclid.hpp"
#include <iostream>

int main() {
    int x, y;
    std::cout << residue_class::extgcd(1, 2, x, y) << '\n';
}