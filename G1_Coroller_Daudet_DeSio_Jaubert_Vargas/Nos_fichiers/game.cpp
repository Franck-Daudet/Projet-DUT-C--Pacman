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

StringMatrix kmap3{
{"╔","═","═","═","═","═","═",".","═","═","═","═","═","═","╗"},
{"║","¤",".",".",".",".",".","ᗧ",".",".",".",".",".","¤","║"},
{"║",".","╔","═",".","═","╗",".","╔","═",".","═","╗",".","║"},
{"║",".","║",".",".",".","║",".","║",".",".",".","║",".","║"},
{"║",".","║",".","║",".","║",".","║",".","║",".","║",".","║"},
{"║",".","║",".","║",".","║",".","║",".","║",".","║",".","║"},
{"║",".","║",".",".",".","║",".","║",".",".",".","║",".","║"},
{"║",".","╚","═","$","═","╝",".","╚","═","£","═","╝",".","║"},
{".",".",".",".","●",".",".","¤",".",".","●",".",".",".","."},
{"║",".","╔","═",".","═","╗",".","╔","═",".","═","╗",".","║"},
{"║",".","║",".",".",".","║",".","║",".",".",".","║",".","║"},
{"║",".","║",".","║",".","║",".","║",".","║",".","║",".","║"},
{"║",".","║",".","║",".","║",".","║",".","║",".","║",".","║"},
{"║",".","║",".",".",".","║",".","║",".",".",".","║",".","║"},
{"║",".","╚","═",".","═","╝",".","╚","═",".","═","╝",".","║"},
{"║","¤",".",".",".",".",".","@",".",".",".",".",".","¤","║"},
{"╚","═","═","═","═","═","═",".","═","═","═","═","═","═","╝"}};

StringMatrix kmap2{
{"╔","═","═","═","═","═","═","═","═",".","═","═","═","═","═","═","═","═","╗"},
{"║","¤",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".","¤","║"},
{"║",".","╔","═","═","╗",".","╔","═","═","═","╗",".","╔","═","═","╗",".","║"},
{"║",".","║"," "," ","║",".","║"," "," "," ","║",".","║"," "," ","║",".","║"},
{"║",".","╚","═","═","╝","●","╚","═","═","═","╝","●","╚","═","═","╝",".","║"},
{"║",".",".",".",".",".",".",".",".","ᗧ",".",".",".",".",".",".",".",".","║"},
{"║",".","═","═","═","╗",".","╔","═","═","═","╗",".","╔","═","═","═",".","║"},
{".",".",".",".","£","║",".","║"," "," "," ","║",".","║","$",".",".",".","."},
{"║",".",".",".",".","║",".","╚","═","═","═","╝",".","║",".",".",".",".","║"},
{"║",".",".",".",".",".",".",".",".","@",".",".",".",".",".",".",".",".","║"},
{"║",".","╔","═","═","╗",".","╔","═","═","═","╗",".","╔","═","═","╗",".","║"},
{"║",".","║"," "," ","║",".","║"," "," "," ","║",".","║"," "," ","║",".","║"},
{"║",".","╚","═","═","╝","●","╚","═","═","═","╝","●","╚","═","═","╝",".","║"},
{"║","¤",".",".",".",".",".",".",".",".",".",".",".",".",".",".",".","¤","║"},
{"╚","═","═","═","═","═","═","═","═",".","═","═","═","═","═","═","═","═","╝"}};

StringMatrix kmap1{
{"╔","═","═","═","═","═","═","╦","═","═","═","═","═","═","═","╦","═","═","═","═","═","═","╗"},
{".","ᗧ",".",".",".",".",".","║",".",".",".",".",".",".",".","║",".",".",".",".",".",".","."},
{"╔",".","═","═","═","═",".","║",".","║",".","║",".","║",".","║",".","═","═","═","═",".","╗"},
{"║",".",".",".",".",".",".",".",".","║",".","¤",".","║",".",".",".",".",".",".",".",".","║"},
{"║",".","╔","═","═","═","═","═",".","╚","═","═","═","╝",".","═","═","═","═","═","╗",".","║"},
{"║",".","║",".",".",".",".",".",".",".",".","@",".",".",".",".",".",".",".",".","║",".","║"},
{"║",".","║",".","═","═","═","╗",".","╔","═","═","═","╗",".","╔","═","═","═",".","║",".","║"},
{"║",".","●",".",".",".",".","║",".","║"," "," "," ","║",".","║",".",".",".",".","●",".","║"},
{"╠","═","═","═","═","═",".","║",".","╚","═","═","═","╝",".","║",".","═","═","═","═","═","╣"},
{"║",".",".",".",".",".",".",".",".",".",".","¤",".",".",".",".",".",".",".",".",".",".","║"},
{"║",".","═","═","═","╗",".","║","$",".","╔","═","╗",".","£","║",".","╔","═","═","═",".","║"},
{"║",".",".",".",".","║",".","╚","═",".","║",".","║",".","═","╝",".","║",".",".",".",".","║"},
{"╚","═","═","╗",".",".",".",".",".",".","║",".","║",".",".",".",".",".",".","╔","═","═","╝"},
{"═","═","═","╝",".","═","═","╦","═",".","╚","═","╝",".","═","╦","═","═",".","╚","═","═","═"},
{".",".",".","¤",".",".",".","║",".",".",".","●",".",".",".","║",".",".",".","¤",".",".","."},
{"╔",".","═","═",".","║",".","║",".","═","═","╦","═","═",".","║",".","║",".","═","═",".","╗"},
{"║",".",".",".",".","║",".",".",".",".",".","║",".",".",".",".",".","║",".",".",".",".","║"},
{"║",".","═","═","═","╝",".","═","═","═",".","║",".","═","═","═",".","╚","═","═","═",".","║"},
{"║",".",".","●",".",".",".",".",".",".",".","¤",".",".",".",".",".",".",".","●",".",".","║"},
{"╚","═","═","═","═","═","═","═","═","═","═","═","═","═","═","═","═","═","═","═","═","═","╝"}}; 



unsigned score(0);

//calculates the score based on what pacman eats
void Calc (string EatByPacman)
{
  unsigned newscore(0);
  if (EatByPacman == ".")
       newscore = 1;
  else if (EatByPacman == "●")
       newscore = 20;
  else if (EatByPacman == "¤")
        newscore = 10;
  else if (EatByPacman == "$" || EatByPacman == "£" || EatByPacman == "@")
        newscore = 50;
  score = score + newscore;
}
/**void AffichScore()
{
    cout << "Your Score :" << Calculscore() << endl;
}**/

// start the game and show map/enemies/character



void Launch_Game(){
    vector<int> oldposf1 {0,0};
    vector<int> oldposf2 {0,0};
    vector<int> oldposf3 {0,0};
    vector<int> pos;
    vector<int> posf1;
    vector<int> posf2;
    vector<int> posf3;
    StringMatrix kmap;
    srand (time(NULL));
    unsigned RandomMap =  rand() % 3 + 1;
    if (RandomMap == 1){
        kmap = kmap1;
        pos = {1,1};
        posf1 = {5,11};
        posf2 = {10,8};
        posf3 = {10,14};
    }
    else if (RandomMap == 2){
        kmap = kmap2;
        pos = {5,9};
        posf1 = {9,9};
        posf2 = {7,14};
        posf3 = {7,4};
    }
    else if (RandomMap == 3){
        kmap = kmap3 ;
        pos = {1,7};
        posf1 = {15,7};
        posf2 = {7,4};
        posf3 = {7,10};
    }



    vector<int> posinitf1 = posf1;
    vector<int> posinitf2 = posf2;
    vector<int> posinitf3 = posf3;

    string ElementOnF1 (".");
    string ElementOnF2 (".");
    string ElementOnF3 (".");
    string EatByPacman = ".";
    bool NotDead = true;
    unsigned SuperPacGum = 0 ;
    ShowMap(kmap,SuperPacGum);


    while (NotDead){
        Calc(EatByPacman);
        cout << "Player's score : " << score << endl;
        EatByPacman = MovePacman(pos,kmap);
        oldposf1 = NextPhantomMove(kmap,posf1,oldposf1);
        oldposf2 = NextPhantomMove(kmap,posf2,oldposf2);
        oldposf3 = NextPhantomMove(kmap,posf3,oldposf3);

        ElementOnF1 = MoveCharacter(posf1,kmap,oldposf1,"@",ElementOnF1);
        ElementOnF2 = MoveCharacter(posf2,kmap,oldposf2,"$",ElementOnF2);
        ElementOnF3 = MoveCharacter(posf3,kmap,oldposf3,"£",ElementOnF3);

        if(SuperPacGum || EatByPacman == "●"){
            if(EatByPacman == "●"){
                SuperPacGum = 15;
            }
            if (ElementOnF1 == "ᗧ" || EatByPacman == "@"){
                kmap[posf1[0]][posf1[1]] = ElementOnF1;
                kmap[pos[0]][pos[1]] = "ᗧ";
                posf1 = posinitf1;
                oldposf1 = {0,0};
                ElementOnF1 = ".";
            }
            if (ElementOnF2 == "ᗧ"|| EatByPacman == "$"){
                kmap[posf2[0]][posf2[1]] = ElementOnF2;
                kmap[pos[0]][pos[1]] = "ᗧ";
                posf2 = posinitf2;
                oldposf2 = {0,0};
                ElementOnF1 = ".";
            }
            if (ElementOnF3 == "ᗧ"|| EatByPacman == "£"){
                kmap[posf3[0]][posf3[1]] = ElementOnF3;
                kmap[pos[0]][pos[1]] = "ᗧ";
                posf3 = posinitf3;
                oldposf3 = {0,0};
                ElementOnF1 = ".";
            }
            --SuperPacGum;
        }
        else{
            if (ElementOnF1 == "ᗧ" || EatByPacman == "@"|| ElementOnF2 == "ᗧ" || EatByPacman == "$"|| ElementOnF3 == "ᗧ"|| EatByPacman == "£") NotDead = false;
        }

        if (ElementOnF3 == "@"){
            ElementOnF3 = ElementOnF1;
        }
        if (ElementOnF3 == "$"){
            ElementOnF3 = ElementOnF2;
        }
        if (ElementOnF2 == "@"){
            ElementOnF2 = ElementOnF1;
        }
         if (ElementOnF2 == "£"){
            ElementOnF2 = ElementOnF3;
        }
        if (ElementOnF1 == "$"){
            ElementOnF1 = ElementOnF2;
        }
        if (ElementOnF1 == "£"){
            ElementOnF1 = ElementOnF3;
        }
        ShowMap(kmap,SuperPacGum);
    }
}



void PacMan()
{
    //Musique
    //system("cvlc ../G1_Coroller_Daudet_DeSio_Jaubert_Vargas/Nos_fichiers/MusicDirectory/pac-man-theme-remix-by-arsenic1987.mp3 &");
          
    while(true)
    {
        unsigned u = Start_Screen();
        if (u==1)
        {
            Launch_Game();
            EntryPlayerscore(score);
            while(true)
            {
                unsigned v = End_Screen();
                if (v==1)
                {
                    Launch_Game();
                    EntryPlayerscore(score);
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
                {
                    system("killall vlc");
                    exit(0);
                }
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
        {
            system("killall vlc");
            exit(0);

        }
        else if (u==5)
        {
            Credit();
            continue;
        }
     }
}