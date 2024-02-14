
# Build
add_library(InternalCore
        STATIC
        calculator.c
        checks.c
        functions.c
        stack.c
)

add_compile_options(-fprofile-arcs -ftest-coverage)
target_link_libraries(InternalCore --coverage)
            
target_include_directories(InternalCore
                            INTERFACE
                            .)