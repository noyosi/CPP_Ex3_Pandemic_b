#include "GeneSplicer.hpp"

using namespace std;
using namespace pandemic;


const int five_cards = 5;

GeneSplicer::GeneSplicer(Board &b, City c): Player(b, c){}

Player &GeneSplicer::discover_cure(Color c){
    if((bool)board.discovered_cure.count(c)){
        return *this;
    }
    if(!board.is_rs(ct)){
        throw invalid_argument{"Error: you need to be in a city with a research station"};
    }
    if(cards.size()<five_cards){
        throw invalid_argument{"Error: you need 5 cards"};
    }
    int cards_num=1;
    auto card=cards.begin();
    while(card!=cards.end()){
        if(cards_num==five_cards){
            break; 
        }
        cards_num++;
        card=cards.erase(card);
    }
    board.set_cure(c);
    return *this;
}

std::string GeneSplicer::role(){
    return "GeneSplicer"; 
}    