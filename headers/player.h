#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "card.h"
#include "pokemon_card.h"

using namespace std;

class Player {
    private:
        string playerName;
        vector<Card*> benchCards; // Vecteur de cartes (trainer, pokemon, energy), c'est le deck des cartes en réserve
        vector<PokemonCard*> actionCards; // Vecteur de cartes (trainer, pokemon, energy), c'est le deck des cartes d'action Pokemon

    public:
        // Constructor functions
        Player(string playerName);

        // Getters
        string getName() const;
        vector<Card*> getBenchCards() const;
        vector<PokemonCard*> getActionCards() const;
        
        // Setters
        void setName(const string& playerName);
        void setBenchCards(const vector<Card*>& benchCards);
        void setActionCards(const vector<PokemonCard*>& actionCards);

        // Functions
        void addCardToBench(Card* card);
        void activatePokemonCard(int pokemonCardNumber);
        void attachEnergyCard(int energyCardNumber, int pokemonCardNumber);
        void displayBench() const;
        void displayAction() const;
        void attack(int pokemonCardNumber, int attackNumber, Player& target, int pokemonTargetNumber);
        void useTrainer(int trainerCardNumber);
};

#endif