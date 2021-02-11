#include "Mage.h"

Mage::Mage(): m_hp{ 50 }, m_mana{ 50 }, m_bouclier{ 0 }, m_baton{0}{}
Mage::Mage(Baton* baton) : m_hp{ 50 }, m_mana{ 50 }, m_bouclier{ 0 }, m_baton{ baton } {}

bool Mage::lancerSort(Mage* target, char type)
{
	if (m_mana > 0)
	{
		m_baton->lancerSort(type, target);
		m_mana -= 10;
		return true;
	}
	return false;
}

void Mage::changerBaton(Sort* sorts)
{
	Baton baton{ &sorts };
	*m_baton = baton;
	m_mana = 50;
}
void Mage::recoitDmg(int dmg) 
{
	if (dmg < 0) 
	{
		m_hp += dmg;
	}
	if (dmg > 0) 
	{
		if (m_bouclier >= dmg) 
		{
			m_bouclier -= dmg;
		}
		else 
		{
			m_hp -= (dmg - m_bouclier);
		}
	}
}
void Mage::buff(int dmg) 
{
	if (dmg < 0) 
	{
		m_bouclier -= dmg;
	}
	else 
	{
		m_hp += dmg;
	}
}
int Mage::getHp() 
{
	return m_hp;
}
bool Mage::isAlive()
{
	if(m_hp>0)
	{ 
		return true;
	}
	return false;
}
string Mage::getNomBaton()
{
	return m_baton->getNom();
}
