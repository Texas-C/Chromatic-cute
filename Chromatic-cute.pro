
TEMPLATE = app
TARGET = Chromatic-cute
INCLUDEPATH += .

QT += core widgets

# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += src

# Input
SOURCES += src/Main.cpp \
	src/CLevelManager.cpp

DISTFILES += \
	levels/colors.json \
	levels/levels.json \
	res/palette.png \
	res/splash.png \
	res/zen.wav \
	res/zen2.wav \
	res/zenfirstclick.wav \
	res/zensecondclick.wav

HEADERS += \
	src/CLevelManager.hpp
