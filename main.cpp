#include <string>
#include "Dessin.h"
#include "Figure.h"
#include "StringExt.h"
#include <iostream>

using namespace std;
const int nb_cmd = 5;

string cmd_name[nb_cmd] = {"C","R","L","PL","OA"};

bool valid_parameters( vector<string> cmd_split, string*  cmd_name)
{
    bool found = false;

    if( ! cmd_split[0].compare("DELETE") && cmd_split.size() < 2 )
        return false;
    if( ! cmd_split[0].compare("MOVE") && cmd_split.size() < 4 )
        return false;
    if( ! cmd_split[0].compare("LIST") && cmd_split.size() > 1 )
        return false;

    for( int i=0; i<nb_cmd; i++)
    {
        if( ! cmd_split[0].compare(cmd_name[i]) )
        {
            if( cmd_split.size() < 4 )
                return false;
            else if( is_number(cmd_split[1]) )
                return false;
            found = true;
        }
    }
    if( found )
        return true;
    return true;
}

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

        if( ! valid_parameters( cmd_split, cmd_name) )
        {
            cerr << "ERR" << endl;
            cerr << "# Invalid parameters" << endl;
            continue;
        }

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
        {
            if( ! dessin->Move( cmd_split[1], atoi(cmd_split[2].c_str()), atoi(cmd_split[3].c_str()) ) )
            {
                cerr << "ERR" << endl;
                cerr << "# Object " << cmd_split[1] << " unknown" << endl;
            }
            else
            {
                cout << "OK" << endl;
                cout << "# Object " << cmd_split[1] << " moved" << endl;
            }

        }
        else if( !cmd_split[0].compare("SAVE") )
            {
                change=false;
                dessin->Save( cmd_split[1]);
            }
        else if(!cmd_split[0].compare("DELETE") )
        {
            for( int i=1; i<cmd_split.size(); i++ )
            {
                if( ! dessin->Delete(cmd_split[i]) )
                {
                    cerr << "ERR" << endl;
                    cerr << "# Object " << cmd_split[i] << " unknown" << endl;
                }
                else
                {
                    cout << "OK" << endl;
                    cout << "# Object " << cmd_split[i] << " deleted" << endl;
                }
            }
        }

        else if(!cmd_split[0].compare("UNDO") )
            {
                change=false;
                dessin->Undo();
            }
        else if( !cmd_split[0].compare("CLEAR") )
            {
                dessin->Clear();
            }

        else if( !cmd_split[0].compare("OA") )
            {
                if( ! dessin->Add_oa(cmd_split) )
                {
                    cerr << "ERR" << endl;
                    cerr << "# Invalid parameters" << endl;
                    continue;
                }
                else
                {
                    cout << "OK" << endl;
                    cout << "# New object : " << cmd_split[1] << endl;
                }
            }
        else
        {
            new_fig = dessin->Create_figure(cmd_split);
            if( dessin->Add( new_fig, cmd_split[1] ) )
            {
                cout << "OK" << endl;
                cout << "# New object : " << cmd_split[1] << endl;
            }
        }
        if(change) dessin->Set_last_cmd(cmd_split);



    }

    return 0;
}
