QT       += core gui network sql serialbus serialport axcontainer xlsx charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

#DEFINES += QT_NO_DEBUG_OUTPUT

SOURCES += \
    BaseGraphicsview.cpp \
    ImageWidget.cpp \
    Snap7_sdk/plc_siemens.cpp \
    Snap7_sdk/s7.cpp \
    Snap7_sdk/snap7.cpp \
    dataoper.cpp \
    frmmessagebox.cpp \
    iconhelper.cpp \
    loginform.cpp \
    main.cpp \
    platewidget.cpp \
    qtstreambuf.cpp \
    savelog.cpp \
    titlewidget.cpp \


HEADERS += \
    BaseGraphicsview.h \
    ImageWidget.h \
    Snap7_sdk/plc_siemens.h \
    Snap7_sdk/s7.h \
    Snap7_sdk/snap7.h \
    connection.h \
    dataoper.h \
    frmmessagebox.h \
    iconhelper.h \
    loginform.h \
    myhelper.h \
    objectinfo.h \
    platewidget.h \
    qtstreambuf.h \
    savelog.h \
    stdc++.h \
    titlewidget.h \



FORMS += \
    frmmessagebox.ui \
    loginform.ui \
    platewidget.ui

#adding qtrpt subproject
#INCLUDEPATH += $$PWD/QtRptProject  QtRptProject
#include($$PWD/QtRptProject/QtRPT/QtRPT.pri)

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


RC_ICONS=log.ico


RESOURCES += \
    images.qrc

include(Snap7_sdk.pri)

#adding qtrpt subproject
#INCLUDEPATH += $$PWD/QtRptProject  QtRptProject
#include($$PWD/QtRptProject/QtRPT/QtRPT.pri)
