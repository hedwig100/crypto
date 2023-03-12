#include "euclid.hpp"
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/random.hpp>
#include <random>

namespace mp = boost::multiprecision;
namespace rc = residue_class;
using BigInt = mp::cpp_int;

namespace residue_class {

// miller_rabin returns true if n is estimated to be prime,
//              returns false if n is estimated to be composite.
bool miller_rabin(BigInt n, int t) {

    // random generator
    boost::mt19937 rng(3);
    boost::uniform_int<BigInt> gen(1, n - 1);

    // caluculate s,d
    BigInt s = 0, d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }

    for (int i = 0; i < t; i++) {
        BigInt a = gen(rng);

        if (rc::gcd(a, n) != 1) {
            return false;
        }

        bool is_composite = true;

        // first check
        BigInt b = rc::pow(a, d, n);
        if (b == 1 || b == n - 1) {
            is_composite = false;
        }

        // second check
        for (int j = 1; j < s; j++) {
            b = b * b % n;
            if (b == n - 1) {
                is_composite = false;
            }
        }

        if (is_composite) {
            return false;
        }
    }

    return true;
}

std::random_device seed_gen;
std::mt19937 engine(seed_gen());
std::uniform_int_distribution<> _rnd(0, 1);

// _make_random_k_bit_integer generate random k bit odd integer
BigInt _make_random_k_bit_integer(int k) {
    BigInt x = 0;
    mp::bit_set(x, 0);
    mp::bit_set(x, k - 1);
    for (int i = 1; i < k - 1; i++) {
        if (_rnd(engine) == 1) {
            mp::bit_set(x, i);
        }
    }
    return x;
}

// prime_gen generate k bit prime positive number
// t is times to try prime number
// miller_t is times to test miller rabin test
// if this function fails to generate prime number in t times, return -1
BigInt prime_gen(int k, int t = 10, int miller_t = 10) {
    for (int i = 0; i < t; i++) {
        BigInt trial_integer = _make_random_k_bit_integer(k);
        if (miller_rabin(trial_integer, miller_t)) {
            return trial_integer;
        }
    }
    return BigInt(-1);
}

} // namespace residue_class