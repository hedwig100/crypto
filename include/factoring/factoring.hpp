#ifndef FACTORING_HPP
#define FACTORING_HPP

#include "euclid.hpp"
#include "random.hpp"
#include <boost/multiprecision/cpp_int.hpp>

using BigInt = boost::multiprecision::cpp_int;

namespace factoring {

std::pair<bool, BigInt> p_minus_1(BigInt n, int B);

} // namespace factoring

#endif