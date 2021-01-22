
#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include "alias.h"


using namespace std;

#include "alias.h"
#include "affichage.h"

void ClearScreen (){
    //Clear the screen
    cout << "\033[H\033[2J";
}



void Color (const string & coul){
    // Allows you to add Color in the terminal
    cout << "\033[" << coul <<"m";
}


void EntryPlayerscore(unsigned score)
{
    ofstream Scoreplayer;
    string Playername;
    Scoreplayer.open("../Projet-DUT-C--Pacman-main/Nos_fichiers/TxtDirectory/PlayersScores.txt",ios::out|ios::app);
    if(Scoreplayer)
      {
        cout << "Entry your username" << endl;
        cin >> Playername;
        if (Playername.size() > 15)
          {
            EntryPlayerscore(score);
           }
        else
          {
            Scoreplayer << Playername << " " << score << endl;
          }
      }
    else
       {
        cout << "ça marche pas lo " << endl;
       }
    Scoreplayer.close();
}

void Displayscore()
{
   ifstream Scoreplayerdisplay("PlayersScores.txt");
   string line;
   while(getline(Scoreplayerdisplay, line))
      {
        cout << line << endl;
      }

}

void ShowMap(StringMatrix & map, unsigned & SuperPacGum){
    // Color map and show it
  string Background = KBBlue;
  if (SuperPacGum > 0) Background = KBCyan;
    ClearScreen ();
    Color(Background);
  Color(KBlack);
    for (int x = 0; x < map.size(); x++) {
        for (int y = 0; y < map[x].size(); y++) {
            if ( map[x][y] == Pacman){
        Color(KYellow);}
      else if ( map[x][y] == "@"){
        Color(KRed);}
      else if ( map[x][y] == "$"){
        Color(KRed);}
      else if ( map[x][y] == "£"){
        Color(KRed);}
      else if ( map[x][y] == "."){
        Color(KLightGrey);}

      cout << map[x][y];
      Color(KBlack);

        }
        cout << endl;
    }
    Color(KReset);
}
