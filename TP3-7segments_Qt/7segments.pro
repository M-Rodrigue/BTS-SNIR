TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp


win32: LIBS += -L$$PWD/../../../../../../../../Qt/InterfaceQt/librairies/ -lAff7seg

INCLUDEPATH += $$PWD/../../../../../../../../Qt/InterfaceQt/librairies
DEPENDPATH += $$PWD/../../../../../../../../Qt/InterfaceQt/librairies
