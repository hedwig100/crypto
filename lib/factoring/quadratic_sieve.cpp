#include "factoring.hpp"

namespace factoring {

QuadraticSieve::QuadraticSieve(BigInt n, BigInt m, int B, int C) : n(n), B(B), C(C) {
    m           = mp::sqrt(n);
    factor_base = residue_class::eratosthenes(B);
}

BigInt QuadraticSieve::f(BigInt x) {
    return (x + m) * (x + m) - n;
}

// root calculate zeros of f(x) = (x + m)^2 - n
// Fp is field, so there are at most 2 zeros.
std::vector<int> QuadraticSieve::root(int p) {
    std::vector<int> roots;
    for (int x = 0; x < p; x++) {
        if (f(BigInt(x)) == BigInt(0)) {
            roots.push_back(x);
            if (roots.size() == 2)
                return roots;
        }
    }
    return roots;
}

// sieve calculate sieve, which means factoring f(s) (s \in [-C,C]) with prime factor p less than B.
void QuadraticSieve::sieve() {
    std::vector<std::vector<int>> sieves_tmp(2 * C + 1, std::vector<int>(factor_base.size() + 1, 0));

    std::vector<BigInt> F(2 * C + 1);
    for (int s = -C; s <= C; s++) {
        F[s + C] = f(s);
    }

    for (int i = 0; i < (int)factor_base.size(); i++) {
        int p      = factor_base[i];
        auto roots = root(p);
        for (const int &r : roots) {

            // more than r
            for (int x = r; x <= C; x += p) {
                while (F[x + C] % p == 0) {
                    F[x + C] /= p;
                    sieves_tmp[x + C][i]++;
                }
            }

            // less than r
            for (int x = r - p; x >= -C; x -= p) {
                while (F[x + C] % p == 0) {
                    F[x + C] /= p;
                    sieves_tmp[x + C][i]++;
                }
            }
        }
    }

    for (int s = -C; s <= C; s++) {
        // not B-smooth
        if (mp::abs(F[s + C]) != 1) continue;

        sieves_tmp[s + C].back() = (F[s + C] < 0 ? 1 : 0);
        sieves.push_back(sieves_tmp[s + C]);
        candidate_s.push_back(s);
    }
}

} // namespace factoring