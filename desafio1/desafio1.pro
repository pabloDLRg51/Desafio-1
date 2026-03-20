TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    entradas.cpp \
    juego.cpp \
    main.cpp \
    piezas.cpp \
        tablero.cpp

HEADERS += \
    entradas.h \
    juego.h \
    piezas.h \
       tablero.h
