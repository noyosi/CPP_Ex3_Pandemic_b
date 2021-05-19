#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <set>

namespace pandemic{

    class Player {

        protected:
        Board &board;
        City ct;
        std::string p_role;
        std::set<City> cards;

        public:
        Player(Board &b, City c);
        
        Player &take_card(City c);
        virtual Player &drive(City c);
        virtual Player &fly_direct(City c);
        virtual Player &fly_charter(City c);
        virtual Player &fly_shuttle(City c);
        virtual Player &build();
        virtual Player &discover_cure(Color c);
        virtual Player &treat(City c);
        virtual std::string role();
    };
}