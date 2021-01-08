// Author: Franck Daudet 	

#include "Nos_fichiers/game.h"


using namespace std;

int main() 
{
	while(true)
	{
		int x;
		int y;
		x = Start_Screen();
		if (x==1)
		{
			ClearScreen();
			Launch_Game();
		}
		// if (x==2) -> classment
		// if (x==3) -> settings
		if (x==4) return 0;
		y = End_Screen();
		if (y==1)
		{
			ClearScreen();
			Launch_Game();
		}
		// if (y==2) -> classment
		// if (y==3) -> settings
		if (y==4) return 0;
	}
}
