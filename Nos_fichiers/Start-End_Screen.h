#ifndef STARTEND_SCREEN_H
#define STARTEND_SCREEN_H

#endif // STARTEND_SCREEN_H

/**
 * \file Start-End_Screen.h
 * \brief Show Home Screen and Game Over
 * \author Nicolas Jaubert
 * \version 1.0
 * \date 08/01/21
 */

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<unistd.h>
#include <stdlib.h>

#include <termios.h>
#include <unistd.h>
#include <stdio.h>

using namespace std;
//Faut fixer ça par contre mais je sais pas vraiment comment faire
//---------------------------------------------------------------------------------------

const string Kreset   ("0");
const string Kyellow   ("33");
const string Kred   ("31");
const string Kwhite ("37");
const string KBwhite ("47");

int Getch(void)
{
  struct termios oldattr, newattr;
  int ch;
  tcgetattr( STDIN_FILENO, &oldattr );
  newattr = oldattr;
  newattr.c_lflag &= ~( ICANON | ECHO );
  tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
  ch = getchar();
  tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
  return ch;
}
void Color2 (const string & coul)
{
    cout << "\033[" << coul <<"m";
}

void ClearScreen2() /*Clear the screen*/
{
    cout << "\033[H\033[2J";
}

//---------------------------------------------------------------------------------------

void LoadScreen(const string& Link, const string& TheColor)
{
    ClearScreen2();
    ifstream Flow(Link);
    char Ch;
    while(Flow.get(Ch)) //Print the screen
    {
        if (Ch=='@') //For the color of Pacman and the fantom
            Color2(TheColor);
        else if ( Ch=='O') // For the color of the fantom eyes
        {
            Color2(Kwhite);
            Color2(KBwhite);
        }
        cout << Ch;
        Color2(Kreset);
    }
    Flow.close();
}

unsigned FourChoices ()
{
    unsigned y;
    bool var = true;
    while(var)
    {
        char x;
        x=Getch();
        switch (x)
        {
            case '1':
                y=1;
                var = false;
                break;
            case '2':
                y=2;
                var = false;
                break;
            case '3':
                y=3;
                var = false;
                break;
            case '4':
                y=4;
                var = false;
                break;
        }
        if (x !='1' && x !='2' && x !='3' && x !='4')
            cout << "Wrong answer, you're supposed to press 1 or 2 or 3 or 4" << endl;
    }
    return y;
}

unsigned Start_Screen() /*Animation of the Start menu + select of the option*/
{
    string BeginLink ="../Projet-DUT-C--Pacman/Nos_fichiers/TxtDirectory/StartSheet";
    LoadScreen(BeginLink+".txt", Kyellow);
    usleep(200000);
    LoadScreen(BeginLink+"2.txt", Kyellow);
    usleep(200000);
    LoadScreen(BeginLink+".txt", Kyellow);
    usleep(200000);
    LoadScreen(BeginLink+"2.txt", Kyellow);
    usleep(200000);
    LoadScreen(BeginLink+".txt", Kyellow);
    usleep(200000);
    LoadScreen(BeginLink+"2.txt", Kyellow);
    usleep(200000);
    LoadScreen(BeginLink+".txt", Kyellow);
    return FourChoices();

}

unsigned End_Screen() /*different End menu option and Gost animation*/
{
    string BeginLink ="../Projet-DUT-C--Pacman/Nos_fichiers/TxtDirectory/EndSheetsDr/EndSheet";
    LoadScreen(BeginLink+".txt", Kred);
    usleep(200000);
    LoadScreen(BeginLink+"2.txt", Kred);
    usleep(200000);
    /*while(true)
    {
        for (unsigned i{3}; i <= 14; i++)
        {
            LoadScreen(BeginLink+to_string(i)+".txt", Kred);
            usleep(200000);
        }
    }*/
    return FourChoices();
}
