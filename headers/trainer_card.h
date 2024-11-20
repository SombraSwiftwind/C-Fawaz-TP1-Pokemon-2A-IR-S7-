#ifndef TRAINER_CARD_H
#define TRAINER_CARD_H

#include <string>
#include "card.h"

using namespace std;

class TrainerCard : public Card{
    private:
        string trainerEffect;

    public:
        // Constructor functions
        TrainerCard(const string& trainerName, const string& trainerEffect);

        // Getters
        string getTrainerEffect() const;

        // Setters
        void setTrainerEffect(string& trainerEffect);

        // Functions
        void displayInfo() const override;
};

#endif