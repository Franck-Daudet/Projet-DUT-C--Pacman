#ifndef STARTEND_SCREEN_H
#define STARTEND_SCREEN_H

/*!
 * \file Start-End_Screen.h
 * \brief Show Home Screen and Game Over + Credit
 * \author Nicolas Jaubert
 * \version 1.8
 * \date 08/01/21
 */

#include <string>

using namespace std;



/**
 * @brief Load the file .txt and modify to incorporate colors
 * @param[in] Link   The Link of the file
 * @param[in] TheColor   The colot to incorporate
 */

void LoadScreen(const string& Link, const string& TheColor);


/**
 * @brief With getch, the function take the input of the player
 * @return 1, 2, 3, 4 depending on user input
 */

unsigned Choices (unsigned& y);

/*!
 * \brief Load the Start Screen and allow a choice
 * \return 1, 2, 3, 4 depending on the choice of the player
 */

unsigned Start_Screen(); /*Animation of the Start menu + options choices*/


/*!
 * \brief Load the Game Over Screen and allow a choice
 * \return 1, 2, 3, 4 depending on the choice of the player
 */

unsigned End_Screen(); /*Animation of the game over + options choices*/

void Credit(); /*Credit screen*/

#endif // STARTEND_SCREEN_H
