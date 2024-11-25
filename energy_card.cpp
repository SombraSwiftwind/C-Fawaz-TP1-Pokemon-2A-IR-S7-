#include "headers/energy_card.h"
#include <iostream>

using namespace std;

EnergyCard::EnergyCard(string energyName) 
: Card(energyName), energyType(energyName) {
}

void EnergyCard::displayInfo() const
{
    // Display information about the energy card
    cout << "Card Name: " << getCardName() << endl;
    cout << "Energy Type: " << energyType << endl;
}