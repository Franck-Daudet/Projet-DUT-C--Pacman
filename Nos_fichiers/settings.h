#ifndef SETTINGS_H
#define SETTINGS_H

/*!
 * \file settings.h
 * \brief Settings and that it
 * \author Nicolas Jaubert
 * \version 1.0
 * \date 21/01/21
 */
#include <iostream>
#include <vector>
#include <fstream>
#include <unistd.h>
#include <map>

using namespace std;

void ClearScreen3()
{
    cout << "\033[H\033[2J";
}


/**
 * @brief settings : Settings that allow the player to change the controls keys
 */

void settings()
{
    //(Inspiré par le Tutorat du 19/01/21)
    bool VAR = true;
    while(VAR)
    {
        ClearScreen3();
        cout << "\t\t\t\t    Settings" <<endl << endl << endl
             << "To change the movement keys, " << endl
             << "first enter for which movement (ex : Down) and then press Enter, " << endl
             << "next press the key you want to put (ex : q) and finally press Enter to validate." <<endl
             << "Press 4 and then Enter to leave the settings "<< endl << endl;
        ifstream IFlow("../Projet-DUT-C--Pacman/Nos_fichiers/config.yaml");
        string line;
        string delimiter = " : ";

        map<string, string> mapParams = {};

        while(getline(IFlow, line)) {
            int pos = line.find(delimiter);
            mapParams[line.substr(0, pos)] = line.substr(pos+delimiter.size(), line.size()-1);
        }


        for (map<string, string>::iterator iter = mapParams.begin(); iter != mapParams.end(); ++iter) {
            cout <<iter->first << " = " << iter->second << endl;
        }
        cout << "Write the mouvement you want to change :" << endl;
        string choice;
        bool var = true;
        while(var)
        {
            getline(cin, choice);
            if (choice =="4")
            {
                var=false;
                break;
            }
            else if (choice !="Down" && choice !="Left" && choice !="Right" && choice != "Up")
            {
                cout << "Wrong Input" << endl;
            }
            else
                var=false;
        }
        if (choice =="4")
        {
            VAR=false;
            break;
        }
        cout << "Enter the key you want to use :" << endl;
        char Key;
        cin >> Key;
        IFlow.get(Key);

        mapParams[choice] = Key;

        ofstream OFlow("../Projet-DUT-C--Pacman/Nos_fichiers/config.yaml");
        for (map<string, string>::iterator iter = mapParams.begin(); iter != mapParams.end(); ++iter) {
            OFlow << iter->first << " : " << iter->second << endl;
        }
        cout << "done" << endl;
        sleep(1);
        IFlow.close();
        OFlow.close();
    }
}
#endif // SETTINGS_H
