cmake_minimum_required(VERSION 3.16)
project(ouch_engine LANGUAGES CXX)

add_library(ouch_engine
    src/ouch_decode.cpp
    src/ouch_encode.cpp
    src/ouch_utils.cpp
)
target_include_directories(ouch_engine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_compile_features(ouch_engine PUBLIC cxx_std_17)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang|AppleClang")
    target_compile_options(ouch_engine PRIVATE -Wall -Wextra -Wpedantic)
elseif(MSVC)
    target_compile_options(ouch_engine PRIVATE /W4)
endif()

include(CTest)
if(BUILD_TESTING)
    add_executable(ouch_smoke_test tests/smoke.cpp)
    target_link_libraries(ouch_smoke_test PRIVATE ouch_engine)
    add_test(NAME ouch_smoke_test COMMAND ouch_smoke_test)
endif()
