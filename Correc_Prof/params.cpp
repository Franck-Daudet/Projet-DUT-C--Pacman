#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "params.h"


using namespace std;


void InitParams (CMyParam & Param)
{
    //Move Keys
    Param.MapParamChar["KeyUp"]   = 'z';
    Param.MapParamChar["KeyDown"] = 's';
    Param.MapParamChar["KeyLeft"] = 'q';
    Param.MapParamChar["KeyRight"] = 'd';
    Param.MapParamChar["KeyRight"] = 'd';
    Param.MapParamChar["TokenP1"] = 'O';
    Param.MapParamChar["TokenP2"] = 'X';

    //Size of grid -- suppose to be a rectangle
    Param.MapParamUnsigned["NbColumn"] = 10;
    Param.MapParamUnsigned["NbRow"] = 15;

    //Display Colors
    Param.MapParamString["ColorP1"] = KColor.find("KRed")->second ;
    Param.MapParamString["ColorP2"] = KColor.find("KGreen")->second ;
}

int LoadParams (CMyParam & Param, const std::string & FileName)
{
    ifstream ifs (FileName);
    if (!ifs.is_open())
    {
        cerr << "pas le bon fichier de configuration";
        return 2;
    }
    string Key;
    while (ifs >> Key)
    {
        char tmp;
        ifs >> tmp;        
        if (find (KAuthorizedKey.VParamChar.begin(), KAuthorizedKey.VParamChar.end(), Key) != KAuthorizedKey.VParamChar.end())
            ifs >> Param.MapParamChar[Key];
        else if (find (KAuthorizedKey.VParamUnsigned.begin(), KAuthorizedKey.VParamUnsigned.end(), Key) != KAuthorizedKey.VParamUnsigned.end())
            ifs >> Param.MapParamUnsigned[Key];
        else if (find (KAuthorizedKey.VParamString.begin(), KAuthorizedKey.VParamString.end(), Key) != KAuthorizedKey.VParamString.end())
        {
            string Val;
            ifs >> Val;
            Param.MapParamString[Key] = KColor.find(Val)->second;
        }
    }
    return 0;
}
