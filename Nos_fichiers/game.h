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

// Different map
vector<vector<string>> kmap{
	{"╔","═","═","═","═","═","═",".","═","═","═","═","═","═","╗"},
	{"║","ᗧ",".",".",".",".",".",".",".",".",".",".",".",".","║"},
	{"║",".","╔","═",".","═","╗",".","╔","═",".","═","╗",".","║"},
	{"║",".","║",".",".",".","║",".","║",".",".",".","║",".","║"},
	{"║",".","║",".","║",".","║",".","║",".","║",".","║",".","║"},
	{"║",".","║",".","║",".","║",".","║",".","║",".","║",".","║"},
	{"║",".","║",".",".",".","║",".","║",".",".",".","║",".","║"},
	{"║",".","╚","═",".","═","╝",".","╚","═",".","═","╝",".","║"},
	{".",".",".",".",".",".",".",".",".",".",".",".",".",".","."},
	{"║",".","╔","═",".","═","╗",".","╔","═",".","═","╗",".","║"},
	{"║",".","║",".",".",".","║",".","║",".",".",".","║",".","║"},
	{"║",".","║",".","║",".","║",".","║",".","║",".","║",".","║"},
	{"║",".","║",".","║",".","║",".","║",".","║",".","║",".","║"},
	{"║",".","║",".",".",".","║",".","║",".",".",".","║",".","║"},
	{"║",".","╚","═",".","═","╝",".","╚","═",".","═","╝",".","║"},
	{"║",".",".",".",".",".",".",".",".",".",".",".",".",".","║"},
	{"╚","═","═","═","═","═","═",".","═","═","═","═","═","═","╝"}};


// start the game and show map/enemies/character

/*!
 * \brief résumé à faire (voir correc prof pour exemple)
 * \fn (voir exemple)
 */

unsigned CountNbPacGum()
{
    unsigned nbpacgum(0);
    for (int x = 0; x < kmap.size(); x++) {
        for (int y = 0; y < kmap[x].size(); y++) {
              if(kmap[x][y] == ".")
                {
                  nbpacgum = nbpacgum + 1;
              }
            }
    }
    return nbpacgum;
}

void AffichNbPacGum()
{
    cout << "nb PacGum réstant :" << CountNbPacGum() << endl;
}

void Launch_Game(){
    vector<int> pos {1,1};
	while (true)
	{
        AffichNbPacGum();
		ShowMap(kmap);
		MoveCharacter(pos,kmap);
	}
}

/*!
 * \brief main function of the project
 * \fn void PacMan()
 */

void PacMan()
{
    while(true)
    {
        unsigned u = Start_Screen();
        if (u==1)
        {
            Launch_Game();
            while(true)
            {
                unsigned v = End_Screen();
                if (v==1)
                {
                    Launch_Game();
                    continue;
                }
                else if (v==2)
                {
                    cout<<"W.I.P"<<endl;
                    sleep(1);
                    continue;
                }
                else if (v==3)
                {
                    cout<<"W.I.P"<<endl;
                    sleep(1);
                    continue;
                }
                else if (v==4)
                    exit(0);
            }
        }
        else if (u==2)
        {
            cout<<"W.I.P"<<endl;
            sleep(1);
            continue;
        }
        else if (u==3)
        {
            cout<<"W.I.P"<<endl;
            sleep(1);
            continue;
        }
        else if (u==4)
            exit(0);
    }
}
#endif // GAME_H
