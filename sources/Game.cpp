#include "Game.hpp"

using namespace std;
namespace coup{
    Game::Game(){}
    string Game::turn(){ 
        return playing.at(turn_counter % playing.size()); //returns the name of the player who's turn it is
    }

    vector<string> Game::players(){
        return playing;
    }

    string Game::winner(){
        if (!checkIfGameFinished() || game_started == false){
            throw invalid_argument("Game is not over yet or hasn't started yet");
        }
        return playing.at(0);
    }

    //adding player to the game
    void Game::addPlayer(const string& name){
        if (playing.size() >= 6){
            throw invalid_argument("Game is full");
        }
        if (turn_counter > 0){
            throw invalid_argument("Game is already started");
        }
        playing.push_back(name);
    }

    //reviving player after assassins's speical coup
    void Game::revivePlayer(const string& name, int index){
        if (index < 0 || index > playing.size() + 1){
            throw invalid_argument("Index out of range");
        }
        auto it = playing.begin() + index; //"reviving" the player and adding them to their original position
        playing.insert(it, name);
    }

    //"killing" a player
    void Game::removePlayer(const string& name){
        if (find(playing.begin(), playing.end(), name) == playing.end()){
            throw invalid_argument("Player not in game");
        }
        last_died = name; //keeping track of the last player that died incase of revival by Contessa
        last_dead_index = find(playing.begin(), playing.end(), name) - playing.begin();
        for(int i = 0; i < playing.size(); i++){ //removing the player from the game
            if(playing.at((size_t)i) == name){
                playing.erase(playing.begin() + (long)i);
            }
        }
    }

    //returns the name of the last player that died
    string Game::getLastDied() const{
        return last_died;
    }

    //returns the index of the last player that died
    int Game::getLastDeadIndex() const{
        return last_dead_index;
    }

    //checks if it's the player's turn
    bool Game::checkIfTurn(const string& name){
        if (playing.size() < 2){
            throw invalid_argument("Not enough players");
        }
        if (!game_started){
            game_started = true;
        }
        int idx = find(playing.begin(), playing.end(), name) - playing.begin();
        return (turn_counter % playing.size()) == idx;
    }

    //checks if the game is finished
    bool Game::checkIfGameFinished(){
        if (playing.size() == 1){
            game_finished = true;
            return true;
        }
        return false;
    }
}
