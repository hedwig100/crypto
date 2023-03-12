#ifndef EUCLID_H
#define EUCLID_H

namespace residue_class {

template <class T>
T extgcd(T a, T b, T &x, T &y);
template <class T>
T gcd(T a, T b);
template <class T>
T pow(T x, T n, T m);

} // namespace residue_class

#endif