#include "factoring.hpp"
#include <iostream>

int main() {
    BigInt n     = 235789209357;
    auto [ok, f] = factoring::p_minus_1(n, 10);
    std::cout << ok << ' ' << f << ' ' << n % f << '\n';
}