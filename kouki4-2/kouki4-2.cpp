
#include"hero.h"
#include"Enemy.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class Enemy;    //前方宣言

const int MAX_NAME = 16;



// コンストラクタ





void Enemy::operator*(const int i)
{
    _hp *= i;
    _attack *= i;
    _diffence *= i;
}

// コンストラクタ











int main()
{
    bool turn = false;
    //Hero hero = InputHeroStatus();
    //Enemy enemy = InputEnemyStatus();
    char name[MAX_NAME]{ "" };
    int hp = 0;

    printf("ヒーロー名を入力\n> ");
    cin >> name;
    printf("HPを入力\n> ");
    cin >> hp;

    Hero hero(&name[0], hp);

    // ステータス表示
    hero.show();

    printf("エネミー名を入力\n> ");
    cin >> name;
    printf("HPを入力\n> ");
    cin >> hp;

    Enemy enemy(&name[0], hp);

    // ステータス表示
    enemy.show();


    int select = 0;
    while (true) {
        // プレイヤーターン
        printf("攻撃 : 1\, 回復 : 2\n> ");
        cin >> select;

        switch (select)
        {
        case 1:
            hero.attack(&enemy);
            break;
        case 2:
            hero.heal();
            break;
        default:
            break;
        }
        if (enemy.getHp() <= 0) { break; }

        // エネミーターン
        printf("攻撃 : 1\, 回復 : 2\n> ");
        cin >> select;

        switch (select)
        {
        case 1:
            enemy.attack(&hero);
            break;
        default:
            break;
        }
        if (hero.getHp() <= 0) { break; }
    }
}