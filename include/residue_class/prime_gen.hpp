#ifndef PRIME_GEN_H
#define PRIME_GEN_H

#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;
using BigInt = mp::cpp_int;

namespace residue_class {

bool miller_rabin(BigInt n, int t);

} // namespace residue_class

#endif