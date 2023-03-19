#include "factoring.hpp"
#include <boost/multiprecision/cpp_int.hpp>
#include <gtest/gtest.h>

using BigInt = boost::multiprecision::cpp_int;

TEST(Factoring, PMinus1Method) {
    BigInt n     = 101941241344;
    auto [ok, f] = factoring::p_minus_1(n, 10);
    if (ok)
        EXPECT_TRUE(n % f == 0);
}