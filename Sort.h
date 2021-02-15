#ifndef DEF_SORT
#define DEF_SORT

#include <string>

using namespace std;

class Sort
{
public:
	Sort();
	Sort(string nom, char type, int dmg);
	int agir();
	string getNom();
	char getType();
private:
	string m_nom;
	char m_type;
	int m_dmg;
};
#endif