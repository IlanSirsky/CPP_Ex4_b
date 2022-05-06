#pragma once

#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include "Game.hpp"

using namespace std;
namespace coup{
    class Game{
        private:
            vector<string> playing;
            string last_died = ""; //name of the last player that died
            int last_dead_index = 0; //index of the last player that died
            bool game_started = false; //whether the game has started or not
            bool game_finished = false; //whether the game has finished or not

        public:
            vector<int> turns; //keeps track of the turns
            size_t turn_counter = 0; //keeps track of the number of turns played
            Game();
            ~Game(){};
            string turn();
            vector<string> players();
            string winner();
            void addPlayer(const string& name);
            void revivePlayer(const string& name, int index);
            void removePlayer(const string& name); 
            string getLastDied() const; 
            int getLastDeadIndex() const; 
            bool checkIfTurn(const string& name);
            bool checkIfGameFinished();
    };
}