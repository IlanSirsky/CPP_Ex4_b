#include "Assassin.hpp"


using namespace std;
namespace coup{

    //handles the coup operation for the Assassin
    //can coup with only 3 coins but can be blocked by Contessa
    //using coup with 7 coins can't be blocked
    void Assassin::coup(Player & p){
        if (!this->game.checkIfTurn(this->name)){
            throw invalid_argument("It is not your turn");
        }
        if (this->money < 2){ //checking if there is enough coins
            throw invalid_argument("Not enough coins");
        }
        if (this->money > 2 && this->money < COIN_FOR_COUP){ //using special coup with only 3 coins
            this->game.removePlayer(p.getName());
            this->money -= 3;
            this->last_operation = "assassinate";
        }
        else{ //using normal coup with 7 coins
            this->game.removePlayer(p.getName());
            this->money -= COIN_FOR_COUP;
            this->last_operation = "coup";
        }
        this->game.turn_counter++;
    }
    
    string Assassin::role(){
        return "Assassin";
    }
}