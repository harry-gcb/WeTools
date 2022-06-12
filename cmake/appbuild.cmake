aux_source_directory(${PROJECT_SOURCE_DIR}/app/desktop SRC_LIST)
aux_source_directory(${PROJECT_SOURCE_DIR}/app/moc SRC_LIST)

# qt5_wrap_cpp(SRC_LIST ${PROJECT_SOURCE_DIR}/app/desktop/qt_desktop.h)

include_directories(${QT_LIBRARY_PATH}/include)

link_directories(${QT_LIBRARY_PATH}/lib)

IF (CMAKE_SYSTEM_NAME MATCHES "Linux") 
    add_executable(WeTools ${SRC_LIST}) 
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows") 
    add_executable(WeTools WIN32 ${SRC_LIST})
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Darwin") 
ELSE () 
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux") 


target_link_libraries(WeTools PRIVATE Qt5Widgets Qt5Core)

add_custom_command(TARGET WeTools
    PRE_BUILD
    COMMAND ${QT_LIBRARY_PATH}\\bin\\moc.exe ${PROJECT_SOURCE_DIR}\\app\\desktop\\qt_desktop.h -o ${PROJECT_SOURCE_DIR}\\app\\moc\\moc_desktop.cpp
)
