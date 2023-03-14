#include "rsa.hpp"
#include <boost/multiprecision/cpp_int.hpp>
#include <gtest/gtest.h>

namespace mp = boost::multiprecision;

using BigInt = mp::cpp_int;

TEST(Cryptosystem, RSA) {
    auto [Dec, Enc] = cryptosystem::rsa(512);

    BigInt m = BigInt(141439487983);
    EXPECT_EQ(Dec.decrypt(Enc.encrypt(m)), m);
    EXPECT_EQ(Dec.fast_decrypt(Enc.encrypt(m)), m);
}