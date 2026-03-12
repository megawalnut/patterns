cmake_minimum_required(VERSION 3.14)

project(with LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

add_executable(with
  main.cpp
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
)
target_link_libraries(with Qt${QT_VERSION_MAJOR}::Core)

include(GNUInstallDirs)
install(TARGETS with
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
