# #####################################################################
# Automatically generated by qmake (2.01a) zo nov 11 14:52:38 2007
# #####################################################################
TEMPLATE = app
TARGET = play
DEPENDPATH += .
INCLUDEPATH += .
QT += opengl \
    xml
unix:LIBS += -l3ds \
    -lGL
win32 { 
    TEMPLATE = app
    TARGET = play
    DEPENDPATH += . \
        ./lib3ds/release
    INCLUDEPATH += . \
        ./lib3ds
    CONFIG += console
    LIBS += ./lib3ds/release/lib3ds.dll
}
HEADERS += q3dsmodel.h \
    q3dsscene.h \
    mainwindow.h \
    newcomponent.h \
    frame.h
SOURCES += main.cpp \
    mainwindow.cpp \
    q3dsmodel.cpp \
    q3dsscene.cpp \
    newcomponent.cpp \
    frame.cpp
FORMS += mainwindow.ui \
    newcomponent.ui
