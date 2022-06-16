#pragma once
#include <iostream>
#include <random>
#include "Team.hpp"

constexpr int TALENT = 10;
constexpr int HOME = 51;
constexpr int HOME_S = 55;
constexpr int AWAY = 46;
constexpr int AWAY_S = 50;




using namespace std;

    class Game{
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
                home_score = HOME_S + (rand() % HOME) + home->get_skill_level()*TALENT; 
                away_score = AWAY_S + (rand() % AWAY) + away->get_skill_level()*TALENT;
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
            int get_home_score() const{
                return home_score;
            }
            int get_away_score() const{
                return away_score;
            }
            string winner();
    };
