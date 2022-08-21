cmake_minimum_required(VERSION 3.10)
project(MyString)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "-fexec-charset=UTF-8")

add_executable(MyString MyString.cpp MyString.h stdafx.h MyStringEx.cpp MyStringEx.h)


project(study)

set(CMAKE_CXX_STANDARD 17)


add_executable(study main.cpp)

# -l 옵션
#target_link_libraries(study pthread)