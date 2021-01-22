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
StringMatrix kmap{
	{"╔","═","═",".",".","═","═",".","═",".","═","═",".","═","╗"},
	{".","ᗧ",".",".",".",".",".","●",".",".",".",".",".",".","."},
	{".",".","╔","═",".","═","╗",".","╔","═",".","═","╗",".","."},
    {".",".",".",".",".",".","║",".","║",".",".",".","║","¤","."},
	{".",".","║","●","║",".","║",".","║",".","║",".","║",".","║"},
	{".",".","║",".","║",".","║",".","║",".","║",".","║",".","."},
	{".",".","║",".",".",".","║",".","║",".",".",".","║",".","."},
	{".","●","╚",".",".","═","╝",".","╚","═",".","═","╝",".","║"},
    {".",".",".",".",".",".",".","¤",".",".","●",".",".",".","."},
	{"║",".","╔","═",".","═","╗",".","╔","═",".","═","╗",".","║"},
    {"║","¤","║",".",".",".","║",".","║",".",".",".","║",".","║"},
	{"║",".","║",".","║",".","║",".","║",".","║",".","║",".","║"},
	{"║",".","║",".","║",".","║",".","║",".","║",".","║",".","."},
	{"║",".","║",".",".",".","║",".","║",".",".",".","║",".","║"},
	{"║",".","╚","═",".","═","╝","●","╚","═",".","═","╝",".","."},
	{"║",".",".",".",".",".",".",".",".",".",".",".",".",".","."},
	{"╚","═",".","═",".","═","═",".",".","═",".",".",".","═","╝"}};



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

    vector<int> pos {1,1};
	vector<int> posf1 {1,2};
    vector<int> posinitf1 {1,2};
    vector<int> oldposf1 {0,0};
	vector<int> posf2 {3,7};
    vector<int> posinitf2 {3,7};
    vector<int> oldposf2 {0,0};
    vector<int> posf3 {2,4};
    vector<int> posinitf3 {2,4};    
    vector<int> oldposf3 {0,0};

    string ElementOnF1 (" ");
    string ElementOnF2 (" ");
    string ElementOnF3 (" ");
	ShowMap(kmap);
    string EatByPacman = " ";
    bool NotDead = true;
    unsigned SuperPacGum = 0 ;
    

	while (NotDead){
        AffichScore();
		EatByPacman = MovePacman(pos,kmap);
        oldposf1 = NextPhantomMove(kmap,posf1,oldposf1);
        oldposf2 = NextPhantomMove(kmap,posf2,oldposf2);
        oldposf3 = NextPhantomMove(kmap,posf3,oldposf3);

		
        ElementOnF1 = MoveCharacter(posf1,kmap,oldposf1,"@",ElementOnF1);
        ElementOnF2 = MoveCharacter(posf2,kmap,oldposf2,"$",ElementOnF2);
        ElementOnF3 = MoveCharacter(posf3,kmap,oldposf3,"£",ElementOnF3);

        if (ElementOnF1 == "$"){
            ElementOnF1 = ElementOnF2;
        }
        else if (ElementOnF1 == "£"){
            ElementOnF1 = ElementOnF3;
        }
        if (ElementOnF2 == "@"){
            ElementOnF2 = ElementOnF1;
        }
        else if (ElementOnF2 == "£"){
            ElementOnF2 = ElementOnF3;
        }
        if (ElementOnF3 == "@"){
            ElementOnF3 = ElementOnF1;
        }
        else if (ElementOnF3 == "$"){
            ElementOnF3 = ElementOnF2;
        }

        if(SuperPacGum > 0 || EatByPacman == "●"){
            if(EatByPacman == "●"){
                SuperPacGum = 15;
            }
            if (ElementOnF1 == "ᗧ" || EatByPacman == "@"){
                kmap[posf1[0]][posf1[1]] = ElementOnF1;
                kmap[pos[0]][pos[1]] = "ᗧ";
                posf1 = posinitf1;
                oldposf1 = {0,0};
                ElementOnF1 = " ";
            }
            if (ElementOnF2 == "ᗧ"|| EatByPacman == "$"){
                kmap[posf2[0]][posf2[1]] = ElementOnF2;
                kmap[pos[0]][pos[1]] = "ᗧ";
                posf2 = posinitf2;
                oldposf2 = {0,0};
                ElementOnF1 = " ";
            }
            if (ElementOnF3 == "ᗧ"|| EatByPacman == "£"){
                kmap[posf3[0]][posf3[1]] = ElementOnF3;
                kmap[pos[0]][pos[1]] = "ᗧ";
                posf3 = posinitf3;
                oldposf3 = {0,0};
                ElementOnF1 = " ";
            }
            --SuperPacGum;
            ShowMap(kmap);
        }
        else{
            ShowMap(kmap);
		    if (ElementOnF1 == "ᗧ" || EatByPacman == "@"|| ElementOnF2 == "ᗧ" || EatByPacman == "$"|| ElementOnF3 == "ᗧ"|| EatByPacman == "£") NotDead = false;
        }
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
            EntryPlayerscore(Calculscore());
            Displayscore();
            while(true) 
            { 
                unsigned v = End_Screen(); 
                if (v==1) 
                { 
                    Launch_Game();
                    EntryPlayerscore(Calculscore());
                    Displayscore();
                    continue; 
                } 
                else if (v==2) 
                { 
                    SortDisplay();
                    continue; 
                } 
                else if (v==3) 
                { 
                    settings();
                    continue; 
                } 
                else if (v==4) 
                    exit(0);
                else if (v==5)
                {
                    Credit();
                    continue;
                }

            } 
        } 
        else if (u==2) 
        {
            SortDisplay();
            continue; 
        } 
        else if (u==3) 
        { 
            settings();
            continue; 
        } 
        else if (u==4) 
            exit(0); 
        else if (u==5)
        {
            Credit();
            continue;
        }

    } 
} 
#endif // GAME_H 
