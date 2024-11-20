#include "headers/card.h"

using namespace std;

// CONSTRUCTEURS / DESTRUCTEURS

// Constructeur par défaut
Card::Card(string cardName)
: cardName(cardName)
{
}

// FONCTIONS MEMBRES

string Card::getCardName() const{
    return cardName;
}

void Card::setCardName(string cardName) {
    this->cardName = cardName;
}