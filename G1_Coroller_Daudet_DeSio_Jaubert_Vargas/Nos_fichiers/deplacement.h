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

unsigned MapXSize (StringMatrix & map);

/**
 * @brief résumé à faire (voir correc prof pour exemple)
 * @param[in, out] map   petit résumé à faire
 * @return (voir exemple)
 */

unsigned MapYSize (StringMatrix & map);

/**
 * @brief résumé à faire (voir correc prof pour exemple)
 * @param[in, out] map   petit résumé à faire
 * @param[ (à remplir) ] pos   petit résumé à faire
 * @param[ (à remplir) ] NewX  petit résumé à faire
 */

void MoveXElt (StringMatrix & map,vector<int> pos, int NewX);

/**
 * @brief résumé à faire (voir correc prof pour exemple)
 * @param[in, out] map   petit résumé à faire
 * @param[ (à remplir) ] pos   petit résumé à faire
 * @param[ (à remplir) ] NewY  petit résumé à faire
 */

void MoveYElt (StringMatrix & map,vector<int> pos, int NewY);

string MoveElt (StringMatrix & map,vector<int> pos,vector<int> Addpos, string character,string stringsiton);

/**
 * @brief résumé à faire (voir correc prof pour exemple)
 * @param[in, out] FutureElement   petit résumé à faire
 * @return (voir exemple)
 */

bool ColisionTest(string & FutureElement);

bool PacGumTouchTest(string & FuturElement);

bool BonusTouchTest(string & FuturElement);

/**
 * @brief résumé à faire (voir correc prof pour exemple)
 * @param[in, out] map   petit résumé à faire
 * @param[in, out] AddtoPos   petit résumé à faire
 * @param[in, out] pos   petit résumé à faire
 * @return (voir exemple)
 */

bool GoingToJump(StringMatrix & map,vector<int> & AddtoPos,vector<int> & pos);

/**
 * @brief résumé à faire (voir correc prof pour exemple)
 * @param[in, out] AddPos   petit résumé à faire
 * @param[in, out] pos   petit résumé à faire
 * @param[in, out] map   petit résumé à faire
 */

string Jump(vector<int> & pos,vector<int> Addpos, StringMatrix & map);

IntMatrix MoveList (StringMatrix & map,vector<int> pos,vector<int> oldmove );

vector<int> NextPhantomMove (StringMatrix & map,vector<int> pos,vector<int> oldmove);


vector<int> InputToChar();

string MoveCharacter (vector<int> & pos,StringMatrix & map,vector<int> Addtopos,string character,string stringsiton);

string MovePacman (vector<int> & pos,StringMatrix & map);

#endif // DEPLACEMENT_H
