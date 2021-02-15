#include "Sort.h"

Sort::Sort() : m_nom{ "Default" }, m_type{ 'd' }, m_dmg{ 0 } {}
Sort::Sort(string nom, char type, int dmg) : m_nom{ nom }, m_type{ type }, m_dmg{ dmg } {}

int Sort::agir() 
{
	if (m_type == 'o') 
	{
		return m_dmg;
	}
	else if (m_type == 'd')
	{
		return m_dmg;
	}
	return 0;
}
string Sort::getNom() {	return m_nom; }

char Sort::getType() { return m_type; }
