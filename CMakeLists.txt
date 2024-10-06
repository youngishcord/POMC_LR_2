# cmake_minimum_required(VERSION 3.23 FATAL_ERROR)
cmake_minimum_required(VERSION 3.21 FATAL_ERROR)

project(LabProject VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_CXX_FLAGS "-static -static-libgcc -static-libstdc++")

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)  # Для форм
set(CMAKE_AUTORCC ON)  # Для ресурсов
set(CMAKE_PREFIX_PATH $ENV{QTDIR})

# set(Qt6_DIR "D:/Qt/6.5.2/mingw_64/lib/cmake/Qt6")
# set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")

find_package(Qt6Core REQUIRED)
find_package(Qt6Gui REQUIRED)
find_package(Qt6Widgets REQUIRED)
find_package(Qt6Charts REQUIRED)

set(SOURCES
    main.cpp
    src/mainwindow.cpp
    src/taskOne.cpp
    src/taskTwo.cpp
    src/taskThree.cpp
    src/widgets/customnumberinput.cpp
    )
    
    set(HEADERS
    include/mainwindow.h
    include/taskOne.h
    include/taskTwo.h
    include/taskThree.h
    include/widgets/customnumberinput.h
)

# set(UI
#     mainwindow.ui
# )

qt_standard_project_setup()

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${UI})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Core Qt6::Gui Qt6::Widgets Qt6::Charts)