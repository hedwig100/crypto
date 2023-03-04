#include "euclid.hpp"
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
}
