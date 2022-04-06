#include <string>

using namespace std;

#ifndef CHARACTER_H
#define CHARACTER_H

class Character
{
public:
    Character();
    Character(string, int, int);

    void setName(string);
    void setLevel(int);
    void setHealth(int);

    string getName();
    int getLevel();
    int getHealth();

private:
    string name;
    int level;
    int health;
};

#endif