#include <iostream>

#include "game.h"
#include "params.h"
#include "gridmanagement.h"

#include <map>
using namespace std;
template <class T, class U>
void ShowMap (const map<T,U> & AMap){
    for (const pair <T,U> & Val : AMap)                cout << "Cle : " << Val.first << "   "             << "Valeur : " << Val.second << endl;
    cout << endl;
}// ShowMap ()

void MoveToken (CMat & Mat, const char & Move, CPosition & Pos)
{
    char car = Mat [Pos.first][Pos.second];
    Mat [Pos.first][Pos.second] = KEmpty;
    switch (Move)
    {
    case 'A':
        -- Pos.first;
        -- Pos.second;
        break;
    case 'Z':
        --Pos.first;
        break;
    case 'E':
        --Pos.first;
        ++Pos.second;
        break;
    case 'Q':
        --Pos.second;
        break;
    case 'D':
        ++Pos.second;
        break;
    case 'W':
        ++Pos.first;
        --Pos.second;
        break;
    case 'X':
        ++Pos.first;
        break;
    case 'C':
        ++Pos.first;
        ++Pos.second;
        break;
    }
    Mat [Pos.first][Pos.second] = car;
} //MoveToken ()


int ppal (void)
{

    const unsigned KSize (10);
    unsigned PartyNum (1);
    const unsigned KMaxPartyNum (KSize * KSize);
    CMat Mat;

    bool Player1Turn (true);
    bool Victory (false);

    CPosition PosPlayer1, PosPlayer2;

    CMyParam Param;
    int RetVal = LoadParams(Param, "../PacMan/Nos_fichiers/config.yaml");
    if (RetVal != 0)
    {
        return RetVal;
    }


    InitGrid(Mat, Param, PosPlayer1, PosPlayer2);

    DisplayGrid (Mat, Param);

    while (PartyNum <= KMaxPartyNum && ! Victory)
    {

        cout << "tour numero : " << PartyNum << ", Joueur"
             << (Player1Turn ? '1' : '2') << ", entrez un déplacement : ";

        char Move;
        cin >> Move;

        Move = toupper (Move);
        MoveToken (Mat, Move, (Player1Turn ? PosPlayer1: PosPlayer2));
        ClearScreen();
        DisplayGrid (Mat, Param);

        //Victiry test
        if (PosPlayer1 == PosPlayer2) Victory = true;

        //Increase party's number
        ++PartyNum;

        //Player changing
        Player1Turn = !Player1Turn;
    }//while (no victory)

    if (!Victory)
    {
        Color (KColor.find("KMAgenta")->second);
        cout << "Aucun vainqueur" << endl;
        return 1;
    }

    Color (KColor.find("KGreen")->second);
    cout << "Félicitations Joueur" << (Player1Turn ? '2' : '1')
         << " vous avez gagné :)" << endl;
    Color (KColor.find("KReset")->second);
    return 0;
} //ppal ()
