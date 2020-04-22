# ------------------------------------------------------------------------
# dBase4Linux 1.0
# RDP - Rapid Database Programming
#
# (c) 2015-2020 Jens Kallup
# MIT License
#
# Copyright (c) 2020 Jens Kallup
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in all
# copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
#-------------------------------------------------------------------------------

# ---------------------------------------------------------------------------
# user specified:
# either you comment out "debug", or "release" - depend on your need's ...
# ---------------------------------------------------------------------------
#CONFIG += debug	# set it for debug
CONFIG  += release	# set it for release
CONFIG  += c++14 	# should be the std c++

# ------------------------------------------------------------
# internal specified (should be not changed !
# ------------------------------------------------------------
DEFINES += BUILDTIME=\\\"$$system(date '+%H:%M:%S')\\\"
DEFINES += BUILDDATE=\\\"$$system(date '+%Y-%m-%d')\\\"

VERSION = 0.0.1 	# alpha version

contains(CONFIG,debug  ) {
    WRKDIR = $$system(pwd)/src
    OUTDIR = $$system{pwd)/debug
}
contains(CONFIG,release) {
    WRKDIR = $$system(pwd)/src
    OUTDIR = $$system(pwd)/release
}
isEmpty(CONFIG) {
    CONFIG += debug
    WRKDIR  = $$system(pwd)/src
    OUTDIR  = $$system(pwd)/debug
}

SRCDIR  = $${WRKDIR}		# source
INCDIR  = $${SRCDIR}/inc 	# include
RESDIR  = $${SRCDIR}/res 	# resource
LIBDIR += $${SRCDIR}/lib 	# library

UI_DIR      = $${OUTDIR}/.uic	# converted c++ form source
MOC_DIR     = $${OUTDIR}/.moc	# Q_OBJECT
OBJECTS_DIR = $${OUTDIR}/.obj	# g++ .o
RCC_DIR     = $${OUTDIR}/.rcc	# resources .o

INCLUDEPATH += $${INCDIR}

TEMPLATE_DEPTH = 512	# only under linux, windows will fail

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

# ------------------------------------------------------
# warning: you risk data, if you don't know what's
#          going on here!
#          So, please don't edit this macro line(s).
# ------------------------------------------------------
QMAKE_CLEAN += \
    $${LIBDIR}/libQDataTableSQLPlugin.so

HEADERS     = \
    $${INCDIR}/QDataTableSQL.hpp \
    $${INCDIR}/QDataTableSQLPlugin.hpp \
    $${INCDIR}/QDataTablePropertySheetExtension.hpp \
    $${INCDIR}/QDataTablePropertySheetWidget.hpp \
    $${INCDIR}/QDataTablePropertySheetDialog.hpp \
    $${INCDIR}/QDataTableTaskMenuExtension.hpp \
    $${INCDIR}/QDataTableTaskMenuExtensionFactory.hpp

SOURCES     = \
    $${SRCDIR}/QDataTableSQL.cpp \
    $${SRCDIR}/QDataTableSQLPlugin.cpp \
    $${SRCDIR}/QDataTablePropertySheetExtension.cpp \
    $${SRCDIR}/QDataTablePropertySheetWidget.cpp \
    $${SRCDIR}/QDataTablePropertySheetDialog.cpp \
    $${SRCDIR}/QDataTableTaskMenuExtension.cpp \
    $${SRCDIR}/QDataTableTaskMenuExtensionFactory.cpp

RESOURCES += \
    $${RESDIR}/resources.qrc
