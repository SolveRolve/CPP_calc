QT       += core gui printsupport core5compat widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    credit.cpp \
    main.cc \
    qcustomplot.cc \
    ../controller/calc_controler.cc\
    ../back_model/back_model.cc\
    mainwindow.cc

HEADERS += \
    ../controller/calc_controler.h\
    credit.h \
    mainwindow.h\
    stdio.h\
    qcustomplot.h

FORMS += \
    credit.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
