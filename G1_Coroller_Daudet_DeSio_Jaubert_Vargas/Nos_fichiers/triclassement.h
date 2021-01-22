#ifndef TRICLASSEMENT_H
#define TRICLASSEMENT_H

/*!
 * \file triclassement.h
 * \brief sorting player's score in a ranking
 * \author Nicolas Jaubert
 * \author Enzo Vargas
 * \version 1.3
 * \date 07/01/21
 */

#include <string>


using namespace std;
/**
 * @brief get_rank Gets the position of the ranks
 * @param input
 * @return
 */
int get_rank(std::string input);

/**
 * @brief SortDisplay Sort the player's score
 */

void SortDisplay();

#endif // TRICLASSEMENT_H
