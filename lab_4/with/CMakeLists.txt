cmake_minimum_required(VERSION 3.5)

project(with VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
    #MVC(lab4)
    main.cpp
    view.h view.cpp
    controller.h controller.cpp
    pages.h
    #mediator(lab1)
    listMediator.h listMediator.cpp
    textField.h
    listWidget.h
    component.h
    command.h
    mediator.h
    #factory(lab2)
    creator.h
    entry.h
    types.h
    utils.h
    createMatch.h
    createTeam.h
    createPlayer.h
    player.h player.cpp
    team.h team.cpp
    match.h match.cpp
    #adapter(lab3)
    digitalClock.h
    realDigitalClock.h realDigitalClock.cpp
    analogClock.h analogClock.cpp
    adapter.h adapter.cpp
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(with
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        view1.h view1.cpp
        view2.h view2.cpp
        view3.h view3.cpp
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET with APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(with SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(with
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(with PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
if(${QT_VERSION} VERSION_LESS 6.1.0)
  set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.with)
endif()
set_target_properties(with PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS with
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(with)
endif()
