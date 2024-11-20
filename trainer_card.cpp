#include "headers/trainer_card.h"
#include <iostream>
#include <vector>
#include "trainer_card.h"

using namespace std;

TrainerCard::TrainerCard(const string& trainerCardName, const string& trainerEffect )
: Card(trainerCardName), trainerEffect(trainerEffect) {

}


// Getters
string TrainerCard::getTrainerEffect() const {
    return trainerEffect;
}

// Setters
void TrainerCard::setTrainerEffect(string& trainerEffect) {
    this->trainerEffect = trainerEffect;
}

void TrainerCard::displayInfo() const
{
    // Display information about the trainer card
    cout << "Card Name: " << getCardName() << endl;
    cout << "Trainer effect : " << getTrainerEffect() << endl;
}