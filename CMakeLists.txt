cmake_minimum_required(VERSION 3.10)

project(MazeAll)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -pedantic -Werror)

if(CMAKE_BUILD_TYPE MATCHES "^Debug")
  add_compile_options(-g)
endif()

set(BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(SOURCE_DIR "${BASE_DIR}/src")
set(ADAPTER_DIR "${SOURCE_DIR}/adapter")
set(COMMON_DIR "${SOURCE_DIR}/common")
set(MODEL_DIR "${SOURCE_DIR}/model")
set(VIEW_DIR "${SOURCE_DIR}/view")
set(SAMPLES_DIR "${BASE_DIR}/samples")
set(TESTS_DIR "${BASE_DIR}/tests")

set(HEADERS_RELATIVE_DIR "${SOURCE_DIR}")

file(GLOB_RECURSE MODEL_SOURCES "${MODEL_DIR}/*.cc" "${MODEL_DIR}/*.h")
file(GLOB_RECURSE VIEW_SOURCES "${VIEW_DIR}/*.cc" "${VIEW_DIR}/*.h" "${VIEW_DIR}/*.ui")
file(GLOB_RECURSE ADAPTER_SOURCES "${ADAPTER_DIR}/*.cc" "${ADAPTER_DIR}/*.h")
file(GLOB_RECURSE COMMON_SOURCES "${COMMON_DIR}/*.cc" "${COMMON_DIR}/*.h")
file(GLOB_RECURSE ALL_SOURCES "${SOURCE_DIR}/*.cc" "${SOURCE_DIR}/*.h")

add_custom_target(format
    COMMAND clang-format --style=Google -i --verbose ${ALL_SOURCES}
)

add_custom_target(stylecheck
    COMMAND clang-format --style=Google -n --verbose ${ALL_SOURCES}
)

add_custom_target(cppcheck
    COMMAND cppcheck --language=c++ --enable=all --suppress=missingInclude ${ALL_SOURCES}
)

add_subdirectory(${SOURCE_DIR})

enable_testing()
add_subdirectory(${TESTS_DIR})
