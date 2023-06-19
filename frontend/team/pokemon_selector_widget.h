#ifndef POKEMONSELECTORWIDGET_H
#define POKEMONSELECTORWIDGET_H

#include "backend/pokemons/pokemon.h"
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QSpinBox>
#include <QComboBox>

class PokemonSelectorWidget : public QWidget
{
    Q_OBJECT
private:
    QGridLayout* _grid;
    QComboBox* _selectPokemon;
    QLineEdit* _name;
    QSpinBox* _spinBoxHealth;
    QSpinBox* _spinBoxAttack;
    QSpinBox* _spinBoxDefend;
    QSpinBox* _spinBoxSpeed;
    QLabel* _image;
    PokemonTypology::typology _indexPokemon;
    void onSelectPokemon(int index);
public:
    PokemonSelectorWidget(QWidget *parent = nullptr);
    Pokemon* getPokemon() const;
    void refresh(const Pokemon& pokemon);
signals:

};

#endif // POKEMONSELECTORWIDGET_H
