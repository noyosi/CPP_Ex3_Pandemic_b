#include "Virologist.hpp"

using namespace std;
using namespace pandemic;

Virologist::Virologist(Board &b, City c): Player(b, c){}

Player &Virologist::treat(City c){
    if(ct!=c){ //you need to be in the city you want to treat
        if(!cards.contains(c)){ //can treat any city by discard the city card
            throw invalid_argument{"Error: you need the card of " + ct_str(c) + " city"};
        }
        cards.erase(c);
    }
    if(board[c]==0){
        throw invalid_argument{"Error: there is no disease in " +ct_str(c)+ " city"};
    }
    if(board.is_discovered_cure(c)){
        board[c]=0;
        return *this;
    }
    board[c]--; //treat
    return *this;
}

std::string Virologist::role(){
    return "Virologist";
}