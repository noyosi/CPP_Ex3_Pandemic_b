#include "Scientist.hpp"

using namespace std;
using namespace pandemic;

Scientist::Scientist(Board &b, City c, int num): Player(b, c), n(num) {}

Player &Scientist::discover_cure(Color c) {
    if((bool)board.discovered_cure.count(c)){
        return *this;
    }
    if(!board.is_rs(ct)){
        throw invalid_argument{"Error: you need to be in a city with a research station"};
    }
    int cards_num=0;
    for(const auto &i : cards){
        if(ct_colors.at(i)==c){
            cards_num++;
        }
    }
    if(cards_num<n){
        throw invalid_argument{"Error: you need " +to_string(n)+" "+color_str(c)+ " cards"};
    }
    cards_num=1;
    auto card=cards.begin();
    while(card!=cards.end()){
        if(cards_num==n){
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

std::string Scientist::role(){
    return "Scientist";
}