#include <string>
#include <sys/stat.h> // working_dir
#include "Dessin.h"
#include "Figure.h"
#include "StringExt.h"
#include <iostream>

using namespace std;
const int nb_tcmd = 6;

vector< vector<string> > cmd_type =
{
    { "LIST","UNDO","REDO", "EXIT" }, // commands with no parameters
    { "LOAD","SAVE" }, // commands with one string parameter (file)
    { "C" }, // commands with one string and 3 int parameters
    { "R","L" }, // commands with one string and 4 int parameters
    { "PL" }, // commands with one string and n int parameters
    { "DELETE","OA" } // commands with n string parameters
};



bool valid_parameters( vector<string> cmd_split, vector< vector<string> >  cmd_type)
{
    struct stat working_dir; // informations sur le répertoire courant
    int nb_params;

    if( cmd_split.size() == 0 )
        return false;
    for( int i=0; i<nb_tcmd; i++ )
    {
        for( int j=0; j<(int)cmd_type[i].size(); j++ )
        {
            if( ! cmd_split[0].compare(cmd_type[i][j]) )
            {
                if( i < 2 )
                {
                    if( (int)cmd_split.size()-1 != i )
                        return false;
                    else
                        return true;
                }
                else if( i == 1 )
                // the parameter must be a file
                {
                    if( stat( cmd_split[1].c_str(), &working_dir ) )
                    {
                        cerr << "ERR" << endl;
                        cerr << "Fichier " << cmd_split[1] << " non trouvé.\n";
                        return false;
                    }
                    return true;
                }
                else
                {
                    if( is_number(cmd_split[1]) )
                    // The first parameter is a number
                        return false;
                    else if( i < 5 )
                    {
                        if( i == 2 )
                        // Creation of a circle
                            nb_params = 5;
                        else if( i == 3 )
                        // Creation of a rectangle or line
                            nb_params = 6;
                        else
                        // Creation of a poly-line
                            nb_params = 8;

                        if( (int)cmd_split.size() < nb_params )
                            return false;
                        if( nb_params < 8 && (int)cmd_split.size() > nb_params )
                            return false;

                        for( int k=2; k < (int)cmd_split.size(); k++ )
                        {
                            if( ! is_number(cmd_split[k]) )
                                return false;
                        }
                        return true;
                    }
                    else
                    // Creation of an OA or deletion
                    {
                        if( cmd_split.size() < 2 )
                            return false;
                        if( !cmd_split[0].compare("OA") && cmd_split.size() < 4 )
                            return false;
                        for( int k=2; k < (int)cmd_split.size(); k++ )
                        {
                            if( is_number(cmd_split[k]) )
                                return false;
                        }
                        return true;
                    }
                }
            }
        }// for 2
    }// for 1
    return false;
}

int main()
{

    Dessin* dessin = new Dessin();
    char cmdd[256];
    string cmd;
    string figure_name;
    Objet* new_obj;
    vector<string> cmd_split;
    bool change;


    for( ;; )
    {
        change=true;
        cin.getline(cmdd, 256);
        cmd = string(cmdd);
        cmd_split = split(cmd, ' ');

        if( ! valid_parameters( cmd_split, cmd_type) )
        {
            cerr << "ERR" << endl;
            cerr << "# Invalid parameters" << endl;
            continue;
        }

        if(!cmd_split[0].compare("REDO") )
        {
            change=false;
            cmd_split = dessin->Redo();
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
            for( int i=1; i<(int)cmd_split.size(); i++ )
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

        else if( !cmd_split[0].compare("CLEAR") )
            {
                dessin->Clear();
                cout << "OK" << endl;
                cout << "# Dessin réinitialisé" << endl;
            }


        else if( !cmd_split[0].compare("UNDO") )
            {
                change=false;
                dessin->Undo();
                cout << "OK" << endl;
            }

        else
            {
                new_obj = dessin->Create_objet(cmd_split);
                if( ! dessin->Add( new_obj, cmd_split[1] ) )
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
        if(change)
            dessin->Set_last_cmd(cmd_split);



    }

    return 0;
}
