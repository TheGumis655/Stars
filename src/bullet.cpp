#include "bullet.hpp"
#include <vector>
bool bullet::update(int i,std::vector<bullet>& bullets){
        y--;
}

void bullet::destroy(int i,std::vector<bullet>& bullets){
    bullets.erase(bullets.begin()+i);
}

char bullet::getSkin(){
    return skin;
}
int bullet::getX(){
    return x;
}
int bullet::getY(){
    return y;
}

bullet::bullet(int Cx, int Cy, char Cskin)
{
    x=Cx;
    y=Cy;
    skin=Cskin;
}

bullet::~bullet()
{

}
