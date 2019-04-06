#include "pch.h"
#include "Monster.h"
using namespace std;

Monster::Monster()
{
	this->m_Hp = 300;
	this->m_Atk = 70;
	this->m_Def = 40;
	this->m_Hold = false;
	this->m_Name = "通天教主";
}

void Monster::Attack(Hero * hero)
{
	if (this->m_Hold)
	{
		cout << "怪物“" << this->m_Name << "”被定身了" << endl;
		return;
	}
	int damage = (this->m_Atk - hero->m_Def) > 0 ? this->m_Atk - hero->m_Def : 1;
	hero->m_Hp -= damage;
	cout << "怪物“" << this->m_Name << "”对英雄“" << hero->m_Name << "”造成了" << damage << "点伤害" << endl;
}
