
# Build
add_library(CalculatorCore
        STATIC
        core.c
)

add_subdirectory(InternalCore)

target_link_libraries(CalculatorCore 
                    PUBLIC 
                    InternalCore)
            
target_include_directories(CalculatorCore
                            INTERFACE
                            .)