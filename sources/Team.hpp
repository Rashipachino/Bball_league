#pragma once
#include <iostream>
#include <unistd.h>

using namespace std;

class Team{
    protected:
        string name;
        double skill_level;
    public:
        Team(string name){
            srand(time(0));
            this->name = name;
            this->skill_level = ((double) rand() / (RAND_MAX)); //between 0-1;
           // sleep(7000000);
        }
        bool operator==(const Team other) const;
        bool operator !=(const Team other) const;


        Team(const Team& other){ //copy constructor
                this->name = other.name;
                this->skill_level = other.skill_level;
            }
        Team& operator=(const Team& other){
                if(this != &other){ //to avoid recursion
                    this->name = other.name;
                    this->skill_level = other.skill_level;
                }
                return *this;
            }
        string get_name(){
            return this->name;
        }
        double get_skill_level(){
            return this->skill_level;
        }
};