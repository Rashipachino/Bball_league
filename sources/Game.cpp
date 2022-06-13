#include <iostream>
#include <random>
#include "Game.hpp"

using namespace std;
    string Game::winner(){
        if(this->home_score >= this->away_score){ //tie game goes to the home team
            return this->home->get_name();
        }
        return this->away->get_name();
    }