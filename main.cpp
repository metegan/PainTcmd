#include <string>
#include <sys/stat.h> // working_dir
#include "Dessin.h"
#include "Figure.h"
#include "StringExt.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

/*************************************************************************
Pour chaque objet créé on lui affilie un numéro égal à la taille de la map

Créer un tableau statique de n pointeurs sur objet
à chaque fois qu'on rencontre un objet regarder son numéro
ajouter son pointeur dans le tableau à cet indice.
*/

bool is_nr ( string s)
// contrat : l'utilisateur s'assure que la chaîne est non vide
{
    if( (s[0] < 48 || s[0] > 57) && s[0] != 45 )
    // ni un chiffre ni le signe moins
        return false;

    for( unsigned int i=1; i< s.size(); i++)
    {
        if( s[i] < 48 || s[i] > 57 )
            return false;
    }
    return true;
}


bool valid_parameters( vector<string> cmd_split, vector<vector<string>> cmd_type)
{

    struct stat working_dir; // informations sur le répertoire courant
    int nb_params;

    if( cmd_split.size() == 0 )
    {
       //commande vide
        return false;
    }


    for( int i=0; i<7; i++ )
    {
       for( int j=0; j<(int)cmd_type[i].size(); j++ )
        {
            if( ! cmd_split[0].compare(cmd_type[i][j] ) )
            {
                if( i == 0 ) //commande avec 0 params
                {
                    if( (int)cmd_split.size() != 1 )
                        return false;
                    return true;
                }
                else if( i == 1 )
                {
                       // un seul param apres le nom de la commande, le nom d'un fichier
                    if( (int)cmd_split.size() != 2 )
                        return false;

                    if( !cmd_split[0].compare("LOAD") && stat( cmd_split[1].c_str(), &working_dir ) )
                    {
                        cerr << "ERR" << endl;
                        cerr << "# Fichier " << cmd_split[1] << "non trouvé" <<endl;
                        return false;
                    }
                    return true;

                }


                else if( i == 2 )
                    {
                          // Creation of a circle
                        nb_params = 5;
                        if( (int)cmd_split.size() != nb_params )
                            return false;
                        if( atoi(cmd_split.back().c_str()) < 0 )
                        {
                            cerr << "ERR" << endl;
                            cerr << "# Le rayon d'un cercle ne peut pas être negatif" << endl;
                            return false;
                        }
                        return true;
                    }

                else if( i == 3 )
                    {
                        // Creation of a rectangle or line
                        nb_params = 6;

                        if( (int)cmd_split.size() != nb_params ) return false;

                    //on verifie que les parametres apres les 2 param string (nom du commande et de l'objet a creer) sont des nombres
                        for( int k=2; k < (int)cmd_split.size(); k++ )
                        {
                            if( ! is_nr(cmd_split[k]) )
                                return false;
                        }
                    return true;

                    }
                else if ( i == 4 ) //polyligne
                    {


                        if(cmd_split.size() % 2 != 0) //chaque point a 2 coord => nombre pair de parametres int
                            {
                                cerr<<"# nombre impaire de parametres"<<endl;
                                return false;
                            }

                        for( unsigned int k=2; k < cmd_split.size() ; k++ )
                        {

                            if( ! is_nr(cmd_split[k]) )
                            {
                                cerr<<"# attention il faut introduire des coordonnes"<<endl;
                                return false;
                            }

                        }
                    return true;

                    }
                else if ( i == 5 )
                    // Creation of an OA or deletion
                    {
                        if( cmd_split.size() < 2 )
                            return false;
                        if( !cmd_split[0].compare("OA") && cmd_split.size() < 4 )
                            return false;
                        for( unsigned int k=2; k < cmd_split.size(); k++ )
                        {
                            if( is_nr(cmd_split[k]) )
                                return false;
                        }
                        return true;
                    }
                else if ( i == 6) //MOVE
                {
                    nb_params = 4;

                    if( (int)cmd_split.size() != nb_params ) return false;

                    //on verifie que les 2 parametres apres le nom du commande et de l'objet a creer sont des nombres
                    for( int k=2; k < (int)cmd_split.size(); k++ )
                        {
                            if( ! is_nr(cmd_split[k]) )
                                return false;
                        }
                    return true;
                }
            return true;
            } //fin if

        }// for 2
    }// for 1
    return false;
}
int main()
{



    vector< vector<string> > cmd_type =
    {
        { "LIST","UNDO","REDO", "EXIT", "CLEAR" }, // commands with no parameters
        { "LOAD","SAVE" }, // commands with one string parameter (file)
        { "C" }, // commands with one string and 3 int parameters
        { "R","L"}, // commands with one string and 4 int parameters
        { "PL" }, // commands with one string and n int parameters
        { "DELETE","OA" },// commands with n string parameters
        { "MOVE" } // commands with one string parameter and 2 int
    };


    Dessin* dessin = new Dessin();
    char cmdd[255];
    string cmd;
    string figure_name;
    Objet* new_obj;
    vector<string> cmd_split;
    vector<string> o_to_delete;
    bool change;


    for( ;; )
    {
        change=true;
        cin.getline(cmdd, 255);
        cmd = string(cmdd);
        cmd_split = split(cmd, ' ');


        if(  valid_parameters( cmd_split, cmd_type ) )
        {

            if(!cmd_split[0].compare("REDO") )
            {
                change=false;
                if( dessin->Get_last_cmd_len() > 0 )
                    cmd_split = dessin->Redo();
                else
                {
                    cerr << "ERR" << endl;
                    cerr << "# REDO can be done after UNDO only" << endl;
                    continue;
                }
            }
            if( !cmd_split[0].compare("EXIT") )
                break;

            else if( !cmd_split[0].compare("LOAD") )
            {
                dessin->Load( cmd_split[1], cmd);
            }
            else if(!cmd_split[0].compare("LIST") )
            {
                change=false;
                dessin->Display( );
            }

            else if(!cmd_split[0].compare("MOVE") )
            {
                if(  dessin->Move( cmd_split[1], atoi(cmd_split[2].c_str()), atoi(cmd_split[3].c_str()) ) )
                {
                    cout << "OK" << endl;
                    //cout << "# Object " << cmd_split[1] << " moved" << endl;
                }
                else
                {
                    cout << "ERR" << endl;
                    cout << "# Object " << cmd_split[1] << " unknown" << endl;
                }

            }

            else if( !cmd_split[0].compare("SAVE") )
            {
                change=false;
                dessin->Save( cmd_split[1]);
            }

            else if(!cmd_split[0].compare("DELETE") )
            {
                for( int i=1; i < (int)cmd_split.size(); i++ )
                {
                    o_to_delete = vector<string>();
                    o_to_delete.push_back(cmd_split[i]);
                    if( ! dessin->Delete(o_to_delete) )
                    {
                        cerr << "ERR" << endl;
                        cerr << "# Object " << cmd_split[i] << " unknown" << endl;
                    }
                    else
                    {
                        cout << "OK" << endl;
                        //cout << "# Object " << cmd_split[i] << " deleted" << endl;
                    }
                }
            }

            else if( !cmd_split[0].compare("CLEAR") )
            {
                dessin->Clear();

            }


            else if( !cmd_split[0].compare("UNDO") )
            {
                change=false;
                if( dessin->Get_last_cmd_len() > 0 )
                {
                    dessin->Undo();
                    cout << "OK" << endl;
                }
                else
                {
                    cerr << "ERR" << endl;
                    cerr << "# You must write a command at first" << endl;
                }
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
                    //cout << "# New object : " << cmd_split[1] << endl;
                }
            }
        }

        else { //les parametres ne sont pas valids
            cerr << "ERR" << endl;
            cerr << "# Invalid parameters" << endl;
            //continue;
        }

        if(change)
            dessin->Set_last_cmd(cmd_split);


    }


      return 0;
}
