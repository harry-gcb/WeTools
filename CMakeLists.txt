cmake_minimum_required(VERSION 3.16)

project(WeTools VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(3RD_LIBRARY_PATH "E:\\3rdparty")
set(QT_LIBRARY_PATH ${3RD_LIBRARY_PATH}/qt5)
set(SPDLOG_LIBRARY_PATH ${3RD_LIBRARY_PATH}/spdlog)

IF (CMAKE_SYSTEM_NAME MATCHES "Linux") 
    MESSAGE(STATUS "current platform: Linux ") 
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows") 
    MESSAGE(STATUS "current platform: Windows") 
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Darwin") 
    MESSAGE(STATUS "current platform: Mac OS X") 
ELSE () 
    MESSAGE(STATUS "other platform: ${CMAKE_SYSTEM_NAME}") 
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux") 
# set(CMAKE_AUTOUIC ON)
# set(CMAKE_AUTOMOC ON)
# set(CMAKE_AUTORCC ON)
# find_package(Qt5 COMPONENTS Widgets)
add_subdirectory(cmake)




