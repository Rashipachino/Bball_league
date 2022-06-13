#pragma once
#include <iostream>
#include <unistd.h>

using namespace std;

class Team{
        string name;
        double skill_level;
        int wins;
        int loses;
        int win_streak;
        int lose_streak;
        int longest_win_streak;
        int longest_lose_streak;
        int points_scored;
        int points_lost;

    public:
        Team(string name){
            srand(time(0));
            this->name = std::move(name);
            this->skill_level = ((double) rand() / (RAND_MAX)); //between 0-1;
            this->wins = 0;
            this->loses = 0;
            this->win_streak = 0;
            this->lose_streak = 0;
            this->points_scored = 0;
            this->points_lost = 0;
            this->longest_lose_streak = 0;
            this->longest_win_streak = 0;
        }

        // Team(const Team& other){ //copy constructor
        //     this->name = other.name;
        //     this->skill_level = other.skill_level;
        //     this->wins = other.wins;
        //     this->loses = other.loses;
        //     this->win_streak = other.win_streak;
        //     this->lose_streak = other.lose_streak;
        //     this->points_scored = other.points_scored;
        //     this->points_lost = other.points_lost;
        //     this->longest_lose_streak = other.longest_lose_streak;
        //     this->longest_win_streak = other.longest_win_streak;
        // }
        void streak_update(int res);
        void points_update(int won, int lost);
        int get_points_scored() const;
        int get_points_lost() const;
        int get_longest_win_streak() const;
        int get_longest_lose_streak() const;
        int get_wins() const;
        int get_loses() const;
        string get_name();
        double get_skill_level() const;
        void set_points(int n){
            points_scored = n;
        }
        void set_wins(int n){
            wins = n;
        }
};