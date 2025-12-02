QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

INCLUDEPATH += "./cpp"


SOURCES += \
    main.cpp \
    mainwindow.cpp \
    cpp/dictionary.cpp \
    cpp/word.cpp \
    cpp/wordFactory.cpp


HEADERS += \
    mainwindow.h \
    cpp/dictionary.h \
    cpp/word.h \
    cpp/wordFactory.h


FORMS += mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
