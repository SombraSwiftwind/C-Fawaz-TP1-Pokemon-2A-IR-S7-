#include "headers/player.h"
#include <iostream>
#include "headers/energy_card.h"
#include "headers/trainer_card.h"

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

vector<Card*> Player::getBenchCards() const {
    return benchCards;
}

vector<PokemonCard*> Player::getActionCards() const {
    return actionCards;
}

// Setters
void Player::setName(const string& playerName) {
    this->playerName = playerName;
}

void Player::setBenchCards(const vector<Card*>& benchCards) {
    this->benchCards = benchCards;
}

void Player::setActionCards(const vector<PokemonCard*>& actionCards) {
    this->actionCards = actionCards;
}

// Functions
void Player::addCardToBench(Card* card) {
    benchCards.push_back(card);
}

void Player::activatePokemonCard(int pokemonCardNumber) {
    vector<Card*> actualBenchCards = this->getBenchCards();
    if (pokemonCardNumber <= (int) actualBenchCards.size()) {
        PokemonCard* pokemonCard = dynamic_cast<PokemonCard*>(actualBenchCards[pokemonCardNumber]);
        if (pokemonCard != nullptr) {
            actionCards.push_back(pokemonCard);
            benchCards.erase(benchCards.begin() + pokemonCardNumber);
            cout << endl << getName() << " is activating a Pokemon card: " << pokemonCard->getCardName();
        }
    } else {cout << "Invalid card number" << endl;}
}

void Player::attachEnergyCard(int energyCardNumber, int pokemonCardNumber) {
    vector<Card*> actualBenchCards = this->getBenchCards();
    if (energyCardNumber <= (int) actualBenchCards.size() && pokemonCardNumber <= (int) actionCards.size()) {
        EnergyCard* energyCard = dynamic_cast<EnergyCard*>(actualBenchCards[energyCardNumber]);
        PokemonCard* pokemonCard = dynamic_cast<PokemonCard*>(actionCards[pokemonCardNumber]);
        if (energyCard != nullptr && pokemonCard != nullptr) {
            if (energyCard->getCardName() == pokemonCard->getPokemonType()) {
                pokemonCard->setEnergyAttached(pokemonCard->getEnergyAttached());
                benchCards.erase(benchCards.begin() + energyCardNumber);
                cout << endl << getName() << " is attaching an energy card of type " << energyCard->getCardName() << " attached to " << pokemonCard->getCardName() << endl;
            }
        }
    } else {cout << endl << "Invalid card number" << endl;}
}

void Player::displayBench() const {
    cout << endl << "Bench Cards for player " << getName() << ": " << endl;
    for (const auto& card : benchCards) { // const auto& syntax to create a constant reference to each element in the vector (iterable collection) as it iterates. 
    // const: Ensures that the element cannot be modified within the loop.
    // auto: Automatically deduces the type of the element from the container. In this case, it deduces Card*.
    // &: Uses a reference to avoid copying the element, which is more efficient.
        card->displayInfo();
    }
    cout << endl;
}

void Player::displayAction() const {
    cout << endl << "Action Cards for player " << getName() << ": " << endl;
    for (const auto& card : actionCards) {
        card->displayInfo();
    }
    cout << endl;
}

void Player::attack(int pokemonCardNumber, int attackNumber, Player& target, int pokemonTargetNumber) {
    vector<PokemonCard*> actualActionCards = this->getActionCards();
    vector<PokemonCard*> targetActionCards = target.getActionCards();
    if (pokemonCardNumber <= (int) actualActionCards.size() && pokemonTargetNumber <= (int) targetActionCards.size()) {
        PokemonCard* actualPokemonCard = dynamic_cast<PokemonCard*>(actualActionCards[pokemonCardNumber]);
        PokemonCard* targetPokemonCard = dynamic_cast<PokemonCard*>(targetActionCards[pokemonTargetNumber]);
        if (actualPokemonCard != nullptr && targetPokemonCard != nullptr) {
            vector<Attack> attacks = actualPokemonCard->getAttacks();
            if (attackNumber <= (int) attacks.size() && actualPokemonCard->getEnergyAttached() >= attacks[attackNumber].energyCost) {
                Attack attack = attacks[attackNumber];
                targetPokemonCard->setHP(targetPokemonCard->getHP() - attack.damage);
                actualPokemonCard->setEnergyAttached(actualPokemonCard->getEnergyAttached() - attack.energyCost);
            } else {
                cout << endl << "Invalid attack number or not enough energy attached" << endl;
            }
        }
    } else {cout << endl << "Invalid card number" << endl;}
}


void Player::useTrainer(int trainerCardNumber) {
    if (trainerCardNumber <= (int) benchCards.size()) {
        TrainerCard* trainerCard = dynamic_cast<TrainerCard*>(benchCards[trainerCardNumber]);
        if (trainerCard != nullptr) {
            cout << endl << getName() << " is using the Trainer card named " << trainerCard->getCardName() << " to: " << trainerCard->getTrainerEffect() << endl;
        }
    } else {cout << endl << "Invalid card number or the card isn't a Trainer card" << endl;}
}
