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
    bool change;


    for( ;; )
    {
        change=true;
        cin.getline(cmdd, 256);
        cmd = string(cmdd);
        cmd_split = split(cmd, ' ');

        if(!cmd_split[0].compare("REDO") )
        {
            change=false;
            cmd_split = dessin->Get_last_cmd();
        }
        else if( !cmd_split[0].compare("EXIT") )
            { break; }

        if( !cmd_split[0].compare("LOAD") )
            { dessin->Load( cmd_split[1], cmd); }
        else if(!cmd_split[0].compare("LIST") )
            {
                change=false;
                dessin->Display( );
            }
        else if(!cmd_split[0].compare("MOVE") )
            { dessin->Move( cmd_split[1], atoi(cmd_split[2].c_str()), atoi(cmd_split[3].c_str()) ); }
        else if( !cmd_split[0].compare("SAVE") )
            {
                change=false;
                dessin->Save( cmd_split[1]);
            }
        else if(!cmd_split[0].compare("DELETE") )
            {dessin->Delete(cmd_split[1]); }

        else if(!cmd_split[0].compare("UNDO") )
            {
                change=false;
                dessin->Undo();
            }
        else if( !cmd_split[0].compare("CLEAR") )
            {
                dessin->Clear();
            }

        else
        {
            new_fig = dessin->Create_figure(cmd_split);
            dessin->Add( new_fig, cmd_split[1] );
        }
        if(change) dessin->Set_last_cmd(cmd_split);



    }

    return 0;
}
