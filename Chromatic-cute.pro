
TEMPLATE = app
TARGET = Chromatic-cute
INCLUDEPATH += .

QT += core widgets
CONFIG += c++11

# You can make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# Please consult the documentation of the deprecated API in order to know
# how to port your code away from it.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += src
INCLUDEPATH += src/gui
INCLUDEPATH += src/puzzles

# Input
SOURCES += src/Main.cpp \
	src/gui/CCreditsWidget.cpp \
	src/gui/CHomeWidget.cpp \
	src/gui/CMainWindow.cpp \
	src/puzzles/CPuzzleManager.cpp \
	src/puzzles/CPuzzleRectItem.cpp \
	src/puzzles/CPuzzleWidget.cpp \
	src/puzzles/ColorVector.cpp

HEADERS += \
	src/gui/CCreditsWidget.hpp \
	src/gui/CHomeWidget.hpp \
	src/gui/CMainWindow.hpp \
	src/puzzles/CPuzzleManager.hpp \
	src/puzzles/CPuzzleRectItem.hpp \
	src/puzzles/CPuzzleWidget.hpp \
	src/puzzles/ColorVector.hpp

RESOURCES += \
    resources.qrc

FORMS += \
	forms/CCreditsWidget.ui \
	forms/CHomeWidget.ui \
	forms/CMainWindow.ui \
	forms/CPuzzleWidget.ui

DISTFILES += \
	android/AndroidManifest.xml \
	android/build.gradle \
	android/gradle/wrapper/gradle-wrapper.jar \
	android/gradle/wrapper/gradle-wrapper.properties \
	android/gradlew \
	android/gradlew.bat \
	android/res/values/libs.xml

contains(ANDROID_TARGET_ARCH,armeabi-v7a) {
	ANDROID_PACKAGE_SOURCE_DIR = \
		$$PWD/android
}
