#pragma once
#include "pch.h"
#include "Hero.h"
#include<iostream>
#include<string>
using namespace std;

class Hero;


class Monster
{
public:
	Monster();

	string m_Name;
	int m_Atk;  // ������
	int m_Def;  // ������
	int m_Hp;  // Ѫ��
	bool m_Hold;  // �Ƿ񱻶���

	void Attack(Hero * hero);
};
