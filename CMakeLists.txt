# CMakeのバージョンを設定
cmake_minimum_required(VERSION 2.8)
# プロジェクト名と使用する言語を設定
project(getopt_test CXX)

include_directories(dist)

file(GLOB DIST_FILES dist/*.cpp)

add_executable(getopt_test
	${DIST_FILES}
	test/main.cpp
)
