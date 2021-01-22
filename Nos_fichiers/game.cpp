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
#include "game.h"
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

unsigned CountNbGhost()
{
    unsigned nbghost(0);
    for (int x = 0; x < kmap.size(); x++) {
        for (int y = 0; y < kmap[x].size(); y++) {
              if(kmap[x][y] == "$" || kmap[x][y] == "£" || kmap[x][y] == "@")
                {
                  nbghost = nbghost + 1;
              }
            }
    }
    return nbghost;
}

unsigned Calculscore()
{
    unsigned PlayerScore(0);
    unsigned NbPacGumEatByPlayer(0);
    unsigned NbCherryEatByPlayer(0);
    unsigned NbGhostEatByplayer(0);
    unsigned NbSPacGumEatByPlayer(0);
    NbPacGumEatByPlayer = NbPacGumInit - CountNbPacGum();
    NbCherryEatByPlayer = NbcherryInit - CountNbCherry();
    NbGhostEatByplayer = 3 - CountNbGhost();
    PlayerScore = NbPacGumEatByPlayer + NbCherryEatByPlayer*10 + NbGhostEatByplayer*50;
    return PlayerScore;
}



void AffichScore()
{
    cout << "Your Score :" << Calculscore() << endl;
}

// start the game and show map/enemies/character



void Launch_Game()
{

    vector<int> pos {1,1};
    vector<int> posf1 {1,2};
    vector<int> oldposf1 {0,0};
    vector<int> posf2 {3,7};
    vector<int> oldposf2 {0,0};
    vector<int> posf3 {2,4};
    vector<int> oldposf3 {0,0};

    string ElementOnF1 (" ");
    string ElementOnF2 (" ");
    string ElementOnF3 (" ");
    ShowMap(kmap, 0);
    string EatByPacman = " ";
    bool Pasmort = true;

    while (Pasmort){
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


        ShowMap(kmap, 0);
        if (pos == posf1 || pos == posf2 || pos == posf3) Pasmort = false;
    }
}



void PacMan()
{
    while(true)
    {
        unsigned u = Start_Screen();
        if (u==1)
        {
            Launch_Game();
            EntryPlayerscore(Calculscore());
            while(true)
            {
                unsigned v = End_Screen();
                if (v==1)
                {
                    Launch_Game();
                    EntryPlayerscore(Calculscore());
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
