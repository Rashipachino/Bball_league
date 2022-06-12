#pragma once
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include  <ctime>
#include <unistd.h>
#include "Team.hpp"


using namespace std;
class League{
    protected:
        vector<Team*> teams;
    public:
        League(vector<Team*> t){
            if(t.size() == 20){
                this->teams = t;
            }
            else{
                for(unsigned long i = 0; i < t.size(); i++){
                   this->teams.push_back(t[i]);
                }
                rand_constructor(20 - t.size());
            }
        }
        League(){
            rand_constructor(20);
        }
        void rand_constructor(int n){
            if(n == 0){
                return;
            }
            vector<int> indexes = {0};
            vector<string> b_ball;
            b_ball.push_back("Golden State Warriors");
            b_ball.push_back("Los Angeles Lakers");
            b_ball.push_back("Boston Celtics");
            b_ball.push_back("Toronto Raptors");
            b_ball.push_back("New York Knicks");
            b_ball.push_back("Chicago Bulls");
            b_ball.push_back("Phoenix Suns");
            b_ball.push_back("Dallas Mavericks");
            b_ball.push_back("Philadelphia 76ers");
            b_ball.push_back("Brooklyn Nets");
            b_ball.push_back("Milwaukee Bucks");
            b_ball.push_back("San Antonio Spurs");
            b_ball.push_back("Atlanta Hawks");
            b_ball.push_back("Washington Wizards");
            b_ball.push_back("Sacremento Kings");
            b_ball.push_back("Detroit Pistons");
            b_ball.push_back("Utah Jazz");
            b_ball.push_back("Miami Heat");
            b_ball.push_back("Cleveland Cavaliers");
            b_ball.push_back("Memphis Grizzlies");
            b_ball.push_back("New Orleans Pelicans");
            b_ball.push_back("Charlotee Hornets");
            b_ball.push_back("Minnesota Timberwolves");
            b_ball.push_back("Houston Rockets");
            b_ball.push_back("Indiana Pacers");
            b_ball.push_back("Oklahoma City Thunder");
            b_ball.push_back("Orlando Magic");
            b_ball.push_back("Los Angeles Clippers");
            b_ball.push_back("Denver Nuggets");
            b_ball.push_back("Portland Trail Blazers");
            srand(time(0));
            for(int i = 0; i < n; i++){
                unsigned long index = (unsigned long)rand() % 30; //random number between 0-30
                while (find(indexes.begin(), indexes.end(), index) != indexes.end()){ //team name is already taken
                    //sleep(1);
                    usleep(700000);
                    index = (unsigned long)rand() % 30; //random number between 0-30
                }
                Team* p_team = new Team(b_ball[index]);
                this->teams.push_back(p_team);
                indexes.emplace_back(index);
            }
        }
        // ~League(){
        //     vector<Team*>::iterator it;
        //    for(it = teams.begin(); it != teams.end(); it++){
        //         delete *it;
        //    }
        //    teams.clear();
        //     // for ( auto p : teams )
        //     //     delete p;
        //     // for (unsigned long i = 0; i < teams.size(); i++)
        //     // {
        //     //     cout << i << endl;
        //     //     Team* t = teams.at(i); // not it
        //     //     cout << "team to be deleted: " << t->get_name() << endl;
        //     //     delete t; 
        //     // }
            
        // }
        vector<Team*> get_teams(){
            return this->teams;
        } 
};

