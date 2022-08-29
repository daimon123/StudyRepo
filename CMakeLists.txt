cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "-fexec-charset=UTF-8")

add_subdirectory(MyString)
add_subdirectory(Study)



# -l 옵션
#target_link_libraries(study pthread)