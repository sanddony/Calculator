
# Build
add_library(Services
        STATIC
        Calculate.cpp
)

add_subdirectory(CalculatorCore)

target_link_libraries(Services 
                        PUBLIC 
                        CalculatorCore)
            

target_include_directories(Services
                            INTERFACE
                            .)
