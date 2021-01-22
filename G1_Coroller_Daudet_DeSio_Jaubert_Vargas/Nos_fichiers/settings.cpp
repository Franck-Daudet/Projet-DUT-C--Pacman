#include <iostream>
#include <vector>
#include <fstream>
#include <unistd.h>
#include <map>

using namespace std;
#include"affichage.h"
#include"settings.h"




void settings()
{
    //(Inspiré par la réalisation de Matthis Houles lors du Tutorat du 19/01/21)
    bool VAR = true;
    while(VAR)
    {
        ClearScreen();
        cout << "\t\t\t\t    Settings" <<endl << endl << endl
             << "To change the movement keys, " << endl
             << "first enter for which movement (ex : Down) and then press Enter, " << endl
             << "next press the key you want to put (ex : q) and finally press Enter to validate." <<endl
             << "Press 4 and then Enter to leave the settings "<< endl << endl;
        ifstream IFlow("../Projet-DUT-C--Pacman/Nos_fichiers/config.yaml"); // Input Flow
        string line;
        string Delimiter = " : ";
        map<string, string> MapParams = {};

        while(getline(IFlow, line)) {
            int pos = line.find(Delimiter);
            MapParams[line.substr(0, pos)] = line.substr(pos+Delimiter.size(), line.size()-1);
        }


        for (map<string, string>::iterator Iter = MapParams.begin(); Iter != MapParams.end(); ++Iter) {
            cout <<Iter->first << " = " << Iter->second << endl;
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

        MapParams[choice] = Key;

        ofstream OFlow("../Projet-DUT-C--Pacman/Nos_fichiers/config.yaml");
        for (map<string, string>::iterator iter = MapParams.begin(); iter != MapParams.end(); ++iter) {
            OFlow << iter->first << " : " << iter->second << endl;
        }
        cout << "done" << endl;
        sleep(1);
        IFlow.close();
        OFlow.close();
    }
}
