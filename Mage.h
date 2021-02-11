#ifndef DEF_MAGE
#define DEF_MAGE

#include "Baton.h"
#include "Sort.h"
#include <string>

	using namespace std;

	class Mage
	{
	public:
		Mage();
		Mage(Baton* baton);
		bool lancerSort(Mage* target, char type);
		void changerBaton(Sort* sorts);
		void recoitDmg(int dmg);
		void buff(int dmg);
		int getHp();
		bool isAlive();
		string getNomBaton();
	private:
		int m_hp;
		int m_mana;
		int m_bouclier;
		Baton* m_baton;
	};
#endif
