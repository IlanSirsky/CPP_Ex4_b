#include "Game.hpp"
#include "Player.hpp"

using namespace std;

int const MAX_PLAYERS = 6;
using namespace coup;
    Game::Game(){}
    string Game::turn(){
        return player_turn->getName();
    }

    vector<string> Game::players(){
        vector<string> playerNames; 
        for (size_t i = 0; i < playing.size(); i++)
        {
            if (playing.at(i)->isAlive())
            {
                playerNames.push_back(playing.at(i)->getName());
            }
        }
        return playerNames;
    }

    string Game::winner(){
        if (!checkIfGameFinished() || !game_started){
            throw invalid_argument("Game is not over yet or hasn't started yet");
        }
        string winner;
        for (size_t i = 0; i < playing.size(); i++)
        {
            if (playing.at(i)->isAlive()){
                winner = playing.at(i)->getName();
            }
        }
        return winner;
    }

    //adding player to the game
    int Game::addPlayer(Player* p){
        if (playing.size() >= MAX_PLAYERS){
            throw invalid_argument("Game is full");
        }
        if (turn_counter > 0){
            throw invalid_argument("Game is already started");
        }
        playing.push_back(p);
        return (int)(playing.size() - 1);
    }

    //reviving player after assassins's speical coup
    void Game::revivePlayer(Player* p){
        for(size_t i = 0; i < playing.size(); i++){
            if(playing.at(i) == p){
                playing.at(i)->makeAlive();
                break;
            }
        }
    }

    //"killing" a player
    void Game::removePlayer(Player * p){
        last_died = p; //keeping track of the last player that died incase of revival by Contessa
        for(size_t i = 0; i < playing.size(); i++){ //killing the player
            if(playing.at(i) == p){
                playing.at(i)->makeDead();
                break;
            }
        }
    }

    //returns the name of the last player that died
    Player* Game::getLastDied() const{
        return last_died;
    }

    //checks if it's the player's turn
    bool Game::checkIfTurn(Player * p){
        if (playing.size() < 2){
            throw invalid_argument("Not enough players");
        }
        if (!game_started){
            game_started = true;
        }
        int idx = (int)(turn_counter % playing.size());
        if (p->getId() == idx){
            player_turn = playing.at((size_t)(idx + 1) % playing.size());
            return true;
        }
        if (!playing.at((size_t)idx)->isAlive()){
            turn_counter++;
            return checkIfTurn(p);
        }
        return false;
    }

    //checks if the game is finished
    bool Game::checkIfGameFinished(){
        int counter = 0;
        for (size_t i = 0; i < playing.size(); i++)
        {
            if (playing.at(i)->isAlive()){
                counter++;
            }
        }
        if (counter == 1){
            game_finished = true;
            return true;
        }
        return false;
    }

