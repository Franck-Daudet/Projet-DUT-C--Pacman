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
 * @brief MapXSize 
 * @param map
 */
unsigned MapXSize (StringMatrix & map);

/**
 * @brief MapYSize
 * @param map
 */

unsigned MapYSize (StringMatrix & map);

/**
 * @brief MoveXElt
 * @param map
 * @param pos
 * @param NewX
 */

void MoveXElt (StringMatrix & map,vector<int> pos, int NewX);

/**
 * @brief MoveYElt
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
 * @brief ColisionTest
 * @param FutureElement
 * @return
 */

bool ColisionTest(string & FutureElement);
/**
 * @brief PacGumTouchTest
 * @param FuturElement
 * @return
 */
bool PacGumTouchTest(string & FuturElement);
/**
 * @brief BonusTouchTest
 * @param FuturElement
 * @return
 */
bool BonusTouchTest(string & FuturElement);

/**
 * @brief GoingToJump
 * @param map
 * @param AddtoPos
 * @param pos
 * @return
 */

bool GoingToJump(StringMatrix & map,vector<int> & AddtoPos,vector<int> & pos);

/**
 * @brief Jump
 * @param pos
 * @param Addpos
 * @param map
 * @return
 */

string Jump(vector<int> & pos,vector<int> Addpos, StringMatrix & map);
/**
 * @brief MoveList
 * @param map
 * @param pos
 * @param oldmove
 * @return
 */
IntMatrix MoveList (StringMatrix & map,vector<int> pos,vector<int> oldmove );
/**
 * @brief NextPhantomMove
 * @param map
 * @param pos
 * @param oldmove
 * @return
 */
vector<int> NextPhantomMove (StringMatrix & map,vector<int> pos,vector<int> oldmove);

/**
 * @brief InputToChar
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
 * @brief MovePacman
 * @param pos
 * @param map
 * @return
 */
string MovePacman (vector<int> & pos,StringMatrix & map);

#endif // DEPLACEMENT_H
