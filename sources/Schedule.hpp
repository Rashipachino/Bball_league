#pragma once
#include <iostream>
#include <unordered_map>
#include "League.hpp"
#include "Game.hpp"
#include "Team.hpp"
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

class Schedule{
    private:
        vector<vector<Game*>> season_sched; //380 total games 
        League* l;
    public:
        Schedule(League l){
            this->l = &l;
            for (int i = 0; i < 38; i++) //create 38 vectors for the 38 weeks of games
            {
                season_sched.push_back(vector<Game*>());
            }
            vector<Team*> league_teams = l.get_teams();
            unsigned long size = league_teams.size();
            unsigned long k = 0;
            while(k < 19){
                for (unsigned long i = 0; i < size/2; i++)
                {
                    Game* g_home = new Game(league_teams[i], league_teams[size-i-1]);
                    Game *g_away = new Game(league_teams[size-i-1], league_teams[i]);
                    season_sched[k].push_back(g_home); //creates game and adds to season schedule
                    season_sched[season_sched.size()-k-1].push_back(g_away);
                }
                int rotL= 2;               
                rotate(league_teams.begin()+1, league_teams.begin()+(long)league_teams.size()-rotL, league_teams.end());
                k++;
            }
        }
        ~Schedule(){
            for(unsigned long i = 0; i < season_sched.size(); i++){
                for (unsigned long j = 0; j < season_sched[i].size(); j++)
                {
                   delete season_sched.at(i).at(j);
                }
                
            }
        }
        vector<vector<Game*>> get_schedule(){
            return season_sched;
        }
        vector<Game*> get_round(unsigned long i){
            return season_sched[i];
        }
};