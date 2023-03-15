#include "random.hpp"

namespace cryptorandom {

template class RandomGenerator<int>;
template class RandomGenerator<BigInt>;

template <class T>
RandomGenerator<T>::RandomGenerator(T lower, T upper) : engine(seed_gen()),
                                                        lower(lower),
                                                        upper(upper),
                                                        rnd(lower, upper) {}

// generate generates uniform random integer in [0,n)
template <class T>
T RandomGenerator<T>::generate() {
    return rnd(engine);
}

RandomGenerator<BigInt>::RandomGenerator(BigInt lower, BigInt upper) : engine(seed_gen()),
                                                                       lower(lower),
                                                                       upper(upper),
                                                                       rnd(lower, upper) {}

// generate generates uniform random multiprecision integer in [0,n)
BigInt RandomGenerator<BigInt>::generate() {
    return rnd(engine);
}

// These generator is internally used.
RandomGenerator<int> _bernoulli(0, 1);

// generate_kbit_integer generate k-bit random integer
BigInt generate_kbit_integer(int k, bool must_odd) {
    BigInt x = 0;

    if (must_odd) {
        mp::bit_set(x, 0);
    } else {
        if (_bernoulli.generate()) mp::bit_set(x, 0);
    }

    mp::bit_set(x, k - 1);
    for (int i = 1; i < k - 1; i++) {
        if (_bernoulli.generate()) {
            mp::bit_set(x, i);
        }
    }
    return x;
}

} // namespace cryptorandom