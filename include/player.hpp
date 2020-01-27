#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include <iostream>
#include "bullet.hpp"
#include "enemy.hpp"

class player
{
    public:
        player(int ammunition=100, char skin=121, int x=25, int ammunition_type=0, int lvl=1, int score=0);
        ~player();

        void player_update(int map_width, int map_height, std::vector <bullet>& bullets);
        int getX();
        int getAmmunition();
        std::string getAmmunition_type();
        int getLvl();
        char getSkin();
        void createEnemy(std::vector<enemy>& enemies, int map_width);
        void addAmmunition(int count);
        void increaseLvl();
        void increaseScore();
        int getScore();

    private:
        int score;
        float lvl;
        int x;
        int ammunition;
        int ammunition_type; //0-1shot, 1-2shot, 3-wave shot
        char skin;
};

#endif
