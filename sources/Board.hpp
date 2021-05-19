#pragma once
#include "City.hpp"
#include "Color.hpp"
#include <map>
#include <set>
#include <iostream>

namespace pandemic {

  class Board {

    public:
    static std::map<City, std::set<City>> neighboring_cities;
    std::map<City, int> disease_level; 
    std::set<Color> discovered_cure;
    std::set<City> research_stations;
       
    Board(){}
    int &operator[](City c);
    static bool is_connected(City &c1, City &c2);
    void build_rs(City c);
    bool is_rs(City c) const;
    void set_cure(Color c);
    bool is_discovered_cure(City c) const;
    void remove_cures();
    void remove_stations();
    bool is_clean();
    friend std::ostream &operator<<(std::ostream &out, const Board &b);
  };
}