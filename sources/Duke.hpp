#pragma once

#include "Player.hpp"

using namespace std;
namespace coup{
    class Duke : public Player{
        public:
            Duke(Game& game, const string& name) : Player(game, name){};
            ~Duke(){};
            void tax();
            void block(Player& p); 
            virtual string role();
    };
}