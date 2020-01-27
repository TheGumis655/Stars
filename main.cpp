#include <iostream>
#include <windows.h>
#include <vector>

#include "player.hpp"
#include "functions.hpp"
#include "bullet.hpp"
#include "enemy.hpp"

using namespace std;

void you_lose(int lvl, int score)
{
    system("cls");
    cout<<"You lose :("<<endl;
    cout<<"You survived to "<<lvl<<" level"<<endl;
    cout<<"Your score is: "<<score<<endl;
    Sleep(3000);
    system("pause");
}

void settings_check()
{
    cout<<"Hello!"<<endl;
    cout<<"Before we start I have to check if You can see every char"<<endl;
    cout<<"You have to right-click on title bar, and click properties"<<endl;
    cout<<"And set font as \"Raster Fonts\""<<endl;
    cout<<"I recommend also set font size 8x8"<<endl;
    system("pause");
    system("cls");
}

int main()
{
    settings_check();
    int map_width=25;
    int map_height=50;
    char mapa[map_width][map_height];
    player player(100,262,20,1);

    char wall=219;
    char char_enemy=271;
    vector <bullet> bullets;
    vector <enemy> enemies;
    int tick=0;

    while(1)
    {
        //Time and generating enemies
        tick++;
        if(tick==(int)(100/player.getLvl())){
            player.createEnemy(enemies, map_width);
            player.increaseLvl();
            tick=0;
        }

        //Collisions and adding ammunition/score
        for( size_t b = 0; b < bullets.size(); b++ ){
            for( size_t e = 0; e < enemies.size(); e++ ){
                if(bullets[b].getX()==enemies[e].getX() && bullets[b].getY()==enemies[e].getY()){
                   player.addAmmunition(rand()%10);
                   player.increaseScore();
                   bullets[b].destroy(b,bullets);
                   enemies[e].destroy(e,enemies);
                }
                else if(bullets[b].getX()==enemies[e].getX() && bullets[b].getY()-1==enemies[e].getY()){
                    player.addAmmunition(rand()%10);
                    player.increaseScore();
                    bullets[b].destroy(b,bullets);
                    enemies[e].destroy(e,enemies);
                }
            }
        }

        //Updates
        player.player_update(map_width, map_height, bullets);
        for( size_t i = 0; i < bullets.size(); i++ ){
            if(bullets[i].getY()<-5)
                bullets[i].destroy(i,bullets);
        }
        for( size_t i = 0; i < bullets.size(); i++ )
                bullets[i].update(i,bullets);

        for( size_t i = 0; i < enemies.size(); i++ ){
             enemies[i].update(i,enemies,map_height);
        }

        //Checking for lose game
        for( size_t i = 0; i < enemies.size(); i++ ){
                if(enemies[i].getY()>map_height){
                    you_lose(player.getLvl(),player.getScore());
                    return 0;
                }

        }
        //Generate frame
        for(int b=0; b<map_height; b++){
            for(int a=0; a<map_width; a++){
                mapa[a][b]=' ';
            }
        }

        mapa[player.getX()][map_height-1]=player.getSkin();
        for( size_t i = 0; i < bullets.size(); i++ ){
            if(bullets[i].getY()>=0)
                mapa[bullets[i].getX()][bullets[i].getY()]=bullets[i].getSkin();
        }
        for( size_t i = 0; i < enemies.size(); i++ ){
            if(enemies[i].getY()<map_height)
            mapa[enemies[i].getX()][enemies[i].getY()]=enemies[i].getSkin();
        }


        //Draw frame
        gotoxy(0,0);
        hidecursor();
        for(int b=0; b<map_height; b++)
        {
            cout<<wall;
            for(int a=0; a<map_width; a++)
            {
                if(mapa[a][b]==char_enemy)
                    color(12);
                if(mapa[a][b]=='^')
                    color(10);
                cout<<mapa[a][b];
                color(15);
            }
            cout<<wall;
            cout<<endl;
        }

        //Game informations
        gotoxy(map_width+5,5);
        cout<<"Ammunition:"<<player.getAmmunition()<<"       ";
        gotoxy(map_width+5,6);
        cout<<"Ammunition Type:"<<player.getAmmunition_type()<<"        ";
        gotoxy(map_width+5,7);
        cout<<"Lvl:"<<player.getLvl()<<"       ";
        gotoxy(map_width+5,8);
        cout<<"Tick counter:"<<(int)(100/player.getLvl())<<"       ";

    }
}
