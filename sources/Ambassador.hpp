#pragma once

#include "Player.hpp"

using namespace std;
namespace coup{
    class Ambassador : public Player{
        public:
            Ambassador(Game& game, const string& name) : Player(game, name){};
            ~Ambassador(){};
            void block(Player& p);
            void transfer(Player& from_player, Player & to_player);
            virtual string role();
    };
}