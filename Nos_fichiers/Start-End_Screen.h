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

using namespace std;

int Start_Screen()
{

    ifstream Flow("../Projet-DUT-C--Pacman/Nos_fichiers/TxtDirectory/StartSheet.txt");
    string line;
    while(getline(Flow, line))
    {
        cout << line << endl;
    }
    int Choice;
    while(true)
    {
        cin >> Choice;
        if (Choice == 1)
        {
             return 1;
        }
        else if (Choice == 2)
        {
             return 2;
        }
        else if (Choice == 3)
        {
            return 3;
        }
        else if (Choice == 4)
        {
            return 4;
        }

        else
        {
            cout <<"Wrong input (you are supposed to write 1 or 2 or 3)" << endl;

        }
    }

}

int End_Screen()
{

    ifstream Flow("../Projet-DUT-C--Pacman/Nos_fichiers/TxtDirectory/EndSheet.txt");
    string line;
    while(getline(Flow, line))
    {
        cout << line << endl;
    }
    int Choice;
    while(true)
    {
        cin >> Choice;
        if (Choice == 1)
        {
             return 1;
        }
        else if (Choice == 2)
        {
             return 2;
        }
        else if (Choice == 3)
        {
            return 3;
        }
        else if (Choice == 4)
        {
            return 4;
        }
        else
        {
            cout <<"Wrong input (you are supposed to write 1 or 2 or 3)" << endl;

        }
    }

}

