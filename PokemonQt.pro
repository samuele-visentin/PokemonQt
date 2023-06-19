TARGET = pokemonQt
INCLUDEPATH += .
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    backend/attacks/attack.cpp \
    backend/battle/battle.cpp \
    backend/entity/enemy.cpp \
    backend/entity/entity.cpp \
    backend/entity/player.cpp \
    backend/pokemons/charizard.cpp \
    backend/pokemons/darkrai.cpp \
    backend/pokemons/giratina.cpp \
    backend/pokemons/infernape.cpp \
    backend/pokemons/pikachu.cpp \
    backend/pokemons/pokemon.cpp \
    backend/pokemons/pokemon_typology.cpp \
    backend/status/burned_status.cpp \
    backend/status/freezed_status.cpp \
    backend/status/paralyzed_status.cpp \
    backend/status/scared_status.cpp \
    backend/status/status.cpp \
    frontend/battaglia/attack_widget.cpp \
    frontend/battaglia/battle_scene.cpp \
    frontend/battaglia/entity_visitor.cpp \
    frontend/battaglia/info_widget.cpp \
    frontend/battaglia/notification_text.cpp \
    frontend/battaglia/status_pokemon.cpp \
    frontend/team/pokemon_selector_widget.cpp \
    frontend/team/team_select_widget.cpp \
    main.cpp \
    mainwindow.cpp \
    backend/type.cpp

HEADERS += \
    backend/attacks/attack.h \
    backend/battle/battle.h \
    backend/entity/enemy.h \
    backend/entity/entity.h \
    backend/entity/entityvisitorinterface.h \
    backend/entity/player.h \
    backend/list.h \
    backend/pokemons/charizard.h \
    backend/pokemons/darkrai.h \
    backend/pokemons/giratina.h \
    backend/pokemons/infernape.h \
    backend/pokemons/pikachu.h \
    backend/pokemons/pokemon_typology.h \
    backend/status/burned_status.h \
    backend/status/freezed_status.h \
    backend/status/paralyzed_status.h \
    backend/status/scared_status.h \
    backend/status/status.h \
    frontend/battaglia/attack_widget.h \
    frontend/battaglia/battle_scene.h \
    frontend/battaglia/entity_visitor.h \
    frontend/battaglia/info_widget.h \
    frontend/battaglia/notification_text.h \
    frontend/battaglia/status_pokemon.h \
    frontend/team/pokemon_selector_widget.h \
    frontend/team/team_select_widget.h \
    mainwindow.h \
    backend/pokemons/pokemon.h \
    backend/type.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
