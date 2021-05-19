#include "Medic.hpp"

using namespace std;
using namespace pandemic;


Medic::Medic(Board &b, City c): Player(b, c){}

Medic &Medic::treat(City c){
    if(ct!=c){
        throw invalid_argument{"Error: you need to be in " +ct_str(c)+ " city"};
    }
    if(board[c]==0){
        throw invalid_argument{"Error: there is no disease in " +ct_str(c)+ " city"};
    }
    board[c]=0; //reduce the disease level to zero
    return *this;
}

Medic &Medic::drive(City c){
    Player::drive(c);
    if(board.is_discovered_cure(c)){
        board[c]=0;
    }
    return *this;
}

Medic &Medic::fly_direct(City c){
    Player::fly_direct(c);
    if(board.is_discovered_cure(c)){
        board[c]=0;
    }
    return *this;
}

Medic &Medic::fly_charter(City c){
    Player::fly_charter(c);
    if(board.is_discovered_cure(c)){
        board[c]=0;
    }
    return *this;
}

Medic &Medic::fly_shuttle(City c){
    Player::fly_shuttle(c);
    if(board.is_discovered_cure(c)){
        board[c]=0;
    }
    return *this;
}

std::string Medic::role(){
    return "Medic";
}