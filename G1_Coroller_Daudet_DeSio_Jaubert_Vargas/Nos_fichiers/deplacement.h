#ifndef DEPLACEMENT_H
#define DEPLACEMENT_H

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
#include "alias.h"
using namespace std;
// MATRICE YX (et non XY)
/**
 * @brief MapXSize keep a map size on X axis
 * @param map
 */
unsigned MapXSize (StringMatrix & map);

/**
 * @brief MapYSize keep a map size on Y axis
 * @param map
 */

unsigned MapYSize (StringMatrix & map);

/**
 * @brief MoveXElt movement on the X axis
 * @param map
 * @param pos
 * @param NewX
 */

void MoveXElt (StringMatrix & map,vector<int> pos, int NewX);

/**
 * @brief MoveYElt movement on the y axis
 * @param map
 * @param pos
 * @param NewY
 */

void MoveYElt (StringMatrix & map,vector<int> pos, int NewY);
/**
 * @brief MoveElt
 * @param map
 * @param pos
 * @param Addpos
 * @param character
 * @param stringsiton
 * @return
 */
string MoveElt (StringMatrix & map,vector<int> pos,vector<int> Addpos, string character,string stringsiton);

/**
 * @brief ColisionTest test for collision on X and Y axis for walls
 * @param FutureElement
 * @return
 */

bool ColisionTest(string & FutureElement);
/**
 * @brief PacGumTouchTest test for collision on X and Y axis for Pac-gum
 * @param FuturElement
 * @return
 */
bool PacGumTouchTest(string & FuturElement);
/**
 * @brief BonusTouchTest test for collision on X and Y axis for super Pac-gum
 * @param FuturElement
 * @return
 */
bool BonusTouchTest(string & FuturElement);

/**
 * @brief GoingToJump teleport the character to the other side of the map
 * @param map
 * @param AddtoPos
 * @param pos
 * @return
 */

bool GoingToJump(StringMatrix & map,vector<int> & AddtoPos,vector<int> & pos);

/**
 * @brief Jump calculate the teleportation point
 * @param pos
 * @param Addpos
 * @param map
 * @return
 */

string Jump(vector<int> & pos,vector<int> Addpos, StringMatrix & map);
/**
 * @brief MoveList manages Pac-man collisions
 * @param map
 * @param pos
 * @param oldmove
 * @return
 */
IntMatrix MoveList (StringMatrix & map,vector<int> pos,vector<int> oldmove );
/**
 * @brief NextPhantomMove Random ghost movement
 * @param map
 * @param pos
 * @param oldmove
 * @return
 */
vector<int> NextPhantomMove (StringMatrix & map,vector<int> pos,vector<int> oldmove);

/**
 * @brief InputToChar recover the keys to move Pac-man
 * @return
 */
vector<int> InputToChar();
/**
 * @brief MoveCharacter 
 * @param pos
 * @param map
 * @param Addtopos
 * @param character
 * @param stringsiton
 * @return
 */
string MoveCharacter (vector<int> & pos,StringMatrix & map,vector<int> Addtopos,string character,string stringsiton);
/**
 * @brief MovePacman lets know what Pac-man is doing
 * @param pos
 * @param map
 * @return
 */
string MovePacman (vector<int> & pos,StringMatrix & map);

#endif // DEPLACEMENT_H
