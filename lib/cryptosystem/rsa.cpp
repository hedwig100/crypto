#include "rsa.hpp"
#include "euclid.hpp"
#include "prime_gen.hpp"
#include <boost/multiprecision/cpp_int.hpp>

namespace mp = boost::multiprecision;
using BigInt = mp::cpp_int;

namespace cryptosystem {

RsaDecrypter::RsaDecrypter(BigInt p, BigInt q, BigInt d) : p(p), q(q), d(d) {
    n = p * q;

    // for fast_decrypt
    d_modp = d % (p - 1);
    d_modq = d % (q - 1);
    residue_class::extgcd(p, q, yp, yq);
}

// decrypt decrypt ciphertext c using d (private key), n
BigInt RsaDecrypter::decrypt(BigInt c) {
    return residue_class::pow(c, d, n);
}

// fast_decrypt decrypt ciphertext c by CRT.
BigInt RsaDecrypter::fast_decrypt(BigInt c) {
    BigInt mp = residue_class::pow(c, d_modp, p), mq = residue_class::pow(c, d_modq, q);
    return (mp * yq * q + mq * yp * p) % n;
}

RsaEncrypter::RsaEncrypter(BigInt n, BigInt e) : n(n), e(e) {}

// encrypt encrypt message m using e (public key)
BigInt RsaEncrypter::encrypt(BigInt m) {
    return residue_class::pow(m, e, n);
}

// rsa create RsaDecrypter,RsaEncrypter with k bit p,q
std::pair<RsaDecrypter, RsaEncrypter> rsa(int k, int miller_t) {
    BigInt p = residue_class::prime_gen_must(k, miller_t), q = residue_class::prime_gen_must(k, miller_t);
    BigInt n = p * q;
    BigInt e = (1 << 16) + 1;
    BigInt d = residue_class::inv(e, BigInt((p - 1) * (q - 1)));
    return std::make_pair(RsaDecrypter(p, q, d), RsaEncrypter(n, e));
}

} // namespace cryptosystem