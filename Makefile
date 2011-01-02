#############################################################################
# Makefile for building: 3dmeEditor
# Generated by qmake (2.01a) (Qt 4.7.0) on: ?? 1? 3 09:07:24 2011
# Project:  3dsplay.pro
# Template: app
# Command: /usr/local/bin/qmake -o Makefile 3dsplay.pro
#############################################################################

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_XML_LIB -DQT_OPENGL_LIB -DQT_GUI_LIB -DQT_CORE_LIB -DQT_SHARED
CFLAGS        = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
CXXFLAGS      = -m64 -pipe -O2 -Wall -W -D_REENTRANT $(DEFINES)
INCPATH       = -I../../qtsdk/qt/mkspecs/linux-g++-64 -I. -I../../qtsdk/qt/include/QtCore -I../../qtsdk/qt/include/QtGui -I../../qtsdk/qt/include/QtOpenGL -I../../qtsdk/qt/include/QtXml -I../../qtsdk/qt/include -I. -Ilib3ds -I/usr/X11R6/include -I. -I.
LINK          = g++
LFLAGS        = -m64 -Wl,-O1 -Wl,-rpath,/home/z35liu/qtsdk/qt/lib
LIBS          = $(SUBLIBS)  -L/home/z35liu/qtsdk/qt/lib -L/usr/X11R6/lib64 -Llib3ds/ -llib3ds -lQtXml -L/home/z35liu/qtsdk/qt/lib -lQtOpenGL -L/usr/X11R6/lib64 -lQtGui -lQtCore -lGLU -lGL -lpthread 
AR            = ar cqs
RANLIB        = 
QMAKE         = /usr/local/bin/qmake
TAR           = tar -cf
COMPRESS      = gzip -9f
COPY          = cp -f
SED           = sed
COPY_FILE     = $(COPY)
COPY_DIR      = $(COPY) -r
STRIP         = strip
INSTALL_FILE  = install -m 644 -p
INSTALL_DIR   = $(COPY_DIR)
INSTALL_PROGRAM = install -m 755 -p
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = main.cpp \
		mainwindow.cpp \
		q3dsmodel.cpp \
		q3dsscene.cpp \
		newcomponent.cpp \
		frame.cpp moc_mainwindow.cpp \
		moc_newcomponent.cpp
OBJECTS       = main.o \
		mainwindow.o \
		q3dsmodel.o \
		q3dsscene.o \
		newcomponent.o \
		frame.o \
		moc_mainwindow.o \
		moc_newcomponent.o
DIST          = ../../qtsdk/qt/mkspecs/common/g++.conf \
		../../qtsdk/qt/mkspecs/common/unix.conf \
		../../qtsdk/qt/mkspecs/common/linux.conf \
		../../qtsdk/qt/mkspecs/qconfig.pri \
		../../qtsdk/qt/mkspecs/modules/qt_webkit_version.pri \
		../../qtsdk/qt/mkspecs/features/qt_functions.prf \
		../../qtsdk/qt/mkspecs/features/qt_config.prf \
		../../qtsdk/qt/mkspecs/features/exclusive_builds.prf \
		../../qtsdk/qt/mkspecs/features/default_pre.prf \
		../../qtsdk/qt/mkspecs/features/release.prf \
		../../qtsdk/qt/mkspecs/features/default_post.prf \
		../../qtsdk/qt/mkspecs/features/warn_on.prf \
		../../qtsdk/qt/mkspecs/features/qt.prf \
		../../qtsdk/qt/mkspecs/features/unix/opengl.prf \
		../../qtsdk/qt/mkspecs/features/unix/thread.prf \
		../../qtsdk/qt/mkspecs/features/moc.prf \
		../../qtsdk/qt/mkspecs/features/resources.prf \
		../../qtsdk/qt/mkspecs/features/uic.prf \
		../../qtsdk/qt/mkspecs/features/yacc.prf \
		../../qtsdk/qt/mkspecs/features/lex.prf \
		../../qtsdk/qt/mkspecs/features/include_source_dir.prf \
		3dsplay.pro
QMAKE_TARGET  = 3dmeEditor
DESTDIR       = 
TARGET        = 3dmeEditor

first: all
####### Implicit rules

.SUFFIXES: .o .c .cpp .cc .cxx .C

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o "$@" "$<"

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o "$@" "$<"

####### Build rules

all: Makefile $(TARGET)

$(TARGET): ui_mainwindow.h ui_newcomponent.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: 3dsplay.pro  ../../qtsdk/qt/mkspecs/linux-g++-64/qmake.conf ../../qtsdk/qt/mkspecs/common/g++.conf \
		../../qtsdk/qt/mkspecs/common/unix.conf \
		../../qtsdk/qt/mkspecs/common/linux.conf \
		../../qtsdk/qt/mkspecs/qconfig.pri \
		../../qtsdk/qt/mkspecs/modules/qt_webkit_version.pri \
		../../qtsdk/qt/mkspecs/features/qt_functions.prf \
		../../qtsdk/qt/mkspecs/features/qt_config.prf \
		../../qtsdk/qt/mkspecs/features/exclusive_builds.prf \
		../../qtsdk/qt/mkspecs/features/default_pre.prf \
		../../qtsdk/qt/mkspecs/features/release.prf \
		../../qtsdk/qt/mkspecs/features/default_post.prf \
		../../qtsdk/qt/mkspecs/features/warn_on.prf \
		../../qtsdk/qt/mkspecs/features/qt.prf \
		../../qtsdk/qt/mkspecs/features/unix/opengl.prf \
		../../qtsdk/qt/mkspecs/features/unix/thread.prf \
		../../qtsdk/qt/mkspecs/features/moc.prf \
		../../qtsdk/qt/mkspecs/features/resources.prf \
		../../qtsdk/qt/mkspecs/features/uic.prf \
		../../qtsdk/qt/mkspecs/features/yacc.prf \
		../../qtsdk/qt/mkspecs/features/lex.prf \
		../../qtsdk/qt/mkspecs/features/include_source_dir.prf \
		/home/z35liu/qtsdk/qt/lib/libQtXml.prl \
		/home/z35liu/qtsdk/qt/lib/libQtCore.prl \
		/home/z35liu/qtsdk/qt/lib/libQtOpenGL.prl \
		/home/z35liu/qtsdk/qt/lib/libQtGui.prl
	$(QMAKE) -o Makefile 3dsplay.pro
../../qtsdk/qt/mkspecs/common/g++.conf:
../../qtsdk/qt/mkspecs/common/unix.conf:
../../qtsdk/qt/mkspecs/common/linux.conf:
../../qtsdk/qt/mkspecs/qconfig.pri:
../../qtsdk/qt/mkspecs/modules/qt_webkit_version.pri:
../../qtsdk/qt/mkspecs/features/qt_functions.prf:
../../qtsdk/qt/mkspecs/features/qt_config.prf:
../../qtsdk/qt/mkspecs/features/exclusive_builds.prf:
../../qtsdk/qt/mkspecs/features/default_pre.prf:
../../qtsdk/qt/mkspecs/features/release.prf:
../../qtsdk/qt/mkspecs/features/default_post.prf:
../../qtsdk/qt/mkspecs/features/warn_on.prf:
../../qtsdk/qt/mkspecs/features/qt.prf:
../../qtsdk/qt/mkspecs/features/unix/opengl.prf:
../../qtsdk/qt/mkspecs/features/unix/thread.prf:
../../qtsdk/qt/mkspecs/features/moc.prf:
../../qtsdk/qt/mkspecs/features/resources.prf:
../../qtsdk/qt/mkspecs/features/uic.prf:
../../qtsdk/qt/mkspecs/features/yacc.prf:
../../qtsdk/qt/mkspecs/features/lex.prf:
../../qtsdk/qt/mkspecs/features/include_source_dir.prf:
/home/z35liu/qtsdk/qt/lib/libQtXml.prl:
/home/z35liu/qtsdk/qt/lib/libQtCore.prl:
/home/z35liu/qtsdk/qt/lib/libQtOpenGL.prl:
/home/z35liu/qtsdk/qt/lib/libQtGui.prl:
qmake:  FORCE
	@$(QMAKE) -o Makefile 3dsplay.pro

dist: 
	@$(CHK_DIR_EXISTS) .tmp/3dmeEditor1.0.0 || $(MKDIR) .tmp/3dmeEditor1.0.0 
	$(COPY_FILE) --parents $(SOURCES) $(DIST) .tmp/3dmeEditor1.0.0/ && $(COPY_FILE) --parents q3dsmodel.h q3dsscene.h mainwindow.h newcomponent.h frame.h .tmp/3dmeEditor1.0.0/ && $(COPY_FILE) --parents main.cpp mainwindow.cpp q3dsmodel.cpp q3dsscene.cpp newcomponent.cpp frame.cpp .tmp/3dmeEditor1.0.0/ && $(COPY_FILE) --parents mainwindow.ui newcomponent.ui .tmp/3dmeEditor1.0.0/ && (cd `dirname .tmp/3dmeEditor1.0.0` && $(TAR) 3dmeEditor1.0.0.tar 3dmeEditor1.0.0 && $(COMPRESS) 3dmeEditor1.0.0.tar) && $(MOVE) `dirname .tmp/3dmeEditor1.0.0`/3dmeEditor1.0.0.tar.gz . && $(DEL_FILE) -r .tmp/3dmeEditor1.0.0


clean:compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


####### Sub-libraries

distclean: clean
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) Makefile


check: first

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

compiler_moc_header_make_all: moc_mainwindow.cpp moc_newcomponent.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_mainwindow.cpp moc_newcomponent.cpp
moc_mainwindow.cpp: q3dsscene.h \
		q3dsmodel.h \
		lib3ds/lib3ds/file.h \
		lib3ds/lib3ds/background.h \
		lib3ds/lib3ds/types.h \
		lib3ds/lib3ds/atmosphere.h \
		lib3ds/lib3ds/shadow.h \
		lib3ds/lib3ds/viewport.h \
		lib3ds/lib3ds/camera.h \
		lib3ds/lib3ds/mesh.h \
		lib3ds/lib3ds/node.h \
		lib3ds/lib3ds/tracks.h \
		lib3ds/lib3ds/tcb.h \
		lib3ds/lib3ds/material.h \
		lib3ds/lib3ds/matrix.h \
		lib3ds/lib3ds/vector.h \
		lib3ds/lib3ds/light.h \
		mainwindow.h
	/home/z35liu/qtsdk/qt/bin/moc $(DEFINES) $(INCPATH) mainwindow.h -o moc_mainwindow.cpp

moc_newcomponent.cpp: q3dsmodel.h \
		lib3ds/lib3ds/file.h \
		lib3ds/lib3ds/background.h \
		lib3ds/lib3ds/types.h \
		lib3ds/lib3ds/atmosphere.h \
		lib3ds/lib3ds/shadow.h \
		lib3ds/lib3ds/viewport.h \
		lib3ds/lib3ds/camera.h \
		lib3ds/lib3ds/mesh.h \
		lib3ds/lib3ds/node.h \
		lib3ds/lib3ds/tracks.h \
		lib3ds/lib3ds/tcb.h \
		lib3ds/lib3ds/material.h \
		lib3ds/lib3ds/matrix.h \
		lib3ds/lib3ds/vector.h \
		lib3ds/lib3ds/light.h \
		newcomponent.h
	/home/z35liu/qtsdk/qt/bin/moc $(DEFINES) $(INCPATH) newcomponent.h -o moc_newcomponent.cpp

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_image_collection_make_all: qmake_image_collection.cpp
compiler_image_collection_clean:
	-$(DEL_FILE) qmake_image_collection.cpp
compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_mainwindow.h ui_newcomponent.h
compiler_uic_clean:
	-$(DEL_FILE) ui_mainwindow.h ui_newcomponent.h
ui_mainwindow.h: mainwindow.ui \
		q3dsscene.h \
		q3dsmodel.h \
		lib3ds/lib3ds/file.h \
		lib3ds/lib3ds/background.h \
		lib3ds/lib3ds/types.h \
		lib3ds/lib3ds/atmosphere.h \
		lib3ds/lib3ds/shadow.h \
		lib3ds/lib3ds/viewport.h \
		lib3ds/lib3ds/camera.h \
		lib3ds/lib3ds/mesh.h \
		lib3ds/lib3ds/node.h \
		lib3ds/lib3ds/tracks.h \
		lib3ds/lib3ds/tcb.h \
		lib3ds/lib3ds/material.h \
		lib3ds/lib3ds/matrix.h \
		lib3ds/lib3ds/vector.h \
		lib3ds/lib3ds/light.h
	/home/z35liu/qtsdk/qt/bin/uic mainwindow.ui -o ui_mainwindow.h

ui_newcomponent.h: newcomponent.ui
	/home/z35liu/qtsdk/qt/bin/uic newcomponent.ui -o ui_newcomponent.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_header_clean compiler_uic_clean 

####### Compile

main.o: main.cpp q3dsscene.h \
		q3dsmodel.h \
		lib3ds/lib3ds/file.h \
		lib3ds/lib3ds/background.h \
		lib3ds/lib3ds/types.h \
		lib3ds/lib3ds/atmosphere.h \
		lib3ds/lib3ds/shadow.h \
		lib3ds/lib3ds/viewport.h \
		lib3ds/lib3ds/camera.h \
		lib3ds/lib3ds/mesh.h \
		lib3ds/lib3ds/node.h \
		lib3ds/lib3ds/tracks.h \
		lib3ds/lib3ds/tcb.h \
		lib3ds/lib3ds/material.h \
		lib3ds/lib3ds/matrix.h \
		lib3ds/lib3ds/vector.h \
		lib3ds/lib3ds/light.h \
		mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp

mainwindow.o: mainwindow.cpp mainwindow.h \
		q3dsscene.h \
		q3dsmodel.h \
		lib3ds/lib3ds/file.h \
		lib3ds/lib3ds/background.h \
		lib3ds/lib3ds/types.h \
		lib3ds/lib3ds/atmosphere.h \
		lib3ds/lib3ds/shadow.h \
		lib3ds/lib3ds/viewport.h \
		lib3ds/lib3ds/camera.h \
		lib3ds/lib3ds/mesh.h \
		lib3ds/lib3ds/node.h \
		lib3ds/lib3ds/tracks.h \
		lib3ds/lib3ds/tcb.h \
		lib3ds/lib3ds/material.h \
		lib3ds/lib3ds/matrix.h \
		lib3ds/lib3ds/vector.h \
		lib3ds/lib3ds/light.h \
		ui_mainwindow.h \
		newcomponent.h \
		ui_newcomponent.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o mainwindow.o mainwindow.cpp

q3dsmodel.o: q3dsmodel.cpp q3dsmodel.h \
		lib3ds/lib3ds/file.h \
		lib3ds/lib3ds/background.h \
		lib3ds/lib3ds/types.h \
		lib3ds/lib3ds/atmosphere.h \
		lib3ds/lib3ds/shadow.h \
		lib3ds/lib3ds/viewport.h \
		lib3ds/lib3ds/camera.h \
		lib3ds/lib3ds/mesh.h \
		lib3ds/lib3ds/node.h \
		lib3ds/lib3ds/tracks.h \
		lib3ds/lib3ds/tcb.h \
		lib3ds/lib3ds/material.h \
		lib3ds/lib3ds/matrix.h \
		lib3ds/lib3ds/vector.h \
		lib3ds/lib3ds/light.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o q3dsmodel.o q3dsmodel.cpp

q3dsscene.o: q3dsscene.cpp q3dsscene.h \
		q3dsmodel.h \
		lib3ds/lib3ds/file.h \
		lib3ds/lib3ds/background.h \
		lib3ds/lib3ds/types.h \
		lib3ds/lib3ds/atmosphere.h \
		lib3ds/lib3ds/shadow.h \
		lib3ds/lib3ds/viewport.h \
		lib3ds/lib3ds/camera.h \
		lib3ds/lib3ds/mesh.h \
		lib3ds/lib3ds/node.h \
		lib3ds/lib3ds/tracks.h \
		lib3ds/lib3ds/tcb.h \
		lib3ds/lib3ds/material.h \
		lib3ds/lib3ds/matrix.h \
		lib3ds/lib3ds/vector.h \
		lib3ds/lib3ds/light.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o q3dsscene.o q3dsscene.cpp

newcomponent.o: newcomponent.cpp newcomponent.h \
		q3dsmodel.h \
		lib3ds/lib3ds/file.h \
		lib3ds/lib3ds/background.h \
		lib3ds/lib3ds/types.h \
		lib3ds/lib3ds/atmosphere.h \
		lib3ds/lib3ds/shadow.h \
		lib3ds/lib3ds/viewport.h \
		lib3ds/lib3ds/camera.h \
		lib3ds/lib3ds/mesh.h \
		lib3ds/lib3ds/node.h \
		lib3ds/lib3ds/tracks.h \
		lib3ds/lib3ds/tcb.h \
		lib3ds/lib3ds/material.h \
		lib3ds/lib3ds/matrix.h \
		lib3ds/lib3ds/vector.h \
		lib3ds/lib3ds/light.h \
		ui_newcomponent.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o newcomponent.o newcomponent.cpp

frame.o: frame.cpp frame.h \
		q3dsmodel.h \
		lib3ds/lib3ds/file.h \
		lib3ds/lib3ds/background.h \
		lib3ds/lib3ds/types.h \
		lib3ds/lib3ds/atmosphere.h \
		lib3ds/lib3ds/shadow.h \
		lib3ds/lib3ds/viewport.h \
		lib3ds/lib3ds/camera.h \
		lib3ds/lib3ds/mesh.h \
		lib3ds/lib3ds/node.h \
		lib3ds/lib3ds/tracks.h \
		lib3ds/lib3ds/tcb.h \
		lib3ds/lib3ds/material.h \
		lib3ds/lib3ds/matrix.h \
		lib3ds/lib3ds/vector.h \
		lib3ds/lib3ds/light.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o frame.o frame.cpp

moc_mainwindow.o: moc_mainwindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_mainwindow.o moc_mainwindow.cpp

moc_newcomponent.o: moc_newcomponent.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_newcomponent.o moc_newcomponent.cpp

####### Install

install:   FORCE

uninstall:   FORCE

FORCE:

