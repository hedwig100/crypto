#include "euclid.hpp"
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/random.hpp>

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

} // namespace residue_class