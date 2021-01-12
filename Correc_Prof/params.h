#ifndef PARAMS_H
#define PARAMS_H

/**
 * \file params.h
 * \brief Paramters' definition and associated functions
 * \author Alain Casali
 * \author Marc Laporte
 * \version 1.0
 * \date 18 décembre 2018
 */

#include "type.h"



/**
 * @brief Initialize the set of parameters from scratch
 * @param[out] Param : List of usefull parameters
 * @fn void InitParams (CMyParam & Param);
 */
void InitParams (CMyParam & Param);

/**
 * @brief Load the set of parameters from a YAML file
 * @param[out] Param : List of usefull parameters
 * @param[in] FileName : Path to the file to load
 * @fn void LoadParams (CMyParam & Param);
 * @return 0 if everything is OK, return 2 if it can't load the file
 */
int LoadParams (CMyParam & Param, const std::string & FileName);
#endif // PARAMS_H
