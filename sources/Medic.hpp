#pragma once
#include "City.hpp"
#include "Color.hpp"
#include "Player.hpp"
#include "Board.hpp"


namespace pandemic{

    class Medic: public Player {

        public:
            Medic(Board &b, City c);
            Medic &treat(City c) override;
            Medic &drive(City c) override; 
            Medic &fly_direct(City c) override;
            Medic &fly_charter(City c) override;
            Medic &fly_shuttle(City c) override;
            std::string role() override;
    };
}