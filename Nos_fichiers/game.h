#include <vector>
#include <string>
#include <iostream>
using namespace std;

#include "deplacement.h"
#include "affichage.h"

vector<vector<string>> kmap{
	{"\u2554","\u2550","\u2550"," "     ,"\u2550","\u2550","\u2557"}, 
	{"\u2551"," "     ," "     ," "     ," "     ," "     ,"\u2551"},
	{"\u2551"," "     ," "     ," "     ," "     ," "     ,"\u2551"},
    {"\u2551"," "     ," "     ," "     ,"\u15E7"," "     ,"\u2551"},
	{"\u2551"," "     ," "     ," "     ," "     ," "     ,"\u2551"},
	{"\u2551"," "     ," "     ," "     ," "     ," "     ,"\u2551"},
    {"\u255A","\u2550","\u2550"," "     ,"\u2550","\u2550","\u255D"}};


void Launch_Game(){
    vector<int> pos;	
	pos.push_back(3);
	pos.push_back(4);
	while (true)
	{
		ShowMap(kmap);
		MoveCharacter(pos,kmap);
	}
}