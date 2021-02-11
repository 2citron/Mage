#include "Baton.h"
#include "utilitaires.h"

Baton::Baton() :m_nom{"Staff of void"}, m_sorts{0}{}

Baton::Baton(Sort* sort[4])
{
	m_sorts[0] = sort[utilitaires::getRng(0, 1)]; //offensif
	m_sorts[1] = sort[utilitaires::getRng(2, 3)]; //defensif
	m_nom = m_sorts[0]->getNom() + " de " + m_sorts[1]->getNom(); //"offensif" de "defensif"
}
void Baton::lancerSort(char type, Mage* target) 
{
	for (int i = 0; i < 2; i++)
	{
		if (m_sorts[i]->getType() == type) { //juste une double verification au cas ou les sorts se melange
			m_sorts[i]->agir(target);
		}
	}
}
string Baton::getNom()
{
	return m_nom;
}

