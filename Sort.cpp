#include "Sort.h"

Sort::Sort() : m_nom{ "Default" }, m_type{ 'd' }, m_dmg{ 0 } {}
Sort::Sort(string nom, char type, int dmg) : m_nom{ nom }, m_type{ type }, m_dmg{ dmg } {}

void Sort::agir(Mage* mage) 
{
	if (m_type == 'o') 
	{
		mage->recoitDmg(m_dmg);
	}
	if (m_type == 'd')
	{
		mage->buff(m_dmg);
	}
}
string Sort::getNom() {	return m_nom; }

char Sort::getType() { return m_type; }
