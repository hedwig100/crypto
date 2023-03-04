
## Residule Class Ring 

add_library(residule_class
    SHARED
     residule_class/euclid.cpp
)

target_include_directories(residule_class
    PUBLIC ${PROJECT_SOURCE_DIR}/include/residule_class
)