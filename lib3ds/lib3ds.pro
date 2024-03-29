# -------------------------------------------------
# Project created by QtCreator 2009-08-20T20:45:26
# -------------------------------------------------
QT -= core \
    gui
TARGET = lib3ds
INCLUDEPATH += . ./lib3ds
TEMPLATE = lib
DEFINES += LIB3DS_LIBRARY
HEADERS += lib3ds/viewport.h \
    lib3ds/vector.h \
    lib3ds/types.h \
    lib3ds/tracks.h \
    lib3ds/tcb.h \
    lib3ds/shadow.h \
    lib3ds/quat.h \
    lib3ds/node.h \
    lib3ds/mesh.h \
    lib3ds/matrix.h \
    lib3ds/material.h \
    lib3ds/light.h \
    lib3ds/io.h \
    lib3ds/file.h \
    lib3ds/ease.h \
    lib3ds/chunktable.sed \
    lib3ds/chunktable.h \
    lib3ds/chunk.h \
    lib3ds/camera.h \
    lib3ds/background.h \
    lib3ds/atmosphere.h
SOURCES += lib3ds/viewport.c \
    lib3ds/vector.c \
    lib3ds/tracks.c \
    lib3ds/tcb.c \
    lib3ds/shadow.c \
    lib3ds/quat.c \
    lib3ds/node.c \
    lib3ds/mesh.c \
    lib3ds/matrix.c \
    lib3ds/material.c \
    lib3ds/light.c \
    lib3ds/io.c \
    lib3ds/file.c \
    lib3ds/ease.c \
    lib3ds/chunk.c \
    lib3ds/camera.c \
    lib3ds/background.c \
    lib3ds/atmosphere.c
