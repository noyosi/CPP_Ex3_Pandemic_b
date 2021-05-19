#include "FieldDoctor.hpp"

using namespace std;
using namespace pandemic;


FieldDoctor::FieldDoctor(Board &b, City c): Player(b, c){}

Player &FieldDoctor::treat(City c){
    if(ct!=c && !Board::is_connected(ct, c)) { //can treat in current city & *in connected city*
        throw invalid_argument{"Error: " + ct_str(ct) + " city isn't connected to " +ct_str(c)+ " city"};
    }
    if(board[c]==0) {
        throw invalid_argument{"Error: there is no disease in " +ct_str(c)+ " city"};
    }
    if(board.is_discovered_cure(c)) {
        board[c]=0;
    }
    else{
        board[c]--;
    }
    return *this;
}

std::string FieldDoctor::role() {
    return "FieldDoctor"; 
}