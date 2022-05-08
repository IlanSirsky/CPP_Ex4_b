#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

int const COIN_FOR_COUP = 7;
int const MAX_COINS = 10;

using namespace std;
namespace coup{
    class Game;
    class Player{
        protected:
            Game* game; // the game this player is in
            int money; //amount of coins the player has
            string name; //players' name
            Player(Game& theGame, const string& name); //abstract constructor
            string last_operation; //keeps the last operation the player performed for blocking purposes
            bool alive; //whether the player is alive or not
            int id; //the player's id

        public:
            string getName();
            int getId() const;
            void income();
            void foreign_aid();
            virtual void coup(Player &p);
            int coins() const;
            virtual string role();
            string getLastOperation();
            void addMoney(int money);

            void makeAlive(){alive = true;};
            void makeDead(){alive = false;};
            bool isAlive(){return alive;};

            //for Captain steal operation
            virtual int getLastStolen(){return 0;};
            virtual Player * getLastStolenPlayer(){return NULL;};

            virtual void transfer(Player&, Player&);
            virtual void tax();
            virtual void steal(Player&);
            virtual void block(Player&);
    };
}
