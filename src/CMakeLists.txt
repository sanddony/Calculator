cmake_minimum_required(VERSION 3.21.1)

project(SmartCalc VERSION 1.0
                  LANGUAGES C CXX)

# Languages
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

list(APPEND QT_MODULES Qml Core Quick Gui)

# For Ubuntu
set(Qt6_DIR /home/user/Qt/6.5.0/gcc_64/lib/cmake/Qt6)

find_package(Qt6 COMPONENTS ${QT_MODULES} 
            REQUIRED
            Charts)

set(QT_PREFIXED_MODULES ${QT_MODULES})
list(TRANSFORM QT_PREFIXED_MODULES PREPEND "Qt6::")


add_subdirectory(Services)
add_subdirectory(Models)
add_subdirectory(Controllers)

add_subdirectory(Views)


# Building
add_executable(${PROJECT_NAME} main.cpp Views/qmlSources.qrc)

target_link_libraries(${PROJECT_NAME}
                PUBLIC
                ${QT_PREFIXED_MODULES}
                Views
)


