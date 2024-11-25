#include "headers/pokemon_card.h"
#include <iostream>
#include <vector>

using namespace std;

PokemonCard::PokemonCard(string cardName, string _pokemonType, string _familyName, int _evolutionLevel, int _maxHP, int _HP, int _energyAttached, vector<Attack> _attacks)
: Card(cardName), pokemonType(_pokemonType), familyName(_familyName), evolutionLevel(_evolutionLevel), maxHP(_maxHP), hp(_HP), energyAttached(_energyAttached), attacks(_attacks) {
}

// Constructor definition for Attack struct
Attack::Attack(int _energyCost, int _damage, const string& _description)
: energyCost(_energyCost), damage(_damage), description(_description) {
}


// Getters
string PokemonCard::getPokemonType() const {
    return pokemonType;
}

string PokemonCard::getFamilyName() const {
    return familyName;
}

int PokemonCard::getEvolutionLevel() const {
    return evolutionLevel;
}

int PokemonCard::getMaxHP() const {
    return maxHP;
}

int PokemonCard::getHP() const {
    return hp;
}

int PokemonCard::getEnergyAttached() const {
    return energyAttached;
}


vector<Attack> PokemonCard::getAttacks() const {
    return attacks;
}

// Setters
void PokemonCard::setPokemonType(const string& pokemonType) {
    this->pokemonType = pokemonType;
}

void PokemonCard::setFamilyName(const string& familyName) {
    this->familyName = familyName;
}

void PokemonCard::setEvolutionLevel(int evolutionLevel) {
    this->evolutionLevel = evolutionLevel;
}

void PokemonCard::setMaxHP(int maxHP) {
    this->maxHP = maxHP;
}

void PokemonCard::setHP(int hp) {
    this->hp = hp;
}

void PokemonCard::setEnergyAttached(int energyValue) {
    this->energyAttached = this->energyAttached + energyValue;
}

void PokemonCard::setAttacks(const vector<Attack>& _attacks) {
    this->attacks = _attacks;
}


void PokemonCard::displayInfo() const
{
    // Display information about the Pokemon card
    cout << "Card Name: " << getCardName() << endl;
    cout << "Pokemon Type: " << getPokemonType() << endl;
    cout << "Family Name: " << getFamilyName() << endl;
    cout << "Evolution Level: " << getEvolutionLevel() << endl;
    cout << "Max HP: " << getMaxHP() << endl;
    cout << "Current HP: " << getHP() << endl;
    cout << "Energy attached to the Pokemon: " << getEnergyAttached() << endl;
    cout << "Attacks: " << endl;
    int attackNumber = 1;
    for (const auto& attack : attacks) {
        cout << "Attack #" << attackNumber << ": Name: " << attack.description << ", Energy Cost: " << attack.energyCost << ", Damage: " << attack.damage << endl;
        attackNumber++;
    }
}