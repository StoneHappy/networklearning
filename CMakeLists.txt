# Generated from rasterwindow.pro.

cmake_minimum_required(VERSION 3.16)
project(networklearning)
enable_testing()


# 设置编译标志
if(WIN32)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wno-parenthese -fexec-charset=GBK")
endif()
if(UNIX AND NOT APPLE)
endif()
if(APPLE)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -Wno-parenthese")
endif()



# 设置头文件目录
include_directories(                include/
                                    )


# 设置项目编译需要的头文件                                    
file(GLOB PROJECT_HEADERS           
                                    include/*.h
                                    )
file(GLOB PROJECT_SOURCES           src/*.cpp
                                    )
# 添加应用                                    
add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCES} ${PROJECT_HEADERS}
)

ADD_TEST(NAME test_add_2_3 COMMAND add 2 3)
SET_TESTS_PROPERTIES(test_add_2_3
    PROPERTIES PASS_REGULAR_EXPRESSION "5")