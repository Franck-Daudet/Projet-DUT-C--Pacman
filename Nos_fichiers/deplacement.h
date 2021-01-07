#include <vector>
#include <string>
#include <iostream>
#include "getch.h"

using namespace std;

void MoveElt (vector<vector<string>> & map,vector<int> pos,vector<int> AddPos){
	map[pos[0]+AddPos[0]][pos[1]+AddPos[1]] = "\u15E7";
	map[pos[0]][pos[1]]= " ";
}
void MoveCharacter (vector<int> pos,vector<vector<string>> & map){
	char x;
	x=getch();
	cout << x << "test";
	switch (x){
		case 'Z':
		case 'z':
			MoveElt(map,pos,{-1,0});
			break;
		case 'Q':
		case 'q':
			MoveElt(map,pos,{0,-1});
			break;
		case 'S':
		case 's':
			MoveElt(map,pos,{1,0});
			break;
		case 'D':
		case 'd':
			MoveElt(map,pos,{0,1});
			break;
	}
}
