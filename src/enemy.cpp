#include "enemy.hpp"
#include "player.hpp"
#include <vector>
bool enemy::update(int i,std::vector<enemy>& enemies,int map_height){

    if(y<map_height+5)
        y++;
    else if(y>=map_height+5)
    {
        enemies.erase(enemies.begin()+i);
        return 1;
    }
    return 0;
}

void enemy::destroy(int e,std::vector<enemy>& enemies){
    enemies.erase(enemies.begin()+e);
}

int enemy::getX(){
    return x;
}
int enemy::getY(){
    return y;
}
char enemy::getSkin(){
    return skin;
}
enemy::enemy(char Cskin, int Cx, int Cy)
{
    skin=Cskin;
    x=Cx;
    y=Cy;
}

enemy::~enemy()
{

}
