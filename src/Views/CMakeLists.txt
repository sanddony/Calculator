# Dependencies
find_package(Qt6 COMPONENTS ${QT_MODULES} 
            REQUIRED
            Charts)

# Build
add_library(Views
            STATIC
            qmlSources.qrc)

target_link_libraries(Views 
                    PUBLIC 
                    ${QT_PREFIXED_MODULES}
                    Controllers 
                    Qt6::Charts)

