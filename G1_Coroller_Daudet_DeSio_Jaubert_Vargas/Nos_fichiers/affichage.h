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
 * @brief KReset Reset the color
 */
const string KReset   ("0");
/**
 * @brief KBlack Color the characters in black
 */
const string KBlack    ("30");
/**
 * @brief KRed Color the characters in red
 */
const string KRed   ("31");
/**
 * @brief KGreen Color the characters in green
 */
const string KGreen    ("32");
/**
 * @brief KYellow Color the characters in yellow
 */
const string KYellow   ("33");
/**
 * @brief KBlue Color the characters in blue
 */
const string KBlue    ("34");
/**
 * @brief KMagenta Color the characters in magenta
 */
const string KMagenta ("35");
/**
 * @brief KCyan Color the characters in cyan
 */
const string KCyan    ("36");
/**
 * @brief KLightGrey Color the characters in light grey
 */
const string KLightGrey ("37");
/**
 * @brief KBCyan Color the background in cyan
 */
const string KBCyan   ("46");
/**
 * @brief KBLightGrey  Color the background in  light grey
 */
const string KBLightGrey ("47");
/**
 * @brief KBYellow  Color the background in yellow
 */
const string KBYellow  ("43");
/**
 * @brief KBBlue  Color the background in blue
 */
const string KBBlue    ("44");
/**
 * @brief Pacman The character of Pacman
 */
const string Pacman  ("\u15E7");

/**
 * @brief ClearScreen Clear the Screen
 */

void ClearScreen ();

/**
 * @brief Color With the param, apply the color
 * @param coul
 */

void Color (const string & coul);

/**
 * @brief EntryPlayerscore Allow the player to enter his username
 * @param score
 */
void EntryPlayerscore(unsigned score);

/**
 * @brief ShowMap Show the game in itself
 * @param map
 * @param SuperPacGum
 */

void ShowMap(StringMatrix & map, unsigned & SuperPacGum);


#endif // AFFICHAGE_H
