#pragma once

#include "Player.hpp"

using namespace std;
namespace coup{
    class Contessa : public Player{
        public:
            Contessa(Game& game, const string& name) : Player(game, name){};
            ~Contessa(){};
            void block(Player& p); 
            virtual string role();
    };
}