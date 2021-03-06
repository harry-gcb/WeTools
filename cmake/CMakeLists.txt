aux_source_directory(${PROJECT_SOURCE_DIR}/app/desktop SRC_LIST)
aux_source_directory(${PROJECT_SOURCE_DIR}/app/moc SRC_LIST)

# qt5_wrap_cpp(SRC_LIST ${PROJECT_SOURCE_DIR}/app/desktop/qt_desktop.h)
include_directories(${PROJECT_SOURCE_DIR}/utils)
include_directories(${PROJECT_SOURCE_DIR}/app)

include_directories(${QT_LIBRARY_PATH}/include)
include_directories(${SPDLOG_LIBRARY_PATH}/include)

link_directories(${QT_LIBRARY_PATH}/lib)
link_directories(${SPDLOG_LIBRARY_PATH}/lib)

IF (CMAKE_SYSTEM_NAME MATCHES "Linux") 
    add_executable(WeTools ${SRC_LIST}) 
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Windows") 
    add_executable(WeTools WIN32 ${SRC_LIST})
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MD")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup")
    set_property(TARGET WeTools PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreadedDLL")
ELSEIF (CMAKE_SYSTEM_NAME MATCHES "Darwin") 
ELSE () 
ENDIF (CMAKE_SYSTEM_NAME MATCHES "Linux") 

if(MSVC)
    add_compile_options(
        $<$<CONFIG:>:/MT> #---------|
        $<$<CONFIG:Debug>:/MT> #---|-- Statically link the runtime libraries
        $<$<CONFIG:Release>:/MT> #--|
    )
endif()

target_link_libraries(WeTools PRIVATE Qt5Widgets Qt5Core Qt5Gui spdlogd)

add_custom_command(TARGET WeTools
    PRE_BUILD
    COMMAND ${QT_LIBRARY_PATH}\\bin\\rcc.exe -binary ${PROJECT_SOURCE_DIR}\\app\\material\\main.qrc -o ${PROJECT_SOURCE_DIR}\\app\\material\\main.rcc
    COMMAND ${QT_LIBRARY_PATH}\\bin\\moc.exe ${PROJECT_SOURCE_DIR}\\app\\desktop\\qt_desktop.h -o ${PROJECT_SOURCE_DIR}\\app\\moc\\moc_desktop.cpp
    COMMAND ${QT_LIBRARY_PATH}\\bin\\moc.exe ${PROJECT_SOURCE_DIR}\\app\\desktop\\qt_sidebar.h -o ${PROJECT_SOURCE_DIR}\\app\\moc\\moc_sidebar.cpp
    COMMAND ${QT_LIBRARY_PATH}\\bin\\moc.exe ${PROJECT_SOURCE_DIR}\\app\\desktop\\qt_drawer.h -o ${PROJECT_SOURCE_DIR}\\app\\moc\\moc_drawer.cpp
    COMMAND ${QT_LIBRARY_PATH}\\bin\\moc.exe ${PROJECT_SOURCE_DIR}\\app\\desktop\\qt_content.h -o ${PROJECT_SOURCE_DIR}\\app\\moc\\moc_content.cpp
    COMMAND ${QT_LIBRARY_PATH}\\bin\\moc.exe ${PROJECT_SOURCE_DIR}\\app\\desktop\\qt_movewidget.h -o ${PROJECT_SOURCE_DIR}\\app\\moc\\moc_movewidget.cpp
    COMMAND ${QT_LIBRARY_PATH}\\bin\\moc.exe ${PROJECT_SOURCE_DIR}\\app\\desktop\\qt_businesscard.h -o ${PROJECT_SOURCE_DIR}\\app\\moc\\moc_businesscard.cpp
)

# add_custom_command(TARGET WeTools
#     POST_BUILD
#     COMMAND ${QT_LIBRARY_PATH}\\bin\\rcc.exe -binary ${PROJECT_SOURCE_DIR}\\app\\material\\main.qrc -o ${PROJECT_SOURCE_DIR}\\app\\material\\main.rcc
#     COMMAND ${QT_LIBRARY_PATH}\\bin\\moc.exe ${PROJECT_SOURCE_DIR}\\app\\desktop\\qt_desktop.h -o ${PROJECT_SOURCE_DIR}\\app\\moc\\moc_desktop.cpp
#     COMMAND ${QT_LIBRARY_PATH}\\bin\\moc.exe ${PROJECT_SOURCE_DIR}\\app\\desktop\\qt_sidebar.h -o ${PROJECT_SOURCE_DIR}\\app\\moc\\moc_sidebar.cpp
#     COMMAND ${QT_LIBRARY_PATH}\\bin\\moc.exe ${PROJECT_SOURCE_DIR}\\app\\desktop\\qt_drawer.h -o ${PROJECT_SOURCE_DIR}\\app\\moc\\moc_drawer.cpp
#     COMMAND ${QT_LIBRARY_PATH}\\bin\\moc.exe ${PROJECT_SOURCE_DIR}\\app\\desktop\\qt_content.h -o ${PROJECT_SOURCE_DIR}\\app\\moc\\moc_content.cpp
#     COMMAND ${QT_LIBRARY_PATH}\\bin\\moc.exe ${PROJECT_SOURCE_DIR}\\app\\desktop\\qt_movewidget.h -o ${PROJECT_SOURCE_DIR}\\app\\moc\\moc_movewidget.cpp
#     COMMAND ${QT_LIBRARY_PATH}\\bin\\moc.exe ${PROJECT_SOURCE_DIR}\\app\\desktop\\qt_businesscard.h -o ${PROJECT_SOURCE_DIR}\\app\\moc\\moc_businesscard.cpp
# )

