cmake_minimum_required(VERSION 3.4.1)

add_library(native-lib
        SHARED
        native-lib.cpp)

find_library(log-lib log)

# SPDLOG TEST, Header only 파일 추가하는 경로.. CMakeLists.txt와 같은 경로 일 경우 . 으로 해야 됨
# please note that add include_directory( . ) if the library path is the same path of CMakeLists.txt
include_directories( . )

target_link_libraries(
        native-lib
        ${log-lib})