#ifndef ALIAS_H
#define ALIAS_H
/*!
 * \file alias.h
 * \brief File for all the typedef
 * \version 1.0
 * \date 21/01/21
 */
#include <vector>
#include <string>
/**
 * @brief StringVector Define the StringVector
 */
typedef std::vector<std::string> StringVector;
/**
 * @brief IntVector Define the IntVector
 */
typedef std::vector<int> IntVector ;
/**
 * @brief StringMatrix Define the StringMatrix
 */
typedef std::vector<StringVector> StringMatrix;
/**
 * @brief IntMatrix Define the IntMatrix
 */
typedef std::vector<IntVector> IntMatrix ;
#endif //ALIAS_H
