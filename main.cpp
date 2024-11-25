#include"headers/card.h"
#include"headers/pokemon_card.h"
#include"headers/energy_card.h"
#include"headers/trainer_card.h"
#include"headers/player.h"
#include <iostream>
#include <string>

using namespace std;

int main ()
{
    Player player1("Hadi");
    player1.addCardToBench(new EnergyCard("Electric"));
    player1.addCardToBench(new EnergyCard("Electric"));
    player1.addCardToBench(new TrainerCard("Ash", "heal all your action pokemon"));
    vector<Attack> pikachuAttacks = { Attack(2 , 20, "thunder bolt"), Attack(3, 30, "thunder storm") };
    player1.addCardToBench(new PokemonCard("Pikachu", "Electric", "Pikachu", 2, 100, 100, 0, pikachuAttacks));
    player1.activatePokemonCard(3);
    player1.attachEnergyCard(0, 0);
    player1.attachEnergyCard(0, 0);
    cout << endl;
    player1.displayBench();
    cout << endl;
    player1.displayAction();
    Player player2("Germain");
    player2.addCardToBench(new EnergyCard("Grass") );
    player2.addCardToBench(new TrainerCard("Brock", "heal all your action pokemon") );
    vector<Attack> bulbasaurAttacks = { Attack(2, 15, "LeechSeed"), Attack(3, 25, "Vine Whip") };
    player2.addCardToBench(new PokemonCard("Bulbasaur", "Grass", "Bulbasaur", 1, 100, 100, 0, bulbasaurAttacks));
    player2.activatePokemonCard(2);
    player2.attachEnergyCard(0, 0);
    cout << endl;
    player2.displayBench();
    cout << endl;
    player2.displayAction();
    player1.attack(0, 0, player2, 0);
    cout << endl;
    player2.displayAction();
    player2.useTrainer(0);
    cout << endl;
    player2.displayAction();
    return 0;
}