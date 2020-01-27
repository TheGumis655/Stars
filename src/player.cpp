#include "player.hpp"
#include "bullet.hpp"
#include "enemy.hpp"

#include <windows.h>
#include <iostream>
#include <random>

void player::addAmmunition(int count){
    ammunition+=count;
}

void player::player_update(int map_width, int map_height, std::vector <bullet>& bullets)
{
    if(GetKeyState('A') & 0x8000 && x>0)
        x--;
    if(GetKeyState('D') & 0x8000 && x<map_width-1)
        x++;

    if(GetKeyState('1') & 0x8000 )
        ammunition_type=0;
    if(GetKeyState('2') & 0x8000 )
        ammunition_type=1;
    if(GetKeyState('3') & 0x8000 )
        ammunition_type=2;

    if(GetKeyState(VK_SPACE) & 0x8000)
    {
        if(ammunition>0 && ammunition_type==0)
        {
            bullet tmp_bullet(x,map_height-1,'^');
            bullets.push_back(tmp_bullet);
            ammunition--;
        }
        if(ammunition>=2 && ammunition_type==1)
        {
            bullet tmp_bullet(x,map_height-1,'^');
            bullets.push_back(tmp_bullet);

            bullet tmp2_bullet(x,map_height-2,'^');
            bullets.push_back(tmp2_bullet);
            ammunition-=2;
        }

        if(ammunition>=3 && ammunition_type==2)
        {
            bullet tmp_bullet(x,map_height-1,'^');
            bullets.push_back(tmp_bullet);
            if(x>0){
                bullet tmp2_bullet(x-1,map_height-1,'^');
                bullets.push_back(tmp2_bullet);
            }

            if(x<map_width-1){
                bullet tmp3_bullet(x+1,map_height-1,'^');
                bullets.push_back(tmp3_bullet);
            }

            ammunition-=3;
        }

    }
}

void player::createEnemy(std::vector<enemy>& enemies,int map_width){
    for(int a=0; a<(int)lvl; a++)
    {
        enemy enemy_tmp(271,rand()%map_width,0);
        enemies.push_back(enemy_tmp);
    }

}

std::string player::getAmmunition_type(){
    if(ammunition_type==0)
        return "Single Shot";
    if(ammunition_type==1)
        return "Double Shot";
    if(ammunition_type==2)
        return "Wave Shot";
}
void player::increaseLvl(){
    lvl+=0.3;
}

void player::increaseScore(){
    score+=1*lvl;
}

int player::getScore(){
    return score;
}

int player::getX(){
    return x;
}
int player::getAmmunition(){
    return ammunition;
}
char player::getSkin(){
    return skin;
}
int player::getLvl(){
    return lvl;
}

player::player(int Cammunition, char Cskin, int Cx, int Cammunition_type,int Clvl, int CScore)
{
    x=Cx;
    ammunition=Cammunition;
    ammunition_type=Cammunition_type;
    skin=Cskin;
    lvl=Clvl;
    score=CScore;
}

player::~player()
{

}
