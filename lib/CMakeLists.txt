
include_directories(Boost_INCLUDE_DIRS)

## Residule Class Ring 

add_library(residue_class
    SHARED
     residue_class/euclid.cpp
     residue_class/prime_gen.cpp
)

target_include_directories(residue_class
    PUBLIC ${PROJECT_SOURCE_DIR}/include/residue_class
)

## CryptoSystem

add_library(cryptosystem
    SHARED
     cryptosystem/rsa.cpp
)

target_link_libraries(
    cryptosystem
    residue_class
)

target_include_directories(cryptosystem
    PUBLIC ${PROJECT_SOURCE_DIR}/include/residue_class
    PUBLIC ${PROJECT_SOURCE_DIR}/include/cryptosystem
)