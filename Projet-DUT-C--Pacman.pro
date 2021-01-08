TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp

HEADERS += \
    Nos_fichiers/Start-End_Screen.h \
    Nos_fichiers/affichage.h \
    Nos_fichiers/deplacement.h \
    Nos_fichiers/game.h \
    Nos_fichiers/getch.h

DISTFILES += \
    Nos_fichiers/config.yaml
