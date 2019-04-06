#pragma once
#include "pch.h"
#include<iostream>
#include<string>
using namespace std;

class Weapon
{
public:
	// 获取基础伤害
	virtual int getBaseDamage() = 0;

	// 获取吸血
	virtual int getSuckBlood() = 0;

	// 获取是否定身
	virtual bool getHold() = 0;

	// 获取是否暴击
	virtual bool getCrit() = 0;

	string m_WeaponName;  //武器名
	int m_BaseDamage;  //基础伤害
private:

};

