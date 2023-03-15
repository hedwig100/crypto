#ifndef RANDOM_H
#define RANDOM_H

#include <boost/multiprecision/cpp_int.hpp>
#include <boost/random.hpp>
#include <random>

namespace mp = boost::multiprecision;
using BigInt = mp::cpp_int;

namespace cryptorandom {

// RandomGenerator generate random int,long long
template <class T>
class RandomGenerator {
  private:
    std::random_device seed_gen;
    std::mt19937 engine;
    std::uniform_int_distribution<T> rnd;
    T lower, upper;

  public:
    RandomGenerator(T lower, T upper);
    T generate();
};

template <>
class RandomGenerator<BigInt> {
  private:
    std::random_device seed_gen;
    boost::mt19937 engine;
    boost::uniform_int<BigInt> rnd;
    BigInt lower, upper;

  public:
    RandomGenerator(BigInt lower, BigInt upper);
    BigInt generate();
};

BigInt generate_kbit_integer(int k, bool must_odd = true);

} // namespace cryptorandom

#endif