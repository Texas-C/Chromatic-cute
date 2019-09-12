
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
INCLUDEPATH += src/gui

# Input
SOURCES += src/Main.cpp \
	src/gui/CMainWindow.cpp \
	src/puzzles/CPuzzleManager.cpp \
	src/puzzles/CPuzzleRectItem.cpp \
	src/puzzles/CPuzzleWidget.cpp

HEADERS += \
	src/gui/CMainWindow.hpp \
	src/puzzles/CPuzzleManager.hpp \
	src/puzzles/CPuzzleRectItem.hpp \
	src/puzzles/CPuzzleWidget.hpp

RESOURCES += \
    resources.qrc

FORMS += \
	forms/CMainWindow.ui \
	forms/CPuzzleWidget.ui
