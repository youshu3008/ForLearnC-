set(CMAKE_CXX_COMPILER "E:/QT/QT6.6.0/Tools/mingw1120_64/bin/g++.exe")
cmake_minimum_required(VERSION 3.5)  # 指定CMake的最低版本要求为3.5。
project(test001 LANGUAGES CXX) # 定义项目名称为"test001"，并指定使用C++语言。
set(CMAKE_INCLUDE_CURRENT_DIR ON) # 启用自动包含当前目录的功能。
set(CMAKE_PREFIX_PATH "e:/QT/QT6.6.0/6.6.2/mingw_64") #设置Qt Kit的安装目录，用于在构建过程中查找Qt库。
set(CMAKE_AUTOUIC ON) # 启用自动UI编译，用于处理Qt的用户界面文件（.ui）。
set(CMAKE_AUTOMOC ON) # 启用自动MOC（元对象编译器）处理，用于处理包含Qt元对象宏的源文件。
set(CMAKE_AUTORCC ON) # 启用自动RCC（资源编译器）处理，用于处理Qt的资源文件（.qrc）。

set(CMAKE_CXX_STANDARD 11) # 设置C++标准为C++11。
set(CMAKE_CXX_STANDARD_REQUIRED ON) # 要求编译器使用指定的C++标准。

find_package(Qt6 COMPONENTS Widgets Core REQUIRED) # 查找并加载Qt5的Widgets组件，确保其可用性。

aux_source_directory(./src srcs) # 将"./src"目录下的所有源文件添加到变量"srcs"中。

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>") # 对于MSVC编译器，添加编译选项以指定使用UTF-8编码。
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>") # 对于MSVC编译器，添加编译选项以指定使用UTF-8编码。

add_executable(${PROJECT_NAME} WIN32 ${srcs}) # 创建一个名为"test001"的可执行文件，并将变量"srcs"中的源文件添加到该可执行文件中。

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets Qt6::Core) # 将Qt5的Widgets库链接到可执行文件中，以便在运行时使用该库的功能。
# target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets Qt6::Core)