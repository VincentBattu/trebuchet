#-------------------------------------------------
#
# Project created by QtCreator 2017-05-14T23:38:31
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = trebuchet
CONFIG   -= app_bundle
TEMPLATE = app


INCLUDEPATH +=$$(OPENCV_DIR)\..\..\include

LIBS += -lglu32 \
     -lopengl32 \
    -L$$(OPENCV_DIR)\lib \
    -lopencv_core2413 \
    -lopencv_highgui2413 \
    -lopencv_imgproc2413 \
    -lopencv_features2d2413 \
    -lopencv_calib3d2413

SOURCES += main.cpp\
        mainwindow.cpp \
    glwidget.cpp \
    glwindow.cpp \
    terraindrawer.cpp \
    trebuchetdrawer.cpp \
    targetdrawer.cpp \
    level.cpp \
    projectiledrawer.cpp \
    mass.cpp \
    spring.cpp \
    simulation.cpp

HEADERS  += mainwindow.h \
    glwidget.h \
    glwindow.h \
    terraindrawer.h \
    trebuchetdrawer.h \
    targetdrawer.h \
    level.h \
    projectiledrawer.h \
    mass.h \
    spring.h \
    simulation.h

FORMS    += mainwindow.ui

RESOURCES += \
    images.qrc
