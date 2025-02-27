project(LearnAssertAndMacro)

# 设置C++标准
# set what std version to use
if(NOT CXX_STD)
    set(CXX_STD "17")
endif()

set(CMAKE_CXX_STANDARD ${CXX_STD})

# make sure to force using it
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# forbid defaulting to gnu++NN instead of c++NN
set(CMAKE_CXX_EXTENSIONS OFF)

add_definitions(-DDEFINE_MACROS)

add_executable(LearnAssertAndMacro main.cpp)