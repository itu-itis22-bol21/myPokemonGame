//--- 2023-2024 Spring BLG 252E Object Oriented Programing Assignment 1 ---//
//--------------------------//
//---Name & Surname:Ugur Erkan Bol
//---Student Number:150210074
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
#include <iostream>
#include <stdio.h>
#include <string.h>

#include "pokemon.h"

using namespace std;

pokemon::pokemon(string name, int atkValue) {
  this->name = name;
  this->atkValue = atkValue;
  this->hpValue = 100;
}

pokemon::pokemon(const pokemon& original) : pokemon { original.name, original.atkValue } {}

const bool pokemon::operator==(const pokemon& otherPokemon) {
  return this->name == otherPokemon.name;
}

string pokemon::getName() {
  return this->name;
}

int pokemon::getHpValue() {
  return this->hpValue;
}

int pokemon::getAtkValue() {
  return this->atkValue;
}

// pokedex

pokedex::pokedex() {
  this->value = 0;
}

void pokedex::updatePokedex(pokemon newPokemon) {
  bool isError = false;
  for(int i = 0; i < this->value; i++) {
    isError = this->pokedexArray[i] == newPokemon ? true : false;
  }
  if(isError) { return; }
  this->pokedexArray[value] = newPokemon;
  this->value++;
}

void pokedex::printPokedex() {
  for(int i = 0; i < this->value; i++) {
    cout << this->pokedexArray[i].getName() << endl;
  }
}

// player

player::player(string name, pokemon playerPokemon) {
  this->name = name;
  this->playerPokemon = playerPokemon;
  this->pokeballNumber = 10;
}

int player::showPokemonNumber() {
  return this->pokemonNumber;
}
int player::showPokeballNumber() {
  return this->pokeballNumber;
}
int player::showBadgeNumber() {
  return this->badgeNumber;
}
pokemon player::getPokemon() {
  return this->playerPokemon;
}

void player::battleWon() {
  this->badgeNumber++;
  this->pokeballNumber += 3;
}

void player::catchPokemon() {
  // if(this->pokeballNumber <= 0) {
  //   return;
  // }
  this->pokemonNumber++;
  this->pokeballNumber--;
}

// enemy

enemy::enemy(string name, pokemon enemyPokemon) {
  this->name = name;
  this->enemyPokemon = enemyPokemon;
}

pokemon enemy::getPokemon() {
  return this->enemyPokemon;
}

string enemy::getName() {
  return this->name;
}

//-------------You Can Add Your Functions Down Below-------------//
