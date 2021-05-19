#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"


namespace pandemic{

    class Researcher: public Player {

        public:
            Researcher(Board &b, City c);
            Player &discover_cure(Color c) override;
            std::string role() override;
    };
}