#include <iostream>

using namespace std;

struct EnemySpaceShip
{
    int x_coordinate;
    int y_coordinate;
    int weapon_power;
    EnemySpaceShip* p_next_enemy;
};

EnemySpaceShip* p_enemies = NULL;

EnemySpaceShip* getNewEnemy()
{
    EnemySpaceShip* p_ship = new EnemySpaceShip;
    p_ship->x_coordinate = 0;
    p_ship->y_coordinate = 0;
    p_ship->weapon_power = 20;
    p_ship->p_next_enemy = p_enemies;
    p_enemies = p_ship;
    return p_ship;
}

void upgradeWeapons(EnemySpaceShip* p_ship)
{
    p_ship->weapon_power += 10;
}

void printShipInfo(EnemySpaceShip* p_ship)
{
    cout << p_ship->weapon_power << '\n';
}

int main()
{
    EnemySpaceShip* p_enemy = getNewEnemy();
    EnemySpaceShip* p_enemy2 = getNewEnemy();
    EnemySpaceShip* p_enemy3 = getNewEnemy();
    upgradeWeapons(p_enemy);
    printShipInfo(p_enemy);
    printShipInfo(p_enemy2);
    printShipInfo(p_enemy3);

    EnemySpaceShip *p_current = p_enemies;

    while(p_current != NULL)
    {
        upgradeWeapons(p_current);
        p_current = p_current->p_next_enemy;
    }

    printShipInfo(p_enemy);
    printShipInfo(p_enemy2);
    printShipInfo(p_enemy3);
    return 0;
}
