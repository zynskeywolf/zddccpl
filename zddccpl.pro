QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    Widgets.cpp \
    main.cpp \
    selectmonitor.cpp

HEADERS += \
	Widgets.h \
	selectmonitor.h

target.path = /usr/bin
desktopentry.files = zddccpl.desktop
desktopentry.path = /usr/share/applications
INSTALLS += target desktopentry

unix: CONFIG += link_pkgconfig
unix: PKGCONFIG += ddcutil
