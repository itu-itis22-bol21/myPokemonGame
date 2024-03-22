//--- 2023-2024 Spring BLG 252E Object Oriented Programing Assignment 1 ---//
//--------------------------//
//---Name & Surname: Ugur Erkan Bol
//---Student Number: 150210074
//--------------------------//

//-------------Do Not Add New Libraries-------------//
//-------------All Libraries Needed Were Given-------------//
#include <iostream> 
#include <stdio.h>
#include <string.h>
#include <fstream>

#include "pokemon.h"

using namespace std;

//-------------Do Not Change These Global Variables-------------//
int NAME_COUNTER = 0;   //Use this to keep track of the enemy names
int POK_COUNTER = 0;    //Use this to keep track of the pokemon names
int PLAYER_POKEMON_ATTACK = 20; //You don't have to use this variable but its here if you need it
int ENEMY_POKEMON_ATTACK = 10;  //You don't have to use this variable but its here if you need it
//--------------------------------------------------------------//

//---If Necessary Add Your Global Variables Here---// 
// 
//
string pokemons[] = {"", "Bulbasaur", "Charmender", "Squirtle", "Pikachu"};
//
//-------------------------------------------------//

//-------------Do Not Change These Function Definitions-------------//
string* readEnemyNames(const char*);
string* readPokemonNames(const char*);
player characterCreate(string, int);
void mainMenu();
void fightEnemy(player*, string*, string*);
void catchPokemon(player*, string*);
//------------------------------------------------------------------//

//---If Necessary Add Your Function Definitions Here---// 
//
//
//
//-----------------------------------------------------//

//-------------Do Not Change This Function-------------//
int main(int argc, char* argv[]){
	system("clear");

    //---Creating Enemy and Pokemon Name Arrays---//
    string* enemyNames = readEnemyNames(argv[1]);         
    string* pokemonNames = readPokemonNames(argv[2]);
    

    string playerName;
    int pokemonChoice;

    cout << "Welcome to the Pokemon Game! \n" << endl;
    cout << "Please enter your name: "; 
    cin >> playerName;
    cout << "Please choose one of these pokemons as your pokemon: \n1- Bulbasaur \n2- Charmender \n3- Squirtle \nChoice: ";
    cin >> pokemonChoice;

    //---Character Creation--//
    player newPlayer = characterCreate(playerName, pokemonChoice);
    
    int menuChoice;

    while(true){
        mainMenu(); 
        cin>>menuChoice;

        switch (menuChoice){
        case 1:
            fightEnemy(&newPlayer, enemyNames, pokemonNames);
            break;
        case 2:
            catchPokemon(&newPlayer, pokemonNames);
            break;
        case 3:
            cout<<newPlayer.showPokemonNumber()<<endl;
            break;
        case 4:
            cout<<newPlayer.showPokeballNumber()<<endl;
            break;
        case 5:
            cout<<newPlayer.showBadgeNumber()<<endl;
            break;
        case 6:
            cout << endl;
            cout << "\n------- Pokedex -------" <<endl;
            newPlayer.playerPokedex.printPokedex();
            break;
        case 7:
            //---Deletes Dynamic Arrays From Memory and Exits---//

            cout << "Exiting the game..." << endl;

            delete[] enemyNames;
            delete[] pokemonNames;
            return EXIT_SUCCESS;
            break;
  
        default:
            cout << "Please enter a valid number!!!" << endl;
            break;
        }
    }
    return EXIT_FAILURE;
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
string* readEnemyNames(const char* argv){
    //---Code Here---//
    // 
    ifstream enemyNames(argv);
    string line;
    getline(enemyNames, line);
    string* enemies = new string[stoi(line)];
    int i = 0;
    while(getline(enemyNames, line)){
        enemies[i] = line;
        i++;
    }
    return enemies;
    //
    //
    //---------------// 
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
string* readPokemonNames(const char* argv){
    //---Code Here---//
    // 
    //
    ifstream pokemonNames(argv);
    string line;
    getline(pokemonNames, line);
    string* pokemons = new string[stoi(line)];
    int i = 0;
    while(getline(pokemonNames, line)) {
        pokemons[i] = line;
        i++;
    }
    return pokemons;
    //
    //---------------//
    
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
player characterCreate(string playerName, int pokemonChoice){
    //---Code Here---//
    // 
    //
    player newCharacter = player(playerName, pokemon(pokemons[pokemonChoice], PLAYER_POKEMON_ATTACK));
    //
    //---------------//
    return newCharacter;
};
//--------------------------------------------//

//-------------Do Not Change This Function-------------//
void mainMenu(){
    cout << endl;
    cout << "-------- Menu --------" << endl;
    cout << "1. Fight for a badge" << endl;
    cout << "2. Catch a Pokemon" << endl;
    cout << "3. Number of Pokemons" << endl;
    cout << "4. Number of Pokeballs " << endl;
    cout << "5. Number of Badges" << endl;
    cout << "6. Pokedex" << endl;
    cout << "7. Exit" << endl;
    cout << endl;
    cout << "Choice: ";
};
//-----------------------------------------------------//

//-------------Code This Function-------------//
void fightEnemy(player* newPlayer, string* enemyNames, string* pokemonNames){
    //---Code Here---//
    // 
    int choice;
    pokemon enemyPokemon = pokemon(pokemonNames[POK_COUNTER], ENEMY_POKEMON_ATTACK);
    enemy enemyPerson = enemy(enemyNames[NAME_COUNTER], enemyPokemon);
    newPlayer->playerPokedex.updatePokedex(enemyPokemon);
    cout << "You encounter with " << enemyNames[NAME_COUNTER] << " and his/hers pokemon " << pokemonNames[POK_COUNTER] << endl << pokemonNames[POK_COUNTER] << " Health: 100 Attack: " << ENEMY_POKEMON_ATTACK << endl << "1- Fight" << endl << "2- Runaway" << endl << "Choice: ";
    cin >> choice;
    if(choice == 2) { 
        return;
    }
    if(choice != 1) {
        return;
    }
    int maxAtack = PLAYER_POKEMON_ATTACK > ENEMY_POKEMON_ATTACK ? PLAYER_POKEMON_ATTACK : ENEMY_POKEMON_ATTACK;
    int numberOfRound = 100 / maxAtack;
    for(int i = 1; i <= numberOfRound; i++) {
        cout << "Your Pokemons Healt: " << 100 - i * ENEMY_POKEMON_ATTACK << endl << enemyNames[NAME_COUNTER] << " Pokemons Healt: " << 100 - i * PLAYER_POKEMON_ATTACK << endl;
        if (i != numberOfRound) {
            cout << "1- Fight" << endl << "2- Runaway" << endl << "Choice: ";
            cin >> choice;
        }
        if (i == numberOfRound) {
            cout << "You Won!" << endl;
            newPlayer->battleWon();
        }
    }
    POK_COUNTER++;
    NAME_COUNTER++;
    //
    //
    //---------------//
};
//--------------------------------------------//

//-------------Code This Function-------------//
void catchPokemon(player* newPlayer, string* pokemonNames){
    //---Code Here---//
    // 
     int choice;
    pokemon enemyPokemon = pokemon(pokemonNames[POK_COUNTER], ENEMY_POKEMON_ATTACK);
    newPlayer->playerPokedex.updatePokedex(enemyPokemon);
    cout << "You encounter with " << pokemonNames[POK_COUNTER] << " Health: 100 Attack: " << ENEMY_POKEMON_ATTACK << endl << "1- Catch" << endl << "2- Runaway" << endl << "Choice: ";
    cin >> choice;
    if(choice == 2) { 
        POK_COUNTER++;
        return;
    }
    if(choice != 1) {
        return;
    }
    cout << "You catch " << pokemonNames[POK_COUNTER] << endl;
    newPlayer->catchPokemon();
    POK_COUNTER++;
    //
    //
    //---------------//
};
//--------------------------------------------//
