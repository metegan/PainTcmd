#include <string>
#include "Dessin.h"
#include "Figure.h"
#include "StringExt.h"
#include <iostream>

using namespace std;

int main()
{
    Dessin* dessin = new Dessin();
    char cmdd[256];
    string cmd;
    string figure_name;
    Figure* new_fig;
    vector<string> cmd_split;



    for( ;; )
    {
        cin.getline(cmdd, 256);
        cmd = string(cmdd);
        cmd_split = split(cmd, ' ');


        if( !cmd_split[0].compare("EXIT") )
            { break; }
        if( !cmd_split[0].compare("LOAD") )
            { dessin->Load( cmd_split[1], cmd, *dessin ); }
        else if(!cmd_split[0].compare("LIST") )
            {dessin->Display( ); }
        else if(!cmd_split[0].compare("MOVE") )
            { dessin->Move( cmd_split[1], atoi(cmd_split[2].c_str()), atoi(cmd_split[3].c_str()) ); }
        else
        {
            new_fig = dessin->Create_figure(cmd_split);
            cout << "OK" << endl;
            dessin->Add( new_fig, cmd_split[1] );
            cout << "OK2" << endl;
        }
    }

    return 0;
}
