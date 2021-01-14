#include <vector>
#include <string>
#include <iostream>
using namespace std;

const string KReset   ("0");
const string KNoir    ("30");
const string KRouge   ("31");
const string KVert    ("32");
const string KJaune   ("33");
const string KBleu    ("34");
const string KMAgenta ("35");
const string KCyan    ("36");
const string KBCyan   ("46");
const string KBJaune  ("43");
const string Pacman  ("\u15E7");

void Color (const string & coul);
void ShowMap(vector<vector<string>> & Map);
void MoveCharacter (vector<int> pos);
void MoveElt (vector<vector<string>> & map,vector<int> pos,vector<int> AddPos);




void ClearScreen (){
	//Clear the screen
    cout << "\033[H\033[2J";
}
void Color (const string & coul){
	// Allows you to add Color in the terminal
    cout << "\033[" << coul <<"m";
}
void ShowMap(vector<vector<string>> & map){
	ClearScreen ();
	Color(KBCyan);
	Color(KNoir);
	for (int x = 0; x < map.size(); x++) {
		for (int y = 0; y < map[x].size(); y++) {
			if ( map[x][y] == Pacman){
				Color(KJaune);
				cout << map[x][y] ;
				Color(KNoir);
			}
			else cout << map[x][y] ;
		}
		cout << endl;
	}
	Color(KReset);
}
