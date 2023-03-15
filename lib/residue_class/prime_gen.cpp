#include "euclid.hpp"
#include "random.hpp"
#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;
namespace rc = residue_class;
using BigInt = mp::cpp_int;

namespace residue_class {

// miller_rabin returns true if n is estimated to be prime,
//              returns false if n is estimated to be composite.
bool miller_rabin(BigInt n, int t) {

    // random generator
    cryptorandom::RandomGenerator<BigInt> generator(1, n - 1);

    // caluculate s,d
    BigInt s = 0, d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }

    for (int i = 0; i < t; i++) {
        BigInt a = generator.generate();

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

// prime_gen generate k bit prime positive number
// t is times to try prime number
// miller_t is times to test miller rabin test
// if this function fails to generate prime number in t times, return -1
BigInt prime_gen(int k, int t = 10, int miller_t = 10) {
    for (int i = 0; i < t; i++) {
        BigInt trial_integer = cryptorandom::generate_kbit_integer(k);
        if (miller_rabin(trial_integer, miller_t)) {
            return trial_integer;
        }
    }
    return BigInt(-1);
}

// prime_gen_must generate k bit prime positive number
// miller_t is times to test miller rabin test
BigInt prime_gen_must(int k, int miller_t = 10) {
    while (1) {
        BigInt trial_integer = cryptorandom::generate_kbit_integer(k);
        if (miller_rabin(trial_integer, miller_t)) {
            return trial_integer;
        }
    }
}

} // namespace residue_class