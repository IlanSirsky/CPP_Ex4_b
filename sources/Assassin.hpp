#pragma once

#include "Player.hpp"

using namespace std;
namespace coup{
    class Assassin : public Player{
        public:
            Assassin(Game& game, const string& name) : Player(game, name){};
            ~Assassin(){};
            void coup(Player & p);
            virtual string role();
    };
}