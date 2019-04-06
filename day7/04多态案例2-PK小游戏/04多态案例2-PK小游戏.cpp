#include "pch.h"
#include <iostream>
#include "Hero.h"
#include "Monster.h"
#include "Weapon.h"
#include "Knife.h"
#include "DragonSword.h"
using namespace std;

void play()
{
	// 创建怪物
	Monster * monster = new Monster;

	// 创建英雄
	Hero * hero = new Hero;

	// 创建武器
	Weapon *knife = new Knife;
	Weapon *dragon = new DragonSword;

	// 用户选择武器
	cout << "请选择武器：" << endl;
	cout << "1.赤手空拳" << endl;
	cout << "2.小刀" << endl;
	cout << "3.屠龙刀" << endl;

	int oper;
	cin >> oper;
	switch (oper)
	{
	case 1:
		cout << "你还是太年轻！" << endl;
		break;
	case 2:
		hero->EquipWeapon(knife);
		break;
	case 3:
		hero->EquipWeapon(dragon);
		break;
	default:
		break;
	}

	getchar();  // 输入缓冲区里有个回车，需要获取一次值

	int round = 1;
	while (true)
	{
		getchar();
		system("cls");

		cout << "-------当前是第" << round << "回合-------" << endl;

		hero->Attack(monster);
		if (monster->m_Hp <= 0)
		{
			cout << "怪物" << monster->m_Name << "挂了，恭喜！" << endl;
			break;
		}

		monster->Attack(hero);
		if (hero->m_Hp <= 0)
		{
			cout << "英雄" << hero->m_Name << "挂了" << endl;
			break;
		}
		cout << "英雄" << hero->m_Name << "，剩余血量：" << hero->m_Hp << endl;
		cout << "怪物" << monster->m_Name << "，剩余血量：" << monster->m_Hp << endl;
		++round;
	}
	delete monster;
	delete hero;
	delete knife;
	delete dragon;
}

int main()
{
	play();
}
