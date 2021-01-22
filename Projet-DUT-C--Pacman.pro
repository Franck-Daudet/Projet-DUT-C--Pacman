TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    Nos_fichiers/Start-End_Screen.cpp \
    Nos_fichiers/affichage.cpp \
    Nos_fichiers/deplacement.cpp \
    Nos_fichiers/game.cpp \
    Nos_fichiers/getch.cpp \
    Nos_fichiers/settings.cpp \
    Nos_fichiers/triclassement.cpp \
        main.cpp

HEADERS += \
    Nos_fichiers/Start-End_Screen.h \
    Nos_fichiers/affichage.h \
    Nos_fichiers/alias.h \
    Nos_fichiers/deplacement.h \
    Nos_fichiers/game.h \
    Nos_fichiers/getch.h \
    Nos_fichiers/settings.h \
    Nos_fichiers/triclassement.h

DISTFILES += \
    Nos_fichiers/config.yaml
