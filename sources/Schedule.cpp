// #pragma once
#include <iostream>
#include <unordered_map>
#include "League.hpp"
#include "Game.hpp"
#include "Team.hpp"
#include <random>
#include <vector>
#include <algorithm>
#include "Schedule.hpp"

using namespace std;

vector<vector<Game*>> Schedule::get_schedule(){
    return season_sched;
}
vector<Game*> Schedule::get_round(unsigned long i){
    return season_sched[i];
}
vector<Team*> Schedule::get_stats(){
    return this->stats;
}
vector<Team*> Schedule::top_picks(int n){
    vector<Team*> top;
    for(unsigned long i = 0; i < n; i++){
        top.push_back(stats.at(i));
    }
    return top;
}
int Schedule::longest_w_streak(){
    int longest = 0;
    for(auto *s : stats){
        if(s->get_longest_win_streak() > longest){
            longest = s->get_longest_win_streak();
        }
    }
    return longest;
}
int Schedule::longest_l_streak(){
    int longest = 0;
    for(auto *s : stats){
        if(s->get_longest_lose_streak() > longest){
            longest = s->get_longest_lose_streak();
        }
    }
    return longest;
}
int Schedule::scored_over_lost(){
    int count = 0;
    for(auto *s : stats){
        if(s->get_points_scored() > s->get_points_lost()){
            count++;
        }
    }
    return count;
}
int Schedule::lost_over_scored(){
    int count = 0;
        for(auto *s : stats){
            if(s->get_points_scored() < s->get_points_lost()){
                count++;
            }
        }
        return count;
}
int Schedule::tie_scores(){
    int count = 0;
        for(auto *s : stats){
            if(s->get_points_scored() == s->get_points_lost()){
                count++;
            }
        }
        return count;
}
int Schedule::wins_over_losses(){
    int count = 0;
        for(auto *s : stats){
            if(s->get_wins() > s->get_loses()){
                count++;
            }
        }
        return count;
}
int Schedule::loses_over_wins(){
    int count = 0;
        for(auto *s : stats){
            if(s->get_wins() < s->get_loses()){
                count++;
            }
        }
        return count;
}
int Schedule::tie_wins_losses(){
    int count = 0;
    for(auto *s : stats){
        if(s->get_wins() == s->get_loses()){
            count++;
        }
    }
    return count;
}
