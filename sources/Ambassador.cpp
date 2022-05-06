#include "Ambassador.hpp"

using namespace std;
namespace coup{

    //blocking a Captain from stealing coins from another player
    void Ambassador::block(Player& p){ 
        if (p.role() != "Captain"){ //blocks only Captains
            throw invalid_argument("Can only block Captain");
        }
        if (p.getLastOperation() != "steal"){ //blocking only after stealing
            throw invalid_argument("Can only block after stealing");
        }
        this->last_operation = "block";
        int stolen = p.getLastStolen();
        if (stolen == 1){
            p.addMoney(-1);
            p.getLastStolenPlayer()->addMoney(1);
        }
        else if (stolen == 2){
            p.addMoney(-2);
            p.getLastStolenPlayer()->addMoney(2);
        }
        this->last_operation = "block";
    }

    //transferring 1 coin from one player to another, can't be blocked
    void Ambassador::transfer(Player& from_player, Player & to_player){
        if (!this->game.checkIfTurn(this->name)){
            throw invalid_argument("It is not your turn");
        }
        if (money >= MAX_COINS){
            throw invalid_argument("Player has too many coins, must coup");
        }
        this->last_operation = "transfer";
        if (from_player.coins() < 1){ //no transfer happens
            throw invalid_argument("Player has no coins");
        }
        from_player.addMoney(-1);
        to_player.addMoney(1);
        this->game.turn_counter++;
    }
    
    string Ambassador::role(){
        return "Ambassador";
    }
}