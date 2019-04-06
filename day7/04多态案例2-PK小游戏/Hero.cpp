#include "pch.h"
#include "Hero.h"
using namespace std;

Hero::Hero()
{
	this->m_Name = "������Ϧ";
	this->m_Hp = 500;
	this->m_Atk = 50;
	this->m_Def = 50;
}


// װ������
void Hero::EquipWeapon(Weapon * weapon)
{
	this->weapon = weapon;
	cout << "Ӣ�ۣ�" << this->m_Name << "װ���ˣ�" << weapon->m_WeaponName << endl;
}

// ����
void Hero::Attack(Monster * monstor)
{
	int damage = 0;
	int addHp = 0;
	bool isHold = false;
	bool isCrit = false;

	if (this->weapon == NULL)  // û��װ������
	{
		damage = this->m_Atk;
	}
	else
	{
		// �����˺�
		damage = this->m_Atk + this->weapon->getBaseDamage();

		// ������Ѫ
		addHp = this->weapon->getSuckBlood();

		// ���㶨��
		isHold = this->weapon->getHold();

		// ���㱩��
		isCrit = this->weapon->getCrit();
	}
	if (isCrit)  // �����˺��ӳ�
	{
		damage = damage * 2;
		cout << "��������Ч���������յ�˫���˺���" << damage << endl;
	}
	if (isHold)
	{
		cout << "��������Ч��������ֹͣ����һ�غ�" << endl;
	}
	if (addHp > 0)
	{
		this->m_Hp += addHp;
		cout << "������ѪЧ����Ӣ������Ѫ��Ϊ��" << addHp << endl;
	}

	// ���ù����Ƿ���
	monstor->m_Hold = isHold;

	// ������ʵ�˺�
	int trueDamage = (damage - monstor->m_Def) > 0 ? damage - monstor->m_Def : 1;

	monstor->m_Hp -= trueDamage;
	cout << "Ӣ�ۡ�" << this->m_Name << "���Թ��" << monstor->m_Name << "�������" << trueDamage << "���˺�" << endl;

}
