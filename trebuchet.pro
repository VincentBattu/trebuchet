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
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
