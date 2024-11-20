#ifndef POKEMON_CARD_H
#define POKEMON_CARD_H

#include <string>
#include <vector>
#include "card.h"

using namespace std;

class PokemonCard : public Card{
    private:
        string pokemonType;
        string familyName;
        int evolutionLevel;
        int maxHP;
        int hp;
        int energyAttached;

        struct Attack {
            int energyCost;
            int damage;
            string description;
        };

        vector<Attack> attacks;

    public:
        // Constructor functions
        PokemonCard(string cardName, string pokemonType, string familyName, int evolutionLevel, int maxHP, int HP, int energyAttached, vector<Attack> attacks);

        // Getters
        string getPokemonType() const;
        string getFamilyName() const;
        int getEvolutionLevel() const;
        int getMaxHP() const;
        int getHP() const;
        int getEnergyAttached() const;
        vector<Attack> getAttacks() const;

        // Setters
        void setPokemonType(const string& pokemonType);
        void setFamilyName(const string& familyName);
        void setEvolutionLevel(int evolutionLevel);
        void setMaxHP(int maxHP);
        void setHP(int hp);
        void setEnergyAttached(int energyValue);
        void setAttacks(const vector<tuple<int, int, string, int>>& attacks);


        // Functions
        void displayInfo() const override;
};

#endif