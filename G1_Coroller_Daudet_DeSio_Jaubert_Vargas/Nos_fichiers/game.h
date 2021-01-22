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





/**
 * @brief Calc Do at each movements a calculing operation that permit to get the player's score
 * @return A COMPLETER /!\
 */

unsigned Calc();


// start the game and show map/enemies/character

/**
 * @brief Launch_Game Launch the game in itself
 */

void Launch_Game();

/*! 
 * \brief PacMan The main function of the project
 * \fn void PacMan() 
 */ 

void PacMan();
#endif // GAME_H 
