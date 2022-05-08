#include "Captain.hpp"

using namespace std;
namespace coup{

    //stealing 2 coins from another player, can be blocked by another Captain or an Ambassador
    void Captain::steal(Player& p){
        if (!this->game->checkIfTurn(this)){
            throw invalid_argument("It is not your turn");
        }
        if (money >= MAX_COINS){
            throw invalid_argument("Player has too many coins, must coup");
        }
        this->last_operation = "steal";
        if (p.coins() < 1){ //not stealing anything
            return;
        }
        if (p.coins() == 1){ //stealing 1 coin if there is only 1 coin
            p.addMoney(-1);
            this->money += 1;
            this->last_stolen = 1;
        }
        else{ //stealing 2 coins
            p.addMoney(-2);
            this->money += 2;
            this->last_stolen = 2;
        }
        this->last_stolen_player = &p;
        this->game->turn_counter++;
    }

    //blocking another Captain from stealing coins from another player
    void Captain::block(Player& p){
        if (p.role() != "Captain"){ //blocks only Captains
            throw invalid_argument("Can only block another Captain");
        }
        if (p.getLastOperation() != "steal"){ //blocking only after stealing
            throw invalid_argument("Can only block after stealing");
        }
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

    string Captain::role(){
        return "Captain";
    }

    int Captain::getLastStolen(){
        return this->last_stolen;
    }

    Player* Captain::getLastStolenPlayer(){
        return this->last_stolen_player;
    }
}