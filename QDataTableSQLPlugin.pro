QT += widgets uiplugin


QTDIR_build {
    PLUGIN_TYPE = designer
    PLUGIN_CLASS_NAME = QDataTableSQLPlugin
    load(qt_plugin)
    CONFIG += install_ok
}
else {

    CONFIG      += plugin
    TEMPLATE    = lib

    TARGET = $$qtLibraryTarget($$TARGET)

    target.path = $$[QT_INSTALL_PLUGINS]/designer
    INSTALLS += target
}

HEADERS     = \
    QDataTableSQL.hpp \
    QDataTableSQLPlugin.hpp

SOURCES     = \
    QDataTableSQL.cpp \
    QDataTableSQLPlugin.cpp

RESOURCES += \
    resources.qrc
