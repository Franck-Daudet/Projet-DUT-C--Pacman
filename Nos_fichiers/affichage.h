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

void Couleur (const string & coul);
void ShowMap(vector<vector<string>> & Map);
void MoveCharacter (vector<int> pos);
void MoveElt (vector<vector<string>> & map,vector<int> pos,vector<int> AddPos);


void ClearScreen (){
	//Permet d'effacer l'écran 
    cout << "\033[H\033[2J";
}
void Couleur (const string & coul){
	//Permet de rajouter de la couleur dans le terminal 
    cout << "\033[" << coul <<"m";
}
void ShowMap(vector<vector<string>> & map){
	ClearScreen ();
	Couleur(KBCyan);
	Couleur(KNoir);
	for (int x = 0; x < map.size(); x++) {
		for (int y = 0; y < map[x].size(); y++) {
			if ( map[x][y] == "\u15E7"){ //Pacman
				Couleur(KJaune);
				cout << map[x][y] ;
				Couleur(KNoir);
			}
			else cout << map[x][y] ;
		}
		cout << endl;
	}
	Couleur(KReset);
}