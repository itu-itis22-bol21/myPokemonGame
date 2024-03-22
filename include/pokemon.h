//--- 2023-2024 Spring BLG 252E Object Oriented Programing Assignment 1 ---//
//--------------------------//
//---Name & Surname:Ugur Erkan Bol
//---Student Number:150210074
//--------------------------//

#ifndef _H
#define _H

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

//-------------Do Not Add Any New Class(es)-------------//

class pokemon{
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
    private:
        string name;
        int hpValue;
        int atkValue;
    public:
        pokemon() = default ;
        pokemon(string , int ); 
        pokemon(const pokemon&);

        const bool operator==(const pokemon&);

        string getName();
        int getHpValue(); 
        int getAtkValue(); 
        
};

class pokedex{
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
    private:
        pokemon pokedexArray[100];
        int value;
    public:
        pokedex();
        void updatePokedex(pokemon);
        void printPokedex();
       
};

class player{
    private:
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
        string name;
        int pokemonNumber;
        int pokeballNumber;
        int badgeNumber;
        pokemon playerPokemon;
    public:
        pokedex playerPokedex;
        player() = default;
        player(string, pokemon);
        int showPokemonNumber();
        int showPokeballNumber();
        int showBadgeNumber();
        pokemon getPokemon();
        void battleWon();
        void catchPokemon();
        
};

class enemy{
    //-------------Do Not Change Given Variables-------------//
    //-------------You Can Add New Variables If Neccessary-------------//
    private:
        string name;
        pokemon enemyPokemon;
    public:
        enemy() = default;
        enemy(string, const pokemon);
        string getName();
        pokemon getPokemon();
        
};

#endif