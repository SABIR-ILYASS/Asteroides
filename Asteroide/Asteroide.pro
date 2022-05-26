QT       += core gui
QT       += opengl
QT       += core gui opengl widgets openglwidgets

win32 {
    win32-msvc* {
        LIBS     += opengl32.lib glu32.lib
    } else {
        LIBS     += -lopengl32 -lglu32
    }
}
else {
        LIBS     += -lGL -lGLU
}


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE  = app
CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    asknombreasteroide.cpp \
    asteroide.cpp \
    chronometer.cpp \
    gamewidget.cpp \
    ground.cpp \
    listasteroide.cpp \
    main.cpp \
    mainwindow.cpp \
    pausewindow.cpp \
    vaisseau.cpp

HEADERS += \
    asknombreasteroide.h \
    asteroide.h \
    chronometer.h \
    gamewidget.h \
    ground.h \
    listasteroide.h \
    mainwindow.h \
    pausewindow.h \
    vaisseau.h

FORMS += \
    asknombreasteroide.ui \
    mainwindow.ui \
    pausewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    texturesAndSond.qrc
