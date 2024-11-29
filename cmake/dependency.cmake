include(FetchContent)
include (CTest)

FetchContent_Declare(googletest
    URL https://github.com/google/googletest/releases/download/v1.15.2/googletest-1.15.2.tar.gz
    URL_HASH SHA256=7b42b4d6ed48810c5362c265a17faebe90dc2373c885e5216439d37927f02926
    EXCLUDE_FROM_ALL
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)