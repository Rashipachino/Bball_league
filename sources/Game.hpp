#pragma once
#include <iostream>
#include <random>
#include "Team.hpp"

using namespace std;

    class Game{
        protected:
            Team* home;
            Team* away;
            int home_score;
            int away_score;
        public:
            Game(Team* t1, Team* t2){
                if(t1->get_name() == t2->get_name()){
                    throw invalid_argument("names must be unique!");
                }
                home = t1;
                away = t2;
                home_score = 55 + (rand() % 46) + home->get_skill_level()*10; 
                away_score = 50 + (rand() % 51) + away->get_skill_level()*10;
                if(this->home_score >= this->away_score){
                    this->home->streak_update(1);
                    this->home->points_update(home_score, away_score);
                    this->away->streak_update(0);
                    this->away->points_update(away_score, home_score);
                }
                else{
                    this->away->streak_update(1);
                    this->away->points_update(away_score, home_score);
                    this->home->streak_update(0);
                    this->home->points_update(home_score, away_score);
                }
            }

            Team* get_home_team(){
                return home;
            }
            Team* get_away_team(){
                return away;
            }
            int get_home_score(){
                return home_score;
            }
            int get_away_score(){
                return away_score;
            }
            string winner();
    };