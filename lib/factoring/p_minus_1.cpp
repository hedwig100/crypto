#include "factoring.hpp"

namespace factoring {

BigInt generate_k(int B) {
    auto primes = residue_class::eratosthenes(B);

    BigInt k = 1;
    for (const int &p : primes) {
        BigInt pp = p;
        while (pp * BigInt(p) <= B)
            pp *= p;
        k *= pp;
    }
    return k;
}

// p_minus_1 factor n and return if p_minus_1 method succeded and factor
// when B is large, computation costs too much. B is about 10.
std::pair<bool, BigInt> p_minus_1(BigInt n, int B) {
    BigInt k = generate_k(B);
    cryptorandom::RandomGenerator<BigInt> rnd(2, n - 1);
    BigInt factor = residue_class::gcd(residue_class::pow(rnd.generate(), k) - 1, n);
    return std::make_pair(factor < n, factor);
}

} // namespace factoring