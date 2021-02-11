#include <iostream>
#include"Sort.h"
#include"Baton.h"
#include"Mage.h"

#include"utilitaires.h"
#include<string>

int main() 
{
	Sort foudre{ "Foudre",'o',-10 };
	Sort incinerateur{ "Incinerateur",'o',10 };
	Sort guerison{ "Guerison",'d',10 };
	Sort protection{ "Protection",'d',-10 };

	Sort* sorts[4]{ &foudre,&incinerateur,&guerison,&protection };

	Baton a{ sorts };
	Baton b{ sorts };

	Mage player{&a};
	Mage ai{ &b };
	Mage* premier[2]{&player,&ai};

	char playerInput;
	bool aiInput;

	while (player.isAlive() && ai.isAlive()) 
	{
		if (utilitaires::getRng(0, 1)) 
		{
			premier[0] = &player;
			premier[1] = &ai;
		}
		else
		{
			premier[0] = &ai;
			premier[1] = &player;
		}
		
		cout << "Vous avez "<<player.getHp()<<" hp\n";
		cout << "Votre adeversaire a " << ai.getHp() << " hp\n";
		cout << "Votre baton se nomme " << player.getNomBaton() << "\n";
		cout << "Que voulez vous faire? 'o', pour attaquer 'd' et 'c' pour changer de baton\n";
		cin >> playerInput;
		aiInput = utilitaires::getRng(0, 1);
		system("CLS");
		if(premier[0] == &player)
		{
			actionJoueur(playerInput, premier, sorts);
			actionAi(aiInput, premier, sorts);
		}
		else 
		{
			actionAi(aiInput, premier, sorts);
			actionJoueur(playerInput, premier, sorts);
		}
	}
	if (player.isAlive())
	{
		cout << "Vous avez " << player.getHp() << " hp\n";
		cout << "Votre adeversaire a " << ai.getHp() << " hp\n";
		cout << "Vous avez gagné\n";
	}
	else if (!player.isAlive() && !ai.isAlive()) {
		cout << "Vous avez " << player.getHp() << " hp\n";
		cout << "Votre adeversaire a " << ai.getHp() << " hp\n";
		cout << "Match nul\n";
	}
	else
	{
		cout << "Vous avez " << player.getHp() << " hp\n";
		cout << "Votre adeversaire a " << ai.getHp() << " hp\n";
		cout << "Vous avez perdu\n";
	}
}

void actionJoueur(char playerInput, Mage* premier[2], Sort* sorts[4])
{
	if (playerInput == 'o')
	{
		if (premier[0]->lancerSort(premier[1],'o'))
		{
			cout << "Vous avez touchez votre adversaire\n";
		}
		else
		{
			premier[0]->changerBaton(*sorts);
			cout << "Vous n'avez plus de mana, vous changez donc de baton\n";
		}
	}
	else if (playerInput == 'd')
	{
		if (premier[0]->lancerSort(premier[0],'d'))
		{
			cout << "Vous vous etes buffer\n";
		}
		else
		{
			premier[0]->changerBaton(*sorts);
			cout << "Vous n'avez plus de mana, vous changez donc de baton\n";
		}
	}
	else if (playerInput == 'c')
	{
		premier[0]->changerBaton(*sorts);
		cout << "Vous avez changez de baton\n";
	}
}

void actionAi(int aiInput, Mage* premier[2], Sort* sorts[4])
{
	if (aiInput)
	{
		if (premier[1]->lancerSort(premier[0],'o'))
		{
			cout << "Votre adversaire vous touche\n";
		}
		else
		{
			premier[1]->changerBaton(*sorts);
			cout << "Votre adversaire n'plus de mana, il change donc de baton\n";
		}
	}
	else
	{
		if (premier[1]->lancerSort(premier[1],'d'))
		{
			cout << "Votre adversaire c'est buffer\n";
		}
		else
		{
			premier[1]->changerBaton(*sorts);
			cout << "Votre adversaire n'plus de mana, il change donc de baton\n";
		}
	}
}