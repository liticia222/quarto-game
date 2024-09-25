cmake_minimum_required(VERSION 3.5)

project(quarto LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(TS_FILES Annotations_fr_FR.ts Annotations_en_US.ts)
find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5 COMPONENTS Widgets LinguistTools REQUIRED)
qt5_create_translation(QM_FILES ${CMAKE_SOURCE_DIR} ${TS_FILES})
cmake_policy(SET CMP0100 NEW)
set(PROJECT_SOURCES
    main.cpp
    piece.cpp
    piece.hh
    grilledes.cpp
    grilledes.hh
    jeu.cpp
    jeu.hh
    grille.cpp
    grille.hh
    dessin.cpp
    dessin.hh
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    ${QM_FILES}
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(quarto
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(quarto SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(quarto
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(quarto PRIVATE Qt5::Widgets)
