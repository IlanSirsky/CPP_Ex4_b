#include "Contessa.hpp"

using namespace std;
namespace coup{

    //blocking an Assassin from using special coup for 3 coins, reviving the killed player
    void Contessa::block(Player& p){
        if (p.role() != "Assassin"){ //only blocks Assassins
            throw invalid_argument("Can only block Assassin");
        }
        if (p.getLastOperation() != "assassinate"){ //blocks only a special coup
            throw invalid_argument("Can block only after assassination");        
        } //revive the killed player
        this->game.revivePlayer(this->game.getLastDied(), this->game.getLastDeadIndex());
        this->last_operation = "block";
    }

    string Contessa::role(){
        return "Contessa";
    }
}