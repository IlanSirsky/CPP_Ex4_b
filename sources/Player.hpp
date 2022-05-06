#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include "Game.hpp"

int const COIN_FOR_COUP = 7;
int const MAX_COINS = 10;


using namespace std;
namespace coup{
    class Player{
        protected:
            Game& game; // the game this player is in
            int money; //amount of coins the player has
            string name; //players' name
            int id; //players' id
            Player(Game& game, const string& name); //abstract constructor
            string last_operation; //keeps the last operation the player performed for blocking purposes

        public:
            string getName();
            void income();
            void foreign_aid();
            virtual void coup(Player p);
            int coins() const;
            virtual string role();
            string getLastOperation();
            void addMoney(int money);

            //for Captain steal operation
            virtual int getLastStolen(){return 0;};
            virtual Player * getLastStolenPlayer(){return NULL;};

            virtual void transfer(Player&, Player&);
            virtual void tax();
            virtual void steal(Player&);
            virtual void block(Player&);
    };
}
