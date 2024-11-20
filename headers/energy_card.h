#ifndef ENERGY_CARD_H
#define ENERGY_CARD_H

#include <string>
#include "card.h"

using namespace std;

class EnergyCard : public Card{
    private:
        string energyType;

    public:
        // Constructor functions
        EnergyCard(string energyName);

        // Functions

};

#endif