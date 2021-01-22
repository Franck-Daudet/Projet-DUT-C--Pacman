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

/**
 * @brief MapXSize keep a map size on X axis
 * @param [in, out] map
 */
unsigned MapXSize (StringMatrix & map);

/**
 * @brief MapYSize keep a map size on Y axis
 * @param [in, out] map
 */

unsigned MapYSize (StringMatrix & map);

/**
 * @brief MoveXElt movement on the X axis
 * @param [in, out] map
 * @param pos
 * @param NewX
 */

void MoveXElt (StringMatrix & map,vector<int> pos, int NewX);

/**
 * @brief MoveYElt movement on the y axis
 * @param [in, out] map
 * @param pos
 * @param NewY
 */

void MoveYElt (StringMatrix & map,vector<int> pos, int NewY);
/**
 * @brief MoveElt
 * @param [in, out] map
 * @param pos
 * @param Addpos
 * @param character
 * @param stringsiton
 * @return Return the element where the 
 */
string MoveElt (StringMatrix & map,vector<int> pos,vector<int> Addpos, string character,string stringsiton);

/**
 * @brief ColisionTest test for collision on X and Y axis for walls
 * @param [in, out] FutureElement
 * @return A COMPLETER /!\
 */

bool ColisionTest(string & FutureElement);
/**
 * @brief PacGumTouchTest test for collision on X and Y axis for Pac-gum
 * @param [in, out] FuturElement
 * @return A COMPLETER /!\
 */
bool PacGumTouchTest(string & FuturElement);
/**
 * @brief BonusTouchTest test for collision on X and Y axis for super Pac-gum
 * @param [in, out] FuturElement
 * @return A COMPLETER /!\
 */
bool BonusTouchTest(string & FuturElement);

/**
 * @brief GoingToJump teleport the character to the other side of the map
 * @param [in, out] map
 * @param [in, out] AddtoPos
 * @param [in, out] pos
 * @return A COMPLETER /!\
 */

bool GoingToJump(StringMatrix & map,vector<int> & AddtoPos,vector<int> & pos);

/**
 * @brief Jump calculate the teleportation point
 * @param [in, out] pos
 * @param Addpos
 * @param [in, out] map
 * @return A COMPLETER /!\
 */

string Jump(vector<int> & pos,vector<int> Addpos, StringMatrix & map);
/**
 * @brief MoveList manages Pac-man collisions
 * @param [in, out] map
 * @param [in, out] pos
 * @param oldmove
 * @return A COMPLETER /!\
 */
IntMatrix MoveList (StringMatrix & map,vector<int> pos,vector<int> oldmove );
/**
 * @brief NextPhantomMove Random ghost movement
 * @param [in, out] map
 * @param [in, out] pos
 * @param oldmove
 * @return A COMPLETER /!\
 */
vector<int> NextPhantomMove (StringMatrix & map,vector<int> pos,vector<int> oldmove);

/**
 * @brief InputToChar Recover the keys to move PacMan
 * @return A COMPLETER /!\
 */
vector<int> InputToChar();
/**
 * @brief MoveCharacter add the different collisions
 * @param [in, out] pos
 * @param [in, out] map
 * @param Addtopos
 * @param character
 * @param stringsiton
 * @return A COMPLETER /!\
 */
string MoveCharacter (vector<int> & pos,StringMatrix & map,vector<int> Addtopos,string character,string stringsiton);
/**
 * @brief MovePacman lets know what Pac-man is doing
 * @param [in, out] pos
 * @param [in, out] map
 * @return A COMPLETER /!\
 */
string MovePacman (vector<int> & pos,StringMatrix & map);

#endif // DEPLACEMENT_H
