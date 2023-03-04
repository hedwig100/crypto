
include_directories(Boost_INCLUDE_DIRS)

## Residule Class Ring 

add_library(residue_class
    SHARED
     residue_class/euclid.cpp
)

target_include_directories(residue_class
    PUBLIC ${PROJECT_SOURCE_DIR}/include/residue_class
)