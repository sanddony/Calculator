# Build
# include_directories(../Services)

add_library(Models
            STATIC
            SimpleCalcModel.cpp
)

target_link_libraries(Models 
                    PUBLIC
                    Services)

target_include_directories(Models
                            INTERFACE
                            .)

