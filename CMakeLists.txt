# CMakeのバージョンを設定
cmake_minimum_required(VERSION 2.8)
# プロジェクト名と使用する言語を設定
project(getopt_test CXX)

include_directories(dist)

add_executable(getopt_test
	test/main.cpp
	dist/XCGetOpt.cpp
	dist/XCListOptObject.cpp
	dist/XCOptFlag.cpp
	dist/XCOptInt32.cpp
	dist/XCOptObject.cpp
	dist/XCOptString.cpp
)
