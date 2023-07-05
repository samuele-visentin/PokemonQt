#ifndef TEAMSELECTWIDGET_H
#define TEAMSELECTWIDGET_H

#include <QWidget>
#include <QPushButton>
#include "backend/list.h"
#include "backend/pokemons/pokemon.h"
#include "frontend/team/pokemon_selector_widget.h"

class TeamSelectWidget : public QWidget
{
    Q_OBJECT
private:
    QPushButton* _saveButton;
    QPushButton* _searchButton;
    QPushButton* _addButton;
    QPushButton* _modifyButton;
    QPushButton* _removeButton;
    PokemonSelectorWidget* _selector;
    QString _fileName;
    QLineEdit* _nameToSearch;
    List<Pokemon*> _pokemonList;
    List<Pokemon*>::iterator _iterator;
    int numberPokemon;
private slots:
    void addPokemon();
    void modifyPokemon();
    void removePokemon();
    void findPokemon();
    void saveFile();
public:
    TeamSelectWidget(QWidget *parent = nullptr);
    ~TeamSelectWidget();
    void setFile(const QString& fileName);
signals:
    void returnToMain();
};

#endif // TEAMSELECTWIDGET_H
