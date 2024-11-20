#include "headers/player.h"
#include <iostream>

using namespace std;

// CONSTRUCTEURS / DESTRUCTEURS

// Constructeur par défaut
Player::Player(string playerName)
: playerName(playerName)
{
}

// FONCTIONS MEMBRES

// Getters
string Player::getName() const {
    return playerName;
}

vector<Card&> Player::getBenchCards() const {
    return benchCards;
}

vector<PokemonCard&> Player::getActionCards() const {
    return actionCards;
}

// Setters
void Player::setName(const string& playerName) {
    this->playerName = playerName;
}

void Player::setBenchCards(const vector<Card&>& benchCards) {
    this->benchCards = benchCards;
}

void Player::setActionCards(const vector<PokemonCard&>& actionCards) {
    this->actionCards = actionCards;
}

// Functions
void Player::addCardToBench(Card& card) {
    benchCards.push_back(card);
}

void Player::activatePokemonCard(int pokemonCardNumber) {
    // Implementation for activating a Pokemon card
}

void Player::attachEnergyCard(int energyCardNumber, int pokemonCardNumber) {
    // Implementation for attaching an energy card to a Pokemon card
}

void Player::displayBench() const {
    cout << "Bench Cards:" << endl;
    for (const auto& card : benchCards) {
        card->displayInfo();
    }
}

void Player::displayAction() const {
    cout << "Action Cards:" << endl;
    for (const auto& card : actionCards) {
        card->displayInfo();
    }
}

void Player::useTrainer(int trainerCardNumber) {
    // Implementation for using a trainer card
}