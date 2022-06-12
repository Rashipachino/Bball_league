#include <iostream>
#include <stdexcept>
#include "doctest.h"
#include "sources/Team.hpp"
#include "sources/Game.hpp"
#include "sources/League.hpp"
#include "sources/Schedule.hpp"
using namespace std;

TEST_CASE("Team"){
    CHECK_NOTHROW(Team child1 = Team("Rashi"));
    Team child2 = Team("Michal");
    CHECK_EQ(child2.get_name(), "Michal");
    Team mom= Team("Ima");
    CHECK_EQ(mom.get_points_scored(), 0);
    Team dad = Team("Abba");
    CHECK_LT(dad.get_skill_level(), 1);
    CHECK_GT(dad.get_skill_level(), 0);
}
TEST_CASE("Game"){
    Team a = Team("a");
    Team b = Team("b");
    Team c = Team("a");
    Game g1 = Game(&a, &b);
    CHECK_THROWS(Game g2 = Game(&a, &c));
    CHECK_GT(a.get_points_scored(), 0);
    CHECK_EQ(g1.get_home_score(), a.get_points_scored());
    CHECK_EQ(g1.get_away_score(), b.get_points_scored());
}
TEST_CASE("League"){
    Team t1 = Team("t1");
    Team t2 = Team("t2");
    Team t3 = Team("t3");
    Team t4 = Team("t4");
    Team t5 = Team("t5");
    Team t6 = Team("t6");
    Team t7 = Team("t7");
    Team t8 = Team("t8");
    Team t9 = Team("t9");
    Team t10 = Team("t10");
    Team t11 = Team("t11");
    Team t12 = Team("t12");
    Team t13 = Team("t13");
    Team t14 = Team("t14");
    Team t15 = Team("t15");
    Team t16 = Team("t16");
    Team t17 = Team("t17");
    Team t18 = Team("t18");
    Team t19 = Team("t19");
    Team t20 = Team("t20");
    Team t21 = Team("t21");    
    vector<Team*> vec1;
    vec1.push_back(&t1);
    vec1.push_back(&t2);
    vec1.push_back(&t3);
    vec1.push_back(&t4);
    League l = League(vec1);
    CHECK(l.get_teams().size() == 20);
    vector<Team*> vec2;
    vec2.push_back(&t1);
    vec2.push_back(&t2);
    vec2.push_back(&t3);
    vec2.push_back(&t4);
    vec2.push_back(&t5);
    vec2.push_back(&t6);
    vec2.push_back(&t7);
    vec2.push_back(&t8);
    vec2.push_back(&t9);
    vec2.push_back(&t10);
    vec2.push_back(&t11);
    vec2.push_back(&t12);
    vec2.push_back(&t13);
    vec2.push_back(&t14);
    vec2.push_back(&t15);
    vec2.push_back(&t16);
    vec2.push_back(&t17);
    vec2.push_back(&t18);
    vec2.push_back(&t19);
    vec2.push_back(&t20);
    vec2.push_back(&t21);   
    CHECK_THROWS(League l2 = League(vec2));
}
TEST_CASE("Schedule"){
    Team bob = Team("bob");
    Team alice = Team("alice");
    Team harry = Team("harry");
    Team sarah = Team("sarah");
    Team john = Team("john");
    Team beth = Team("beth");
    vector<Team*> vec3;
    vec3.push_back(&bob);
    vec3.push_back(&alice);
    vec3.push_back(&harry);
    vec3.push_back(&sarah);
    vec3.push_back(&john);
    vec3.push_back(&beth);
    League l = League(vec3);
    Schedule s = Schedule(l);
    CHECK_EQ(s.get_schedule().size(), 38);
    for (unsigned long i = 0; i < s.get_schedule().size(); i++)
    {
        CHECK_EQ(s.get_round(i).size(), 10);
    }
    CHECK_EQ(s.get_round(0).size(), 10);
    vector<Team*> top_3;
    for(unsigned long i = 0; i < 3; i++){
        top_3.push_back(s.get_stats().at(i));
    }
    CHECK_EQ(top_3, s.top_picks(3));
    CHECK_EQ((s.wins_over_losses() + s.loses_over_wins() + s.tie_wins_losses()), 20);
    CHECK_EQ((s.scored_over_lost() + s.lost_over_scored() + s.tie_scores()), 20);
    CHECK_GT(s.longest_l_streak(), 0);
    CHECK_GT(s.longest_w_streak(), 0);
}