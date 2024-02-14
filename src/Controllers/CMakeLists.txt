find_package(Qt6 COMPONENTS ${QT_MODULES} REQUIRED)


# Build
add_library(Controllers
            STATIC
            SimpleCalcController.cpp 
)


target_link_libraries(Controllers 
                        PUBLIC 
                        ${QT_PREFIXED_MODULES}
                        Models)


target_include_directories(Controllers
                            INTERFACE
                            .)


