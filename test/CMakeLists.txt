enable_testing()

## hello_test
add_executable(
  hello_test
  hello_test.cpp
)
target_link_libraries(
  hello_test
  GTest::gtest_main
)

## residue_class
add_executable(
  residue_class_test
  residue_class.cpp
)
target_include_directories(residue_class_test
  PUBLIC ${PROJECT_SOURCE_DIR}/include/residue_class
)
target_link_libraries(
  residue_class_test
  residue_class
  GTest::gtest_main
)

## cryptosystem
add_executable(
  cryptosystem_test
  cryptosystem.cpp
)
target_include_directories(cryptosystem_test
  PUBLIC ${PROJECT_SOURCE_DIR}/include/cryptosystem
)
target_link_libraries(
  cryptosystem_test
  cryptosystem
  GTest::gtest_main
)


include(GoogleTest)
gtest_discover_tests(hello_test)
gtest_discover_tests(residue_class_test)
gtest_discover_tests(cryptosystem_test)