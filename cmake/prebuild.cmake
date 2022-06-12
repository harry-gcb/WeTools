add_custom_command(OUTPUT moc
    PRE_BUILD
    COMMAND ${QT_LIBRARY_PATH}/bin/moc ${PROJECT_SOURCE_DIR}/app/desktop/qt_desktop.h -o ${PROJECT_SOURCE_DIR}/app/moc/moc_desktop.cpp
)