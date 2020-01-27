#ifndef ENEMY_HPP
#define ENEMY_HPP
#include <vector>

class enemy
{
    public:
        enemy(char skin, int x, int y);
        ~enemy();
        int getX();
        int getY();
        char getSkin();
        bool update(int i,std::vector<enemy>& enemies,int map_height);
        void destroy(int e,std::vector<enemy>& enemies);

    private:
        int x;
        int y;
        char skin;
};

#endif // ENEMY_HPP
