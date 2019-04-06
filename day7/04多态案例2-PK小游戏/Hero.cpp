#include "pch.h"
#include "Hero.h"
using namespace std;

Hero::Hero()
{
	this->m_Name = "北风忆夕";
	this->m_Hp = 500;
	this->m_Atk = 50;
	this->m_Def = 50;
}


// 装备武器
void Hero::EquipWeapon(Weapon * weapon)
{
	this->weapon = weapon;
	cout << "英雄：" << this->m_Name << "装备了：" << weapon->m_WeaponName << endl;
}

// 攻击
void Hero::Attack(Monster * monstor)
{
	int damage = 0;
	int addHp = 0;
	bool isHold = false;
	bool isCrit = false;

	if (this->weapon == NULL)  // 没有装备武器
	{
		damage = this->m_Atk;
	}
	else
	{
		// 基础伤害
		damage = this->m_Atk + this->weapon->getBaseDamage();

		// 计算吸血
		addHp = this->weapon->getSuckBlood();

		// 计算定身
		isHold = this->weapon->getHold();

		// 计算暴击
		isCrit = this->weapon->getCrit();
	}
	if (isCrit)  // 暴击伤害加成
	{
		damage = damage * 2;
		cout << "触发暴击效果！怪物收到双倍伤害：" << damage << endl;
	}
	if (isHold)
	{
		cout << "触发定身效果！怪物停止攻击一回合" << endl;
	}
	if (addHp > 0)
	{
		this->m_Hp += addHp;
		cout << "触发吸血效果！英雄增加血量为：" << addHp << endl;
	}

	// 设置怪物是否定身
	monstor->m_Hold = isHold;

	// 计算真实伤害
	int trueDamage = (damage - monstor->m_Def) > 0 ? damage - monstor->m_Def : 1;

	monstor->m_Hp -= trueDamage;
	cout << "英雄“" << this->m_Name << "”对怪物“" << monstor->m_Name << "”造成了" << trueDamage << "点伤害" << endl;

}
