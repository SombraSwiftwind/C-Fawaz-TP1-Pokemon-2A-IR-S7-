#ifndef CARD_H
#define CARD_H

#include <string>

using namespace std;

class Card {
    private:
        string cardName;

    protected:

    public:
        // Constructor functions
        Card(string cardName);

        // Getters
        string getCardName() const;

        // Setters
        void setCardName(string cardName);

        // Functions
        virtual void displayInfo() const = 0; // Pure virtual function
};

#endif