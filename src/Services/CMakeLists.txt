cmake_minimum_required(VERSION 3.16)

set(namespace "SimpleCalc")
project("CalculatorCore"
    LANGUAGES C CXX
    VERSION 0.1
)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${PROJECT_NAME} 
    ./Calculate.cpp
    ./main.cpp
)

# target_compile_options(${PROJECT_NAME}
#     PRIVATE
#          $<$<OR:$<CXX_COMPILER_ID:GNU>,$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>>: 
#          -Wall -Wextra -Wpedantic -Wcast-align -Wcast-qual -Wctor-dtor-privacy
#          -Wdisabled-optimization -Wformat=2 -Winit-self -Wmissing-include-dirs
#          -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo
#          -Wstrict-overflow=5 -Wswitch-default -Wundef -Wunused-variable >
#          $<$<CXX_COMPILER_ID:GNU>: -Wlogical-op -Wnoexcept -Wstrict-null-sentinel >
# )


# target_link_options(${PROJECT_NAME} PRIVATE $<$<CXX_COMPILER_ID:GNU>:-fsanitize=address>)

