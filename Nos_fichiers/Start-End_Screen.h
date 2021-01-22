#ifndef STARTEND_SCREEN_H
#define STARTEND_SCREEN_H

/*!
 * \file Start-End_Screen.h
 * \brief Show Home Screen and Game Over + Credit
 * \author Nicolas Jaubert
 * \version 1.8
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

//Faut fixer quand y aura les .cpp
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

//A mettre dans le getch.h
// https://stackoverflow.com/questions/29335758/using-kbhit-and-getch-on-linux
#include <sys/ioctl.h>
/**
 * @brief kbhit
 * @return
 */
bool kbhit()
{
    termios term;
    tcgetattr(0, &term);

    termios term2 = term;
    term2.c_lflag &= ~ICANON;
    tcsetattr(0, TCSANOW, &term2);

    int byteswaiting;
    ioctl(0, FIONREAD, &byteswaiting);

    tcsetattr(0, TCSANOW, &term);

    return byteswaiting > 0;
}

/**
 * @brief Load the file .txt and modify to incorporate colors
 * @param[in] Link   The Link of the file
 * @param[in] TheColor   The colot to incorporate
 */

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

/**
 * @brief With getch, the function take the input of the player
 * @return 1, 2, 3, 4 depending on user input
 */

unsigned Choices (unsigned& y)
{
    if(kbhit())
    {
        char x;
        x=Getch();
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

/*!
 * \brief Load the Start Screen and allow a choice
 * \return 1, 2, 3, 4 depending on the choice of the player
 */

unsigned Start_Screen() /*Animation of the Start menu + options choices*/
{
    string BeginLink ="../Projet-DUT-C--Pacman/Nos_fichiers/TxtDirectory/StartSheet";
    bool var = true;
    unsigned y;
    while(var)
    {
        usleep(200000);
        LoadScreen(BeginLink+".txt", Kyellow);
        usleep(200000);
        LoadScreen(BeginLink+"2.txt", Kyellow);
        Choices(y);
        if (y == 1 || y == 2 || y == 3 || y == 4 || y == 5)
            var=false;
    }

    return y;

}

/*!
 * \brief Load the Game Over Screen and allow a choice
 * \return 1, 2, 3, 4 depending on the choice of the player
 */

unsigned End_Screen() /*Animation of the game over + options choices*/
{
    string BeginLink ="../Projet-DUT-C--Pacman/Nos_fichiers/TxtDirectory/EndSheetsDr/EndSheet";
    bool var = true;
    unsigned y;
    LoadScreen(BeginLink+".txt", Kred);
    usleep(200000);
    LoadScreen(BeginLink+"2.txt", Kred);
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
            LoadScreen(BeginLink+to_string(i)+".txt", Kred);
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
        ClearScreen2();
        ifstream Flow ("../Projet-DUT-C--Pacman/Nos_fichiers/TxtDirectory/credit.txt");
        string line;
        while(getline(Flow, line))
            cout << line << endl;
        char input=Getch();
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
#endif // STARTEND_SCREEN_H
