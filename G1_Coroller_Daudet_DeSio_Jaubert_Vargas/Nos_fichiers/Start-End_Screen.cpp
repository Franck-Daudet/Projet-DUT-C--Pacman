#include<iostream>
#include<fstream>
#include<cstdlib>
#include<unistd.h>
#include <stdlib.h>

#include <termios.h>
#include <unistd.h>
#include <stdio.h>

using namespace std;

#include "affichage.h"
#include "getch.h"
#include "Start-End_Screen.h"



void LoadScreen(const string& Link, const string& TheColor)
{
    ClearScreen();
    ifstream Flow(Link);
    char Ch;
    while(Flow.get(Ch)) //Print the screen
    {
        if (Ch=='@') //For the color of Pacman and the fantom
            Color(TheColor);
        else if ( Ch=='O') // For the color of the fantom eyes
        {
            Color(KLightGrey);
            Color(KBLightGrey);
        }
        cout << Ch;
        Color(KReset);
    }
    Flow.close();
}


unsigned Choices (unsigned& y)
{
    if(kbhit())
    {
        char x;
        x=getch();
        switch (x)
        {
            case '1':
                y=1;
                break;
            case '2':
                y=2;
                break;
            case '3':
                y=3;
                break;
            case '4':
                y=4;
                break;
            case '5':
                y=5;
                break;
            default:
                cout << "Wrong answer, you're supposed to press 1 or 2 or 3 or 4 or 5" << endl;
                usleep(800000);
        }
     }
    return y;
}


unsigned Start_Screen() /*Animation of the Start menu + options choices*/
{
    string BeginLink ="../G1_Coroller_Daudet_DeSio_Jaubert_Vargas/Nos_fichiers/TxtDirectory/StartSheet";
    bool var = true;
    unsigned y;
    while(var)
    {
        usleep(200000);
        LoadScreen(BeginLink+".txt", KYellow);
        usleep(200000);
        LoadScreen(BeginLink+"2.txt", KYellow);
        Choices(y);
        if (y == 1 || y == 2 || y == 3 || y == 4 || y == 5)
            var=false;
    }

    return y;

}


unsigned End_Screen() /*Animation of the game over + options choices*/
{
    string BeginLink ="../G1_Coroller_Daudet_DeSio_Jaubert_Vargas/Nos_fichiers/TxtDirectory/EndSheetsDr/EndSheet";
    bool var = true;
    unsigned y;
    LoadScreen(BeginLink+".txt", KRed);
    usleep(200000);
    LoadScreen(BeginLink+"2.txt", KRed);
    usleep(200000);
    while(var)
    {
        Choices(y);
        if (y == 1 || y == 2 || y == 3 || y == 4 || y == 5)
            var=false;
        for (unsigned i{3}; i <= 14; i++)
        {
            if (y == 1 || y == 2 || y == 3 || y == 4 || y == 5) //If a choice has been made, stop the animation
            {
                i=15;
                continue;
            }
            LoadScreen(BeginLink+to_string(i)+".txt", KRed);
            usleep(200000);
        }
    }
    return y;
}
void Credit()
{

    bool Var = true;
    while(Var)
    {
        ClearScreen();
        ifstream Flow ("../G1_Coroller_Daudet_DeSio_Jaubert_Vargas/Nos_fichiers/TxtDirectory/credit.txt");
        string line;
        while(getline(Flow, line))
            cout << line << endl;
        char input=getch();
        switch (input)
        {
            case '4':
                Var=false;
                break;
            default:
                cout << "Wrong input, you're supposed to press 4" << endl;
                usleep(800000);
        }
        Flow.close();
    }

}
