#include <iostream>
#include <iomanip>
#include "gridmanagement.h"

#include "type.h" //nos types
#include "params.h" //nos parametres

using namespace std;



void ClearScreen()
{
    cout << "\033[H\033[2J";
}// ClearScreen ()

void Color (const string & Col)
{
    cout << "\033[" << Col.c_str () <<"m";
} // Color ()


void DisplayGrid (const CMat & Mat, const CMyParam & Param)
{
    ClearScreen ();
    Color (KColor.find("KReset")->second);
    const unsigned KNbLine = Mat.size ();
    const unsigned KNbCol  = Mat[0].size ();
    cout << string (KNbCol + 2 , '-') << endl;
    for (unsigned i (0); i < KNbLine; ++i)
    {
        cout << '|';
        for (unsigned j (0); j < Mat[i].size(); ++j)
        {
            if (Param.MapParamChar.find("TokenP1")->second ==  Mat[i][j])
                Color (Param.MapParamString.find("ColorP1")->second );
            else if (Param.MapParamChar.find("TokenP2")->second == Mat[i][j])
                Color (Param.MapParamString.find("ColorP2")->second );
            else
               Color (KColor.find("KReset")->second);
            cout << Mat[i][j];
            Color (KColor.find("KReset")->second);

        }
        cout << '|' << endl;
    }
    cout << string (KNbCol + 2 , '-') << endl;

}// DisplayGrid ()


void InitGrid (CMat & Mat, const CMyParam & Params, CPosition & PosPlayer1, CPosition & PosPlayer2)
{
    Mat.resize (Params.MapParamUnsigned.find("NbColumn")->second);
    const CVLine KLine (Params.MapParamUnsigned.find("NbRow")->second, KEmpty);
    for (CVLine &ALine : Mat)
        ALine = KLine;

    PosPlayer1.first = 0;
    PosPlayer1.second = Params.MapParamUnsigned.find("NbColumn")->second - 1;
    Mat [PosPlayer1.first][PosPlayer1.second] = Params.MapParamChar.find("TokenP1")->second;
    PosPlayer2.first = Params.MapParamUnsigned.find("NbRow")->second - 1;
    PosPlayer2.second =0;
    Mat [PosPlayer2.first][PosPlayer2.second]   = Params.MapParamChar.find("TokenP2")->second;
} // InitGrid ()
