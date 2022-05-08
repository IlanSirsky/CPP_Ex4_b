#pragma once

#include "Player.hpp"
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>

using namespace std;
namespace coup{
    class Game{
        private:
            vector<Player *> playing;
            Player* last_died = nullptr; //player to the last player that died
            bool game_started = false; //whether the game has started or not
            bool game_finished = false; //whether the game has finished or not
            Player* player_turn = nullptr; //the player that's currently playing

        public:
            size_t turn_counter = 0; //keeps track of the number of turns played
            Game();
            ~Game(){};
            string turn();
            vector<string> players();
            string winner();
            int addPlayer(Player * p);
            void revivePlayer(Player* p);
            void removePlayer(Player* p);
            Player* getLastDied() const;
            bool checkIfTurn(Player* p);
            bool checkIfGameFinished();
    };
}