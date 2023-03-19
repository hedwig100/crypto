#include "euclid.hpp"
#include "prime_gen.hpp"
#include <boost/multiprecision/cpp_int.hpp>
#include <gtest/gtest.h>

namespace mp = boost::multiprecision;
namespace rc = residue_class;

using BigInt = mp::cpp_int;

TEST(ResidueClass, ExtGcd) {
    BigInt x, y;
    EXPECT_EQ(rc::extgcd(BigInt(10), BigInt(5), x, y), 5);
    EXPECT_EQ(x, 0);
    EXPECT_EQ(y, 1);
    EXPECT_EQ(rc::extgcd(BigInt(-10), BigInt(-32), x, y), 2);
    EXPECT_EQ(x, 3);
    EXPECT_EQ(y, -1);
}

TEST(ResidueClass, Pow) {
    EXPECT_EQ(rc::pow(BigInt(4), BigInt(3), BigInt(100)), BigInt(64));
    EXPECT_EQ(rc::pow(BigInt(2), BigInt(5), BigInt(10)), BigInt(2));
    EXPECT_EQ(rc::pow(BigInt(2), BigInt(10), BigInt(250)), BigInt(24));
}

TEST(ResidueClass, Inv) {
    EXPECT_EQ(rc::inv(BigInt(4), BigInt(9)), BigInt(7));
    EXPECT_EQ(rc::inv(BigInt(2), BigInt(5)), BigInt(3));
    EXPECT_EQ(rc::inv(BigInt(2), BigInt(11)), BigInt(6));
}

TEST(ResidueClass, MillerRabin) {
    EXPECT_TRUE(rc::miller_rabin(BigInt(7), 10));
    EXPECT_TRUE(rc::miller_rabin(BigInt(1223), 10));
    EXPECT_TRUE(rc::miller_rabin(BigInt("7427466391"), 10));

    EXPECT_FALSE(rc::miller_rabin(BigInt("10987364871648713689478293749842793842"), 10));
    EXPECT_FALSE(rc::miller_rabin(BigInt("471983479312"), 10));
    EXPECT_FALSE(rc::miller_rabin(BigInt("10987364293874983242"), 10));
}

TEST(ResidueClass, PrimeGen) {
    int n = 10, n_success = 0;
    for (int i = 0; i < n; i++) {
        BigInt p = rc::prime_gen(128, 20, 10);
        if (p > 0) {
            n_success++;
            EXPECT_TRUE(rc::miller_rabin(p, 10));
        }
    }
    RecordProperty("NumberOfSuccess", n_success);
    RecordProperty("NumberOfFailure", n - n_success);
}

TEST(ResidueClass, PrimeGenMust) {
    BigInt p = rc::prime_gen_must(1024, 10);
    EXPECT_TRUE(rc::miller_rabin(p, 10));
}

TEST(ResidueClass, Eratosthenes) {
    std::vector<int> actual{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    auto primes = rc::eratosthenes(50);
    EXPECT_EQ(primes, actual);
}