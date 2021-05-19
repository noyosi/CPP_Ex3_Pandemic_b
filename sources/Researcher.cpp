#include "Researcher.hpp"

using namespace std;
using namespace pandemic;

const int five_cards = 5;

Researcher::Researcher(Board &b, City c): Player(b, c) {}

Player &Researcher::discover_cure(Color c){ //can discover cure in *any city* & not only in rs
    if((bool)board.discovered_cure.count(c)){
        return *this;
    }
    
    int cards_num=0;
    for(const auto &i : cards){
        if(ct_colors.at(i)==c){
            cards_num++;
        }
    }
    if(cards_num<five_cards){
        throw invalid_argument{"Error: you need 5 " +color_str(c)+ " cards"};
    }
    cards_num=1;
    auto card=cards.begin();
    while(card!=cards.end()){
        if(cards_num==five_cards){
            break; 
        }
        if(ct_colors.at(*card)==c){
            cards_num++;
            card=cards.erase(card);
        }
        else {
            ++card;
        }
    }
    board.set_cure(c);
    return *this;
}
    
std::string Researcher::role(){
    return "Researcher";
}