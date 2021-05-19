#include "Player.hpp"

using namespace std;
using namespace pandemic;

const int five_cards = 5;


Player::Player(Board &b, City c): board(b), ct(c){}

/**
 * @brief take card of specific city
 * 
 * @param c 
 * @return Player& 
 */
Player &Player::take_card(City c){
    cards.insert(c);
    return *this;
}

/**
 * @brief drive from current city to connected city
 * 
 * @param c - represent the destination city
 * @return Player& 
 */
Player &Player::drive(City c){
    if(ct!=c){ 
        if(Board::is_connected(ct, c)){
            ct=c;
        }
        else{
            throw invalid_argument{"Error: " +ct_str(ct)+ " city isn't connected to " +ct_str(c)+ " city"};
        }
    }
    else{
        throw invalid_argument{"Error: you're already in " +ct_str(c)+ " city"};
    }
    return *this;
}

/**
 * @brief fly direct from current city to any city that you have it's card,
 *        and you need to discard the destination city card
 * 
 * @param c - represent the destination city
 * @return Player& 
 */
Player &Player::fly_direct(City c){
    if(ct!=c){
        if(cards.contains(c)){
            cards.erase(c);
            ct=c;
        }
        else {
            throw invalid_argument{"Error: you don't have the card of " +ct_str(c)+ " , your destination city"};
        }
    }
    else {
        throw invalid_argument{"Error: you're already in " +ct_str(c)+ " city"};
    }
    return *this;
}

/**
 * @brief fly charter from current city to any city,
 *        and you need to discard the current city card
 * 
 * @param c - represent the destination city
 * @return Player& 
 */
Player &Player::fly_charter(City c){
    if(ct!=c){
        if(cards.contains(ct)){
            cards.erase(ct);
            ct=c;
        }
        else{
            throw invalid_argument{"Error: you don't have the card of " +ct_str(ct)+ " , your current city"};
        }
    }
    else {
        throw invalid_argument{"Error: you're already in " +ct_str(c)+ " city"};
    }
    return *this;
}

/**
 * @brief if there is a research station in the current city,
 *        you can fly shuttle to any city that also have a research station
 * 
 * @param c - represent the destination city
 * @return Player& 
 */
Player &Player::fly_shuttle(City c){
    if(ct!=c){
        if(board.is_rs(ct) && (board.is_rs(c))){
            ct=c;
        }
        else{
            throw invalid_argument{"Error: both cities must have research stations"};
        }
    }
    else{
        throw invalid_argument{"Error: you're already in " +ct_str(c)+ " city"};
    }
    return *this;
}

/**
 * @brief build a research station in the current city
 * 
 * @return Player& 
 */
Player &Player::build(){
    if(cards.contains(ct)){
        board.build_rs(ct);
        cards.erase(ct);
    }
    else {
        throw invalid_argument{"Error: you don't have the card of " +ct_str(ct)+ " city, so can't build a research station"};
    }
    return *this;
}

/**
 * @brief discover a cure to disease with a specific color,
 *        you need to be in a research station, and discard 5 cards in the disease color
 * 
 * @param c - represent the color
 * @return Player& 
 */
Player &Player::discover_cure(Color c){
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

/**
 * @brief can treat in current city
 * 
 * @param c - represent the city
 * @return Player& 
 */
Player &Player::treat(City c){
    if(ct!=c){ 
        throw invalid_argument{"Error: you need to be in " +ct_str(c)+ " city"};
    }
    if(board[c]==0){
        throw invalid_argument{"Error: there is no disease in " +ct_str(c)+ " city"};
    }
    if(board.is_discovered_cure(c)){
        board[c]=0;
    }
    else{
        board[c]--;
    }
    return *this;
}

/**
 * @brief return the player rule
 * 
 * @return std::string 
 */
std::string Player::role() {
    return p_role;
}