cmake_minimum_required(VERSION 3.20)
project(asan_examples)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(DEFAULT_BUILD_TYPE "ASAN")


# enable all warnings and treat them as errors
add_compile_options(-Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -Wconversion -Wformat=2)
#add_compile_options(-Werror)
if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  add_compile_options(-Wcast-align)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  # gcc specific warnings
  add_compile_options(-Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wnull-dereference -Wuseless-cast -Wcast-align=strict -Warith-conversion)
endif()

if (ENABLE_STATIC_CHECKS)
  # enable clang-tidy and cppcheck checks
  find_program(CMAKE_CXX_CLANG_TIDY NAMES clang-tidy)
  if (CMAKE_CXX_CLANG_TIDY)
    string(CONCAT CLANG_TIDY_CHECKS
      "--checks="
      "-*,"
      "boost-*,"
      "bugprone-*,"
      "-bugprone-easily-swappable-parameters,"
      "cert-*,"
      "clang-analyzer-*,"
      "concurrency-*,"
      "cppcoreguidelines-*,"
      "-cppcoreguidelines-owning-memory,"
      "misc-*,"
      "-misc-non-private-member-variables-in-classes,"
      "modernize-*,"
      "-modernize-use-auto,"
      "-modernize-use-trailing-return-type,"
      "performance-*,"
      "portability-*,"
      "readability-*,"
      "-readability-avoid-const-params-in-decls,"
      "-readability-else-after-return,"
      "-readability-function-cognitive-complexity,"
      "-readability-identifier-length,"
      "-readability-implicit-bool-conversion"
    )
    list(
      APPEND CMAKE_CXX_CLANG_TIDY "--use-color" ${CLANG_TIDY_CHECKS})
  endif()

  find_program(CMAKE_CXX_CPPCHECK NAMES cppcheck)
  if (CMAKE_CXX_CPPCHECK)
    list(
      APPEND CMAKE_CXX_CPPCHECK
        "--language=c++"
        "--std=c++17"
        "--enable=warning,performance"
    )
  endif()
endif()

# -----------------------------------------------------------------------------
# defult release build
# -----------------------------------------------------------------------------
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to '${DEFAULT_BUILD_TYPE}'")
  set(
    CMAKE_BUILD_TYPE "${DEFAULT_BUILD_TYPE}"
    CACHE
    STRING "Choose the type of build."
    FORCE
  )
  # Set the possible values of build type for cmake-gui
  set_property(
    CACHE
    CMAKE_BUILD_TYPE
    PROPERTY STRINGS
    "Debug" "Release" "MinSizeRel" "RelWithDebInfo" "ASAN" "UBSAN" "TSAN"
  )
endif()

set(CMAKE_CXX_FLAGS_DEBUG "-g -O0" CACHE STRING "Debug build" FORCE)
set(CMAKE_CXX_FLAGS_RELEASE "-DNDEBUG -O3" CACHE STRING "Release build" FORCE)
set(CMAKE_CXX_FLAGS_ASAN "-fsanitize=address -fsanitize-recover=address -fno-omit-frame-pointer -fno-optimize-sibling-calls -g -O0" CACHE STRING "Address Sanitizer build" FORCE)
set(CMAKE_CXX_FLAGS_UBSAN "-fsanitize=undefined -g -O0" CACHE STRING "Undefined Behaviour Sanitizer" FORCE)
set(CMAKE_CXX_FLAGS_TSAN "-fsanitize=thread -g -O0" CACHE STRING "Thread Sanitizer" FORCE)

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)

add_executable(allocation-size-too-big-1 allocation-size-too-big/example1.cpp)
add_executable(alloc-dealloc-mismatch-1 alloc-dealloc-mismatch/example1.cpp)
add_executable(calloc-overflow-1 calloc-overflow/example1.cpp)
add_executable(container-overflow-1 container-overflow/example1.cpp)
add_executable(double-free-1 double-free/example1.cpp)
add_executable(double-free-2 double-free/example2.cpp)
add_executable(dynamic-stack-buffer-overflow-1 dynamic-stack-buffer-overflow/example1.cpp)
add_executable(dynamic-stack-buffer-overflow-2 dynamic-stack-buffer-overflow/example2.cpp)
add_executable(dynamic-stack-buffer-overflow-3 dynamic-stack-buffer-overflow/example3.cpp)
add_executable(heap-buffer-overflow-1 heap-buffer-overflow/example1.cpp)
add_executable(heap-buffer-overflow-2 heap-buffer-overflow/example2.cpp)
add_executable(heap-buffer-overflow-3 heap-buffer-overflow/example3.cpp)
add_executable(heap-use-after-free-1 heap-use-after-free/example1.cpp)
add_executable(heap-use-after-free-2 heap-use-after-free/example2.cpp)
add_executable(heap-use-after-free-3 heap-use-after-free/example3.cpp)
add_executable(heap-use-after-free-4 heap-use-after-free/example4.cpp)
add_executable(invalid-allocation-alignment-1 invalid-allocation-alignment/example1.cpp)
add_executable(memcpy-param-overlap-1 memcpy-param-overlap/example1.cpp)
add_executable(memory-leak-1 memory-leak/example1.cpp)
add_executable(memory-leak-2 memory-leak/example2.cpp)
add_executable(new-delete-type-mismatch-1 new-delete-type-mismatch/example1.cpp)
add_executable(stack-buffer-overflow-1 stack-buffer-overflow/example1.cpp)
add_executable(stack-buffer-overflow-2 stack-buffer-overflow/example2.cpp)
add_executable(stack-buffer-underflow-1 stack-buffer-underflow/example1.cpp)
add_executable(stack-buffer-underflow-2 stack-buffer-underflow/example2.cpp)
target_link_libraries(stack-buffer-underflow-2 PRIVATE Threads::Threads)
add_executable(stack-use-after-return-1 stack-use-after-return/example1.cpp)
target_compile_options(stack-use-after-return-1 PRIVATE -fsanitize-address-use-after-return=runtime)
add_executable(stack-use-after-scope-1 stack-use-after-scope/example1.cpp)
add_executable(stack-use-after-scope-2 stack-use-after-scope/example2.cpp)
add_executable(stack-use-after-scope-3 stack-use-after-scope/example3.cpp)
add_executable(stack-use-after-scope-4 stack-use-after-scope/example4.cpp)
add_executable(strncat-param-overlap-1 strncat-param-overlap/example1.cpp)
add_executable(use-after-poison-1 use-after-poison/example1.cpp)

