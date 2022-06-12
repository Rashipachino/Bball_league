#pragma once
#include <iostream>
#include <unordered_map>
#include "League.hpp"
#include "Game.hpp"
#include "Team.hpp"
#include <random>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Schedule{
    private:
        vector<vector<Game*>> season_sched; //380 total games, 38 vectors representing rounds- each with 10 games inside
        vector<Team*> stats;
    public:
        Schedule(League l){
            //season_sched
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
                int rotL= 1;               
                rotate(league_teams.begin()+1, league_teams.begin()+(long)league_teams.size()-rotL, league_teams.end());
                k++;
            }
            //stats
             for(auto t : league_teams){
                this->stats.push_back(t);
            }
            for (size_t i = 0; i < stats.size() - 1; ++i) {
                for (size_t j = 0; j < stats.size() - i - 1; ++j) {
                    if (stats.at(j)->get_wins() < stats.at(j + 1)->get_wins()){
                        Team tmp = Team(" ");
                        Team* p_t = &tmp;
                        p_t = stats.at(j);
                        stats.at(j) = stats.at(j + 1);
                        stats.at(j + 1) = p_t;
                    }
                    if(stats.at(j)->get_wins() == stats.at(j + 1)->get_wins()){
                        if(stats.at(j)->get_points_scored() < stats.at(j + 1)->get_points_scored()){
                             Team tmp = Team(" ");
                            Team* p_t = &tmp;
                            p_t = stats.at(j);
                            stats.at(j) = stats.at(j + 1);
                            stats.at(j + 1) = p_t;
                        }
                    } 
                }
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
        vector<vector<Game*>> get_schedule();
        vector<Game*> get_round(unsigned long i);
        vector<Team*> get_stats();
        vector<Team*> top_picks(int n);
        int longest_w_streak(); //returns the length of the longest winning streak of the season
        int longest_l_streak(); //returns the length of the longest losing streak of the season
        int scored_over_lost(); //returns the number of teams that scored more points than they lost throughout the season
        int lost_over_scored(); //returns the number of teams that scored less points than they lost throughout the season
        int tie_scores(); //returns the number of teams that tied the overall score of how many points they scored throughout the season and how many points they lost
        int wins_over_losses(); //returns the number of teams that have more wins of the season than losses
        int loses_over_wins(); //returns the number of teams that have more losses of the season than losses
        int tie_wins_losses(); //returns the number of teams that tied how many games they won and lost throughout the season
};