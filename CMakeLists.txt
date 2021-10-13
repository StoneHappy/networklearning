# Generated from rasterwindow.pro.

cmake_minimum_required(VERSION 3.16)
project(networklearning)

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
                                    test/
                                    )


# 设置项目编译需要的头文件                                    
file(GLOB PROJECT_HEADERS           
                                    include/*.h
                                    test/*.
                                    )
file(GLOB PROJECT_SOURCES           src/*.cpp
                                    )
# 添加应用                                    
add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCES} ${PROJECT_HEADERS}
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/resources $<TARGET_FILE_DIR:${PROJECT_NAME}>/resources/)
