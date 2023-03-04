# Intro Crypto

## Requriements

- Boost Library
```
sudo apt-get install libboost-dev
```

## Build

```
cmake -S . -B build
cmake --build build
```

```
./build/example/a.out
```

## Test

```
cd build/test && ctest
```