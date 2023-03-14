#ifndef RSA_H
#define RSA_H

#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;
using BigInt = mp::cpp_int;

namespace cryptosystem {

class RsaDecrypter {
  private:
    BigInt n, p, q, d;

    // for fast_decrypt
    BigInt d_modp, d_modq, yp, yq;

  public:
    RsaDecrypter(BigInt p, BigInt q, BigInt d);
    BigInt decrypt(BigInt c);
    BigInt fast_decrypt(BigInt c);
};

class RsaEncrypter {
  private:
    BigInt n, e;

  public:
    RsaEncrypter(BigInt n, BigInt e);
    BigInt encrypt(BigInt m);
};

std::pair<RsaDecrypter, RsaEncrypter> rsa(int k, int miller_t = 10);

} // namespace cryptosystem

#endif