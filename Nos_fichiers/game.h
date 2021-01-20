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
    {"║","ᗧ",".",".",".",".",".","¤",".",".",".",".",".",".","║"},
	{"║",".","╔","═",".","═","╗",".","╔","═",".","═","╗",".","║"},
	{"║",".","║",".",".",".","║",".","║",".",".",".","║",".","║"},
	{"║",".","║",".","║",".","║",".","║",".","║",".","║",".","║"},
    {"║",".","║",".","║",".","║",".","║",".","║",".","║","¤","║"},
	{"║",".","║",".",".",".","║",".","║",".",".",".","║",".","║"},
	{"║",".","╚","═",".","═","╝",".","╚","═",".","═","╝",".","║"},
	{".",".",".",".",".",".",".",".",".",".",".",".",".",".","."},
	{"║",".","╔","═",".","═","╗",".","╔","═",".","═","╗",".","║"},
	{"║",".","║",".",".",".","║",".","║",".",".",".","║",".","║"},
	{"║",".","║",".","║",".","║",".","║",".","║",".","║",".","║"},
    {"║",".","║",".","║",".","║","¤","║",".","║",".","║",".","║"},
	{"║",".","║",".",".",".","║",".","║",".",".",".","║",".","║"},
	{"║",".","╚","═",".","═","╝",".","╚","═",".","═","╝",".","║"},
	{"║",".",".",".",".",".",".",".",".",".",".",".",".",".","║"},
	{"╚","═","═","═","═","═","═",".","═","═","═","═","═","═","╝"}};



/**
 * @brief count the numbers of PacGum on the map at each refresh
 * @return (voir exemple)
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

unsigned NbPacGumInit(CountNbPacGum());

/**
 * @brief count the numbers of Cherry(bonus) on the map at each refresh
 * @return (voir exemple)
 */

unsigned CountNbCherry()
{
    unsigned nbcherry(0);
    for (int x = 0; x < kmap.size(); x++) {
        for (int y = 0; y < kmap[x].size(); y++) {
              if(kmap[x][y] == "¤")
                {
                  nbcherry = nbcherry + 1;
              }
            }
    }
    return nbcherry;
}

unsigned NbcherryInit(CountNbCherry());

/**
 * @brief do at each movements a calculing operation that permit to get the player's score
 * @return (voir exemple)
 */

unsigned Calculscore()
{
    unsigned PlayerScore(0);
    unsigned NbPacGumEatByPlayer(0);
    unsigned NbCherryEatByPlayer(0);
    NbPacGumEatByPlayer = NbPacGumInit - CountNbPacGum();
    NbCherryEatByPlayer = NbcherryInit - CountNbCherry();
    PlayerScore = NbPacGumEatByPlayer + NbCherryEatByPlayer*10;
    return PlayerScore;
}

/**
 * @brief display the player's score
 */

void AffichScore()
{
    cout << "Your Score :" << Calculscore() << endl;
}

// start the game and show map/enemies/character

/*!
 * \brief résumé à faire (voir correc prof pour exemple)
 * \fn (voir exemple)
 */

void Launch_Game(){

    EntryPlayerscore(Calculscore());
    Displayscore();
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
