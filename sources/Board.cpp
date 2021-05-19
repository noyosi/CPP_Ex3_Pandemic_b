#include "Board.hpp"

using namespace std;
using namespace pandemic;


/**
 * @brief check if the board is clean - no disease cubes
 * 
 * @return true - if the board is clean
 * @return false - if not
 */
bool Board::is_clean() {
    for(auto &i: disease_level) {
        if(i.second!=0) { 
            return false;
        }
    }
    return true;
}

/**
 * @brief return the disease level in the city
 * 
 * @param c 
 * @return int& 
 */
int &Board::operator[](City c){
    return disease_level[c];
}

/**
 * @brief check if two cities are connected
 * 
 * @param c1 
 * @param c2 
 * @return true - if connected
 * @return false - if not
 */
bool Board::is_connected(City &c1, City &c2) {
    return neighboring_cities.at(c1).contains(c2);
}

/**
 * @brief check if there is research station in the city
 * 
 * @param c - represent the city
 * @return true - if there is station
 * @return false - if not
 */
bool Board::is_rs(City c) const {
    return research_stations.contains(c);
}

/**
 * @brief build a research station in the city
 * 
 * @param c - represent the city
 */
void Board::build_rs(City c){
    research_stations.insert(c);
}

/**
 * @brief check if there is a cure for disease in specific color
 * 
 * @param c - represent the city
 * @return true - if there is a cure
 * @return false - if not
 */
bool Board::is_discovered_cure(City c) const{
    return (bool)discovered_cure.count(ct_colors.at(c));
}

/**
 * @brief set a cure for disease in specific color
 * 
 * @param c - represent the color
 */
void Board::set_cure(Color c) {
    discovered_cure.insert(c);
}

/**
 * @brief remove all the cures
 * 
 */
void Board::remove_cures(){
    discovered_cure.clear();
}

/**
 * @brief remove all the research stations
 * 
 */
void Board::remove_stations(){
    research_stations.clear();
}

/**
 * @brief show the board -> disease level, discovered cure & research stations
 * 
 * @param out 
 * @param b 
 * @return std::ostream& 
 */
std::ostream &pandemic::operator<<(std::ostream &out, const Board &b){
const std::string BLACK = "\033[30m";      
const std::string RED  = "\033[31m";      
const std::string YELLOW = "\033[33m";     
const std::string BLUE = "\033[34m";        
const std::string CYN = "\e[0;36m";
const std::string BHMAG = "\e[1;95m";   
const std::string HWHT = "\e[0;97m";

out << BHMAG << "My board" << endl; 

out << HWHT << "Disease level:" << CYN << endl; 
    for(const auto &i: b.disease_level) { //city -> disease level
        out << "\t" << ct_str(i.first) << " -> " << i.second << endl;
    }

out << HWHT << "Discovered cure:" << endl; 
    for(const auto &c: b.discovered_cure){
        switch(c){
            case Color::Red:
                out << RED;
                break;
            case Color::Yellow:
                out << YELLOW;
                break;
            case Color::Blue:
                out << BLUE;
                break;
            case Color::Black:
                out << BLACK;
                break;
            default:
                break;
        }
    out << "\t" << color_str(c) << endl;
    }

out << HWHT << "Research stations:" << CYN << endl; 
    for(const auto &rs: b.research_stations){
        out << "\t" << ct_str(rs) << endl;
    }
return out;
}

std::map<City, std::set<City>> Board::neighboring_cities{
    { Algiers, {Madrid, Paris, Istanbul, Cairo } },
    { Atlanta, {Chicago, Miami, Washington } },
    { Baghdad, {Tehran, Istanbul, Cairo, Riyadh, Karachi } },
    { Bangkok, {Kolkata, Chennai, Jakarta, HoChiMinhCity, HongKong } },
    { Beijing, {Shanghai, Seoul } },
    { Bogota, {MexicoCity, Lima, Miami, SaoPaulo, BuenosAires } },
    { BuenosAires, {Bogota, SaoPaulo } },
    { Cairo, {Algiers, Istanbul, Baghdad, Khartoum, Riyadh } },
    { Chennai, {Mumbai, Delhi, Kolkata, Bangkok, Jakarta } },
    { Chicago, {SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal } },
    { Delhi, {Tehran, Karachi, Mumbai, Chennai, Kolkata } },
    { Essen, {London, Paris, Milan, StPetersburg } },
    { HoChiMinhCity, {Jakarta, Bangkok, HongKong, Manila } },
    { HongKong, {Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei } },
    { Istanbul, {Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow } },
    { Jakarta, {Chennai, Bangkok, HoChiMinhCity, Sydney } },
    { Johannesburg, {Kinshasa, Khartoum } },
    { Karachi, {Tehran, Baghdad, Riyadh, Mumbai, Delhi } },
    { Khartoum, {Cairo, Lagos, Kinshasa, Johannesburg } },
    { Kinshasa, {Lagos, Khartoum, Johannesburg } },
    { Kolkata, {Delhi, Chennai, Bangkok, HongKong } },
    { Lagos, {SaoPaulo, Khartoum, Kinshasa } },
    { Lima, {MexicoCity, Bogota, Santiago } },
    { London, {NewYork, Madrid, Essen, Paris } },
    { LosAngeles, {SanFrancisco, Chicago, MexicoCity, Sydney } },
    { Madrid, {London, NewYork, Paris, SaoPaulo, Algiers } },
    { Manila, {Taipei, SanFrancisco, HoChiMinhCity, Sydney, HongKong } },
    { MexicoCity, {LosAngeles, Chicago, Miami, Lima, Bogota } },
    { Miami, {Atlanta, MexicoCity, Washington, Bogota } },
    { Milan, {Essen, Paris, Istanbul } },
    { Montreal, {Chicago, Washington, NewYork } },
    { Moscow, {StPetersburg, Istanbul, Tehran } },
    { Mumbai, {Karachi, Delhi, Chennai } },
    { NewYork, {Montreal, Washington, London, Madrid } },
    { Osaka, {Taipei, Tokyo } },
    { Paris, {Algiers, Essen, Madrid, Milan, London } },
    { Riyadh, {Baghdad, Cairo, Karachi } },
    { SanFrancisco, {LosAngeles, Chicago, Tokyo, Manila } },
    { Santiago, {Lima } },
    { SaoPaulo, {Bogota, BuenosAires, Lagos, Madrid } },
    { Seoul, {Beijing, Shanghai, Tokyo } },
    { Shanghai, {Beijing, HongKong, Taipei, Seoul, Tokyo } },
    { StPetersburg, {Essen, Istanbul, Moscow } },
    { Sydney, {Jakarta, Manila, LosAngeles } },
    { Taipei, {Shanghai, HongKong, Osaka, Manila } },
    { Tehran, {Baghdad, Moscow, Karachi, Delhi } },
    { Tokyo, {Seoul, Shanghai, Osaka, SanFrancisco } },
    { Washington, {Atlanta, NewYork, Montreal, Miami } }
};