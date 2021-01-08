TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Correc_Prof/game.cpp \
        Correc_Prof/gridmanagement.cpp \
        Correc_Prof/nsutil.cpp \
        Correc_Prof/params.cpp \
        main.cpp

HEADERS += \
    Correc_Prof/game.h \
    Correc_Prof/gridmanagement.h \
    Correc_Prof/nsutil.h \
    Correc_Prof/params.h \
    Correc_Prof/type.h \
    Nos_fichiers/Start-End_Screen.h \
    Nos_fichiers/affichage.h \
    Nos_fichiers/deplacement.h \
    Nos_fichiers/game.h \
    Nos_fichiers/getch.h

DISTFILES += \
    Nos_fichiers/config.yaml
