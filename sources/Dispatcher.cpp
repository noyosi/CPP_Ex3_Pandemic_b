#include "Dispatcher.hpp"

using namespace std;
using namespace pandemic;


Dispatcher::Dispatcher(Board &b, City c): Player(b, c) {}

Player &Dispatcher::fly_direct(City c){
    if(ct==c){
        throw invalid_argument{"Error: you're already in " +ct_str(c)+ " city"};
    }
    if(board.is_rs(ct)){ //if there is re -> can fly direct, no need to discard a card
        ct=c;
    }
    else{
        return Player::fly_direct(c);
    }
    return *this;
}

std::string Dispatcher::role() {
    return "Dispatcher"; 
}