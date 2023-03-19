#ifndef FACTORING_HPP
#define FACTORING_HPP

#include "euclid.hpp"
#include "random.hpp"
#include <boost/multiprecision/cpp_int.hpp>
#include <vector>

namespace mp = boost::multiprecision;
using BigInt = boost::multiprecision::cpp_int;

namespace factoring {

std::pair<bool, BigInt> p_minus_1(BigInt n, int B);

class QuadraticSieve {
  private:
    BigInt n, m;
    int B, C;
    std::vector<int> factor_base, candidate_s;
    std::vector<std::vector<int>> sieves;

    /*
     sieves has candidate_s as rows and factor_base as columns.
     sieves[i][j] means i + C has a sieves[i][j] number of factor_base[j].
    */

    BigInt f(BigInt x);
    std::vector<int> root(int p);
    void sieve();

  public:
    QuadraticSieve(BigInt n, BigInt m, int B, int C);
};

} // namespace factoring

#endif