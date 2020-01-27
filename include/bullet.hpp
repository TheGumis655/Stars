#ifndef BULLET_HPP
#define BULLET_HPP
#include <vector>

class bullet
{
    public:
        bullet(int x, int y, char skin);
        ~bullet();

        char getSkin();
        int getX();
        int getY();
        bool update(int i, std::vector<bullet>& bullets);
        void destroy(int i, std::vector<bullet>& bullets);

    private:
        int x;
        int y;
        char skin;
};

#endif // BULLET_HPP
