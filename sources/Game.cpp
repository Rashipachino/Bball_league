#include <iostream>
#include <random>
#include "Game.hpp"

using namespace std;
    string Game::winner(){
        if(this->home_score >= this->away_score){ //tie game goes to the home team
            return this->home->get_name();
        }
        else{
            return this->away->get_name();
        }
    }
     int Game::score(){
        if(this->home_score >= this->away_score){
            return home_score;
        }
        return away_score;
    }
