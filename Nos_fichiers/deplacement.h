//#ifndef DEPLACEMENT_H
//#define DEPLACEMENT_H

/*!
 * \file deplacement.h
 * \brief file for moving the character
 * \author Franck Daudet
 * \version 1.4
 * \date 07/01/21
 */

#include <vector>
#include <string>
#include <algorithm>
#include <unistd.h>
#include "getch.h"

using namespace std;
// MATRICE YX (et non XY)

unsigned MapXSize (vector<vector<string>> & map){
	// return X size of the map
	return map[0].size();
}

/**
 * @brief résumé à faire (voir correc prof pour exemple)
 * @param[in, out] map   petit résumé à faire
 * @return (voir exemple)
 */

unsigned MapYSize (vector<vector<string>> & map){
	// return Y size of the map
	return map.size()-1;
}

/**
 * @brief résumé à faire (voir correc prof pour exemple)
 * @param[in, out] map   petit résumé à faire
 * @param[ (à remplir) ] pos   petit résumé à faire
 * @param[ (à remplir) ] NewX  petit résumé à faire
 */

void MoveXElt (vector<vector<string>> & map,vector<int> pos, int NewX){
	// Move X pos of the Element
	map[pos[0]][pos[1]]= " ";
	map[NewX][pos[1]] = "\u15E7";
}

/**
 * @brief résumé à faire (voir correc prof pour exemple)
 * @param[in, out] map   petit résumé à faire
 * @param[ (à remplir) ] pos   petit résumé à faire
 * @param[ (à remplir) ] NewY  petit résumé à faire
 */

void MoveYElt (vector<vector<string>> & map,vector<int> pos, int NewY){
	// Move Y pos of the Element
	map[pos[0]][pos[1]]= " ";
	map[pos[0]][NewY] = "\u15E7";
}

string MoveElt (vector<vector<string>> & map,vector<int> pos,vector<int> Addpos, string character,string stringsiton){
	// Move X and Y pos of the Element
	map[pos[0]][pos[1]]= stringsiton;
	stringsiton = map[pos[0]+Addpos[0]][pos[1]+Addpos[1]];
	map[pos[0]+Addpos[0]][pos[1]+Addpos[1]] = character;
	return stringsiton;
}

/**
 * @brief résumé à faire (voir correc prof pour exemple)
 * @param[in, out] FutureElement   petit résumé à faire
 * @return (voir exemple)
 */

bool ColisionTest(string & FutureElement){
	// Return if the element is in the wall list
	string WallList[] = {"\u2550","\u2551","\u2554","\u2557","\u255A","\u255D" };
	if (find(begin(WallList),end(WallList),FutureElement) != end(WallList))return false;
	else return true;
}

bool PacGumTouchTest(string & FuturElement){       //Vérifie si collision avec bonus
    string BonusList[] = {"."};
    if (find(begin(BonusList),end(BonusList),FuturElement) == end(BonusList)) return true;
    else return false;
}

bool BonusTouchTest(string & FuturElement){       //Vérifie si collision avec bonus
    string BonusList[] = {"¤"};
    if (find(begin(BonusList),end(BonusList),FuturElement) == end(BonusList)) return true;
    else return false;
}

/**
 * @brief résumé à faire (voir correc prof pour exemple)
 * @param[in, out] map   petit résumé à faire
 * @param[in, out] AddtoPos   petit résumé à faire
 * @param[in, out] pos   petit résumé à faire
 * @return (voir exemple)
 */

bool GoingToJump(vector<vector<string>> & map,vector<int> & AddtoPos,vector<int> & pos){
	// Return true if the character is going to jump
	if (pos[0]+AddtoPos[0] < 0 || pos[0]+AddtoPos[0] > MapYSize(map) || pos[1]+AddtoPos[1] < 0 || pos[1]+AddtoPos[1] > MapXSize(map)-1 ) return true;
	else return false;
}

/**
 * @brief résumé à faire (voir correc prof pour exemple)
 * @param[in, out] AddPos   petit résumé à faire
 * @param[in, out] pos   petit résumé à faire
 * @param[in, out] map   petit résumé à faire
 */

void Jump(vector<int> & pos,vector<int> Addpos, vector<vector<string>> & map){
	// Make the character jump
	map[pos[0]][pos[1]]= " ";
	if (pos[0] == 0 && Addpos[0] == -1){
		pos[0] = MapYSize(map);
	}
	else if (pos[0] == MapYSize(map) && Addpos[0] == 1){
		pos[0] = 0;
	}
	else if (pos[1] == 0 && Addpos[1] == -1){
		pos[1] = MapXSize(map)-1;
	}
	else if (pos[1] == MapXSize(map)-1 && Addpos[1] == 1){
		pos[1] = 0;
	}
	map[pos[0]][pos[1]]="\u15E7";
}

vector<vector<int>> MoveList (vector<vector<string>> & map,vector<int> pos,vector<int> oldmove ){
    // return list of possible movement
    vector<vector<int>> movelist;
	bool test = false;
    if (ColisionTest(map[pos[0]-1][pos[1]]) && pos[0] != 1 && oldmove[0] != 1){
        movelist.push_back({-1,0});
		test = true;}

    if (ColisionTest(map[pos[0]][pos[1]-1]) && pos[1] != 1 && oldmove[1] != 1){
        movelist.push_back({0,-1});
		test = true;}

    if (ColisionTest(map[pos[0]+1][pos[1]]) && pos[0] != MapYSize(map)-1 && oldmove[0] != -1){
        movelist.push_back({1,0});
		test = true;}

    if (ColisionTest(map[pos[0]][pos[1]+1]) && pos[1] != MapXSize(map)-2 && oldmove[1] != -1) {
        movelist.push_back({0,1});
		test = true;}
	//If the pacman can move he will have the right to move back
	
    return movelist;
}

vector<int> NextPhantomMove (vector<vector<string>> & map,vector<int> pos,vector<int> oldmove){
    vector<vector<int>> movelist = MoveList (map, pos, oldmove);
	vector<int> movelist2 =movelist[rand()% movelist.size()];
    return movelist2;
}

vector<int> InputToChar(){
	char x;
	x=getch();
	vector<int> Addtopos ;
	switch (x){
		case 'Z':
		case 'z':
			Addtopos = {-1,0};
			break;
		case 'Q':
		case 'q':
			Addtopos = {0,-1};
			break;
		case 'S':
		case 's':
			Addtopos = {1,0};
			break;
		case 'D':
		case 'd':
			Addtopos = {0,1};
			break;
	}
	return Addtopos;
}

string MoveCharacter (vector<int> & pos,vector<vector<string>> & map,vector<int> Addtopos,string character,string stringsiton){
	if (ColisionTest(map[pos[0]+Addtopos[0]][pos[1]+Addtopos[1]])){
		stringsiton = MoveElt(map,pos,Addtopos,character,stringsiton);
		pos[0] += Addtopos[0];
		pos[1] += Addtopos[1];
	}
	return stringsiton;
}

void MovePacman (vector<int> & pos,vector<vector<string>> & map){
	//Movement character whith z,q,s,d	
	vector<int> Addtopos = InputToChar();
	if (GoingToJump(map,pos,Addtopos)){
		Jump(pos,Addtopos,map);
	}
	else if (ColisionTest(map[pos[0]+Addtopos[0]][pos[1]+Addtopos[1]])){
		MoveElt(map,pos,Addtopos,"\u15E7"," ");
		pos[0] += Addtopos[0];
		pos[1] += Addtopos[1];
	}
    else if (PacGumTouchTest(map[pos[0]+Addtopos[0]][pos[1]+Addtopos[1]])){
        //NbPacGumEaten = NbPacGumEaten - 1;
    }
}