cmake_minimum_required(VERSION 3.4...3.18)

project(poller
	VERSION 0.1
	DESCRIPTION "Poll different resources on the web"
	LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23 CACHE STRING "C++ version selection")
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
include(FetchContent)

enable_testing()

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)


file(GLOB_RECURSE SOURCES "include/*.hpp" "src/*.cpp" "tests/*.cpp")
add_executable(unittest ${SOURCES})
target_link_libraries(unittest gtest_main)


include(GoogleTest)
gtest_discover_tests(unittest)

# set_target_properties(poller_lib PROPERTIES LINKER_LANGUAGE CXX)

