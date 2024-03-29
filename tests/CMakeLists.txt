cmake_minimum_required(VERSION 3.14)
project(MazeTests)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


enable_testing()
file(GLOB TEST_SOURCES "${TESTS_DIR}/*.cc")
add_executable(
    ${PROJECT_NAME}
    ${MODEL_SOURCES}
    ${TEST_SOURCES}
    ${COMMON_SOURCES}
)

target_include_directories(${PROJECT_NAME} PUBLIC ${HEADERS_RELATIVE_DIR})

target_link_libraries(
    ${PROJECT_NAME}
    GTest::gtest_main
)

include(GoogleTest)
add_definitions(-DASSETS_DIR="${SAMPLES_DIR}")
gtest_discover_tests(${PROJECT_NAME})
