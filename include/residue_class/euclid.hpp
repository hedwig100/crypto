#ifndef EUCLID_H
#define EUCLID_H

namespace residue_class {

template <class T>
T extgcd(T a, T b, T &x, T &y) {
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

    x = sign * xs[0];
    y = -sign * ys[0];
    return a;
}

} // namespace residue_class

#endif