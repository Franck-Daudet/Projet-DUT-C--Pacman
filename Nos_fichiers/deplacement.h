#include <vector>
#include <string>
#include <algorithm> 
#include "getch.h"

using namespace std;

void MoveElt (vector<vector<string>> & map,vector<int> pos,vector<int> AddPos){
	map[pos[0]+AddPos[0]][pos[1]+AddPos[1]] = Pacman;
	map[pos[0]][pos[1]]= " ";
}
bool ColisionTest(string & FutureElement){
	string WallList[] = { "\u2550","\u2551","\u2554","\u2557","\u255A","\u255D" };
	if (find(begin(WallList),end(WallList),FutureElement) != end(WallList)) return false;
	else return true;
}
void MoveCharacter (vector<int> & pos,vector<vector<string>> & map){
	char x;
	x=getch();
	cout << x << "test";
	vector<int> AddtoPos ;
	switch (x){
		case 'Z':
		case 'z':
			AddtoPos = {-1,0};
			break;
		case 'Q':
		case 'q':
			AddtoPos = {0,-1};
			break;
		case 'S':
		case 's':
			AddtoPos = {1,0};
			break;
		case 'D':
		case 'd':
			AddtoPos = {0,1};
			break;
	}
	if (ColisionTest(map[pos[0]+AddtoPos[0]][pos[1]+AddtoPos[1]])){
		MoveElt(map,pos,AddtoPos);
		pos[0] += AddtoPos[0];
		pos[1] += AddtoPos[1];	
	}
}
