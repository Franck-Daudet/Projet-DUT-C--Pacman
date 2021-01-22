#ifndef AFFICHAGE_H
#define AFFICHAGE_H

/*!
 * \file affichage.h
 * \brief All the const and the display of the characters + display of themap
 * \author Franck Daudet
 * \author Nicolas Jaubert
 * \author Valere Coroller
 * \author Justin De Sio
 * \version 1.3
 * \date 07/01/21
 */


#include "alias.h"
#include <string>
#include <map>
using namespace std;
/**
 * @brief KReset
 */
const string KReset   ("0");
/**
 * @brief KBlack
 */
const string KBlack    ("30");
/**
 * @brief KRed
 */
const string KRed   ("31");
/**
 * @brief KGreen
 */
const string KGreen    ("32");
/**
 * @brief KYellow
 */
const string KYellow   ("33");
/**
 * @brief KBlue
 */
const string KBlue    ("34");
/**
 * @brief KMagenta
 */
const string KMagenta ("35");
/**
 * @brief KCyan
 */
const string KCyan    ("36");
/**
 * @brief KLightGrey
 */
const string KLightGrey ("37");
/**
 * @brief KBCyan
 */
const string KBCyan   ("46");
/**
 * @brief KBLightGrey
 */
const string KBLightGrey ("47");
/**
 * @brief KBYellow
 */
const string KBYellow  ("43");
/**
 * @brief KBBlue
 */
const string KBBlue    ("44");
/**
 * @brief Pacman
 */
const string Pacman  ("\u15E7");

/**
 * @brief ClearScreen
 */

void ClearScreen ();

/**
 * @brief Color
 * @param coul
 */

void Color (const string & coul);

/**
 * @brief EntryPlayerscore
 * @param score
 */
void EntryPlayerscore(unsigned score);

/**
 * @brief ShowMap
 * @param map
 * @param SuperPacGum
 */

void ShowMap(StringMatrix & map, unsigned & SuperPacGum);


#endif // AFFICHAGE_H
