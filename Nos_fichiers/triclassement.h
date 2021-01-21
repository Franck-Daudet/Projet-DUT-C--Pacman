#ifndef TRICLASSEMENT_H
#define TRICLASSEMENT_H

/*!
 * \file triclassement.h
 * \brief sorting player's score in a ranking
 * \author Franck Daudet
 * \author Nicolas Jaubert
 * \author Valere Coroller
 * \author Justin De Sio
 * \author Enzo Vargas
 * \version 1.3
 * \date 07/01/21
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>

using namespace std;

int get_rank(std::string input) {
    std::stringstream ss(input);
    std::string s;
    for(; ss >> s; );
    return std::atoi(s.c_str());
}

void SortDisplay()
{
    std::ifstream infile("../Projet-DUT-C--Pacman/Nos_fichiers/TxtDirectory/PlayersScores.txt");
    unsigned nbligne(0);
    std::vector<std::string> v;
    std::string line;
    std::getline(infile, line);
    for( ; getline( infile, line ); )
      {
        nbligne = nbligne + 1;
        v.push_back(line);
      }
    std::sort(v.begin(), v.end(), [](std::string s1, std::string s2) -> bool { return get_rank(s1) > get_rank(s2); });
    for(unsigned i = 0;i < nbligne;i++)
        cout << v[i].substr(v[i].find(",") + 1) << endl;
}

#endif // TRICLASSEMENT_H
