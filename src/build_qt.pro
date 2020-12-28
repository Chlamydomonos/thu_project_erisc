#-------------------------------------------------
#
# Project created by QtCreator 2020-12-25T19:59:08
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ../../thu_project_erisc
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

DEFINES += QT_IN_PROJECT=\\\"yes\\\"

CONFIG += c++11

SOURCES += \
    qt_main/main.cpp \
    qt_main/mainwindow.cpp \
    vm/ememory.cpp \
    vm/eregister.cpp \
    vm/estack.cpp \
    vm/lineidlist.cpp \
    vm/vm.cpp \
    io/imageconfigreader.cpp \
    io/inpututil.cpp \
    io/output.cpp \
    io/textreader.cpp \
    io/vmconfigreader.cpp \
    image/canvas.cpp \
    fuckide/fuckide.cpp \
    exception/exception.cpp \
    command/command.cpp \
    command/lineid.cpp \
    command/commands/add.cpp \
    command/commands/and.cpp \
    command/commands/beq.cpp \
    command/commands/bge.cpp \
    command/commands/blt.cpp \
    command/commands/bne.cpp \
    command/commands/call.cpp \
    command/commands/div.cpp \
    command/commands/draw.cpp \
    command/commands/end.cpp \
    command/commands/jal.cpp \
    command/commands/load.cpp \
    command/commands/mov.cpp \
    command/commands/mul.cpp \
    command/commands/or.cpp \
    command/commands/pop.cpp \
    command/commands/push.cpp \
    command/commands/rem.cpp \
    command/commands/ret.cpp \
    command/commands/store.cpp \
    command/commands/sub.cpp \
    qt_main/linenumberwidget.cpp \
    qt_main/codeedit.cpp \
    qt_main/codetext.cpp \
    qt_main/codehighlighter.cpp \
    qt_main/paramtest.cpp \
    qt_main/drawarea.cpp \
    qt_main/textconsole.cpp

HEADERS += \
    qt_main/mainwindow.h \
    vm/ememory.h \
    vm/eregister.h \
    vm/estack.h \
    vm/lineidlist.h \
    vm/vm.h \
    io/imageconfigreader.h \
    io/inpututil.h \
    io/output.h \
    io/textreader.h \
    io/vmconfigreader.h \
    image/canvas.h \
    fuckide/fuckide.h \
    exception/exception.h \
    command/allcommands.h \
    command/command.h \
    command/lineid.h \
    command/commands/add.h \
    command/commands/and.h \
    command/commands/beq.h \
    command/commands/bge.h \
    command/commands/blt.h \
    command/commands/bne.h \
    command/commands/call.h \
    command/commands/div.h \
    command/commands/draw.h \
    command/commands/end.h \
    command/commands/jal.h \
    command/commands/load.h \
    command/commands/mov.h \
    command/commands/mul.h \
    command/commands/or.h \
    command/commands/pop.h \
    command/commands/push.h \
    command/commands/rem.h \
    command/commands/ret.h \
    command/commands/store.h \
    command/commands/sub.h \
    qt_main/linenumberwidget.h \
    qt_main/codeedit.h \
    qt_main/codetext.h \
    qt_main/codehighlighter.h \
    qt_main/paramtest.h \
    qt_main/drawarea.h \
    qt_main/textconsole.h

FORMS += \
    qt_main/mainwindow.ui \
    qt_main/codeedit.ui \
    qt_main/drawarea.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

QMAKE_POST_LINK += "..\\..\\src\\copy_files_qt.bat ..\\..\\src"
