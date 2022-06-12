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
                home = t1;
                away = t2;
                srand(time(0));
                home_score = 55 + (rand() % 46); 
                away_score = 50 + (rand() % 51);
            }
            // ~Game(){
            //     delete home;
            //     delete away;
            // }
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
            int score();
    };