#pragma once

#include "Player.hpp"

using namespace std;
namespace coup{
    class Captain : public Player{
        private:
            int last_stolen = 0; //keeps the last amount of coins stolen
            Player* last_stolen_player = NULL; //keeps the last player that was stolen from

        public:
            Captain(Game& game, const string& name) : Player(game, name){};
            ~Captain(){};
            void steal(Player& p);
            void block(Player& p); 
            virtual string role();
            int getLastStolen();
            Player* getLastStolenPlayer();
    };
}