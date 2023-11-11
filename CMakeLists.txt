# 版本
cmake_minimum_required(VERSION 3.0.0)
project(tree VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 11)  
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 指定路径
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib) # 指定可执行程序生成路径
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/bin) # 指定可执行程序生成路径

# 测试
include(CTest)
enable_testing()

# 添加库
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)   # 头文件目录
message(${CMAKE_CURRENT_SOURCE_DIR})
link_directories(${CMAKE_CURRENT_SOURCE_DIR}/lib)      # 链接库目录

# aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR/src}, DIR_SRCS)     # 自动查找置顶目录下的所有源文件  （<dir>, <variable>）

# 子节点
add_subdirectory(src)   
add_executable(tree main.cpp)
target_link_libraries(tree btree)  # 指定需要链接的库  从链接库中寻找

# 打包
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# 如果你有头文件需要包含，可以使用 target_include_directories 添加头文件路径
# target_include_directories(YourExecutableName PRIVATE path_to_your_header_files)