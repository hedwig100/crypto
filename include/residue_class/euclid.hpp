#ifndef EUCLID_H
#define EUCLID_H

#include <vector>

namespace residue_class {

template <class T>
T extgcd(T a, T b, T &x, T &y);
template <class T>
T gcd(T a, T b);
template <class T>
T pow(T x, T n, T m);
template <class T>
T pow(T x, T n);
template <class T>
T inv(T x, T m);

std::vector<int> eratosthenes(int B);

using F2 = int;
std::pair<std::vector<F2>, bool> solve(std::vector<std::vector<F2>> A, std::vector<F2> b);

} // namespace residue_class

#endif