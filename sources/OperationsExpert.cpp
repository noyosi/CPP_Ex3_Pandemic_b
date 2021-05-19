#include "OperationsExpert.hpp"

using namespace std;
using namespace pandemic;

OperationsExpert::OperationsExpert(Board &b, City c): Player(b, c) {}

Player &OperationsExpert::build(){
    board.build_rs(ct); //can build rs & no need to discard a card
    return *this;
}

std::string OperationsExpert::role(){
    return "OperationsExpert";
}