#ifndef GAME_H
#define GAME_H

/*!
 * \file game.h
 * \brief Main file of the project
 * \author Franck Daudet
 * \author Nicolas Jaubert
 * \author Valere Coroller
 * \version 1.6
 * \date 07/01/21
 */

#include <vector>
#include <string>
#include <iostream>
using namespace std;

#include "Start-End_Screen.h"
#include "deplacement.h"
#include "affichage.h"
#include "settings.h"
#include "triclassement.h"
#include "alias.h"
// Different map





/**
 * @brief count the numbers of PacGum on the map at each refresh
 * @return (voir exemple)
 */

unsigned CountNbPacGum();



/**
 * @brief count the numbers of Cherry(bonus) on the map at each refresh
 * @return (voir exemple)
 */

unsigned CountNbCherry();



/**
 * @brief do at each movements a calculing operation that permit to get the player's score
 * @return (voir exemple)
 */

unsigned Calculscore();

/**
 * @brief display the player's score
 */

void AffichScore();

// start the game and show map/enemies/character

/*!
 * \brief résumé à faire (voir correc prof pour exemple)
 * \fn (voir exemple)
 */

void Launch_Game();

/*! 
 * \brief main function of the project 
 * \fn void PacMan() 
 */ 

void PacMan();

#endif // GAME_H 
