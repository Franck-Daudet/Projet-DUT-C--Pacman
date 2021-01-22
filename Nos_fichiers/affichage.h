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
using namespace std;

const string KReset   ("0");
const string KBlack    ("30");
const string KRed   ("31");
const string KGreen    ("32");
const string KYellow   ("33");
const string KBlue    ("34");
const string KMAgenta ("35");
const string KCyan    ("36");
const string KLightGrey ("37");
const string KBCyan   ("46");
const string KBLightGrey ("47");
const string KBYellow  ("43");
const string KBBlue    ("44");
const string Pacman  ("\u15E7");

/*!
 * \brief résumé à faire (voir correc prof pour exemple)
 * \param[in, out] Map   petit résumé à faire
 * \fn (voir exemple)
 */

void ClearScreen ();

/**
 * @brief résumé à faire (voir correc prof pour exemple)
 * @param[in] coul   petit résumé à faire
 * @fn (voir exemple)
 */

void Color (const string & coul);

/*!
 * \brief résumé à faire (voir correc prof pour exemple)
 * \param[in, out] Map   petit résumé à faire
 * \fn (voir exemple)
 */
void EntryPlayerscore(unsigned score);

void Displayscore();


void ShowMap(StringMatrix & map, unsigned & SuperPacGum);


#endif // AFFICHAGE_H
