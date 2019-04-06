#include "pch.h"
#include "DragonSword.h"
using namespace std;

DragonSword::DragonSword()
{
	this->m_BaseDamage = 20;
	this->m_WeaponName = "屠龙宝刀";
	this->suckRate = 20;
	this->holdRate = 30;
	this->critRate = 40;
}

int DragonSword::getBaseDamage()
{
	return this->m_BaseDamage;
}

int DragonSword::getSuckBlood()
{
	if (isTrigger(suckRate))
	{
		return this->m_BaseDamage * 0.5;  // 按照武器基础伤害一半回血
	}
	return 0;
}

bool DragonSword::getHold()
{
	if (isTrigger(suckRate))
	{
		return true; 
	}
	return false;
}

bool DragonSword::getCrit()
{
	if (isTrigger(suckRate))
	{
		return true; 
	}
	return false;
}

bool DragonSword::isTrigger(int Rate)
{
	// 判断是否出发特效
	int num = rand() % 100 + 1;
	if (num < Rate)
	{
		return true;
	}
	return false;
}
