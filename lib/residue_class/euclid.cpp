#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
using BigInt = mp::cpp_int;

namespace residue_class {

template <class T>
T extgcd(T a, T b, T &x, T &y) {
    int sign_a = (a > 0 ? 1 : -1);
    int sign_b = (b > 0 ? 1 : -1);
    if (a < 0) a *= -1;
    if (b < 0) b *= -1;

    T q, r, xx, yy;

    int sign = 1;
    T xs[2]  = {T(1), T(0)};
    T ys[2]  = {T(0), T(1)};

    while (b != 0) {
        r = a % b, q = a / b;
        a = b, b = r;
        xx = xs[1], yy = ys[1];
        xs[1] = q * xs[1] + xs[0];
        ys[1] = q * ys[1] + ys[0];
        xs[0] = xx;
        ys[0] = yy;
        sign *= -1;
    }

    x = sign_a * sign * xs[0];
    y = -sign_b * sign * ys[0];
    return a;
}

template int extgcd<int>(int, int, int &, int &);
template BigInt extgcd<BigInt>(BigInt, BigInt, BigInt &, BigInt &);

// gcd caluclate gcd(a,b)
template <typename T>
T gcd(T a, T b) {
    T x, y;
    return extgcd(a, b, x, y);
}

template int gcd<int>(int, int);
template BigInt gcd<BigInt>(BigInt, BigInt);

// pow calculate x^n mod m
template <typename T>
T pow(T x, T n, T m) {
    T ret = T(1), p = T(x);
    while (n > 0) {
        if (n & 1) {
            ret = (ret * p) % m;
        }
        n >>= 1;
        p = p * p % m;
    }
    return ret;
}

template int pow<int>(int, int, int);
template BigInt pow<BigInt>(BigInt, BigInt, BigInt);

// inv calculate x^{-1} mod m
// if there is no x^{-1}, return meaningless value.
template <class T>
T inv(T x, T m) {
    T z, w;
    extgcd(x, m, z, w);
    z %= m;
    if (z < 0) {
        z = (z + m) % m;
    }
    return z;
}

template int inv<int>(int, int);
template BigInt inv<BigInt>(BigInt, BigInt);

} // namespace residue_class