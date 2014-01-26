/*************************************************************************
                           Dessin  -  description
                             -------------------
    début                : 15 nov. 2013
    copyright            : (C) 2013 par hhannetel
*************************************************************************/

//---------- Réalisation de la classe <Dessin> (fichier Dessin.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>
#include <utility>
#include <iostream>
#include <fstream>

//------------------------------------------------------ Include personnel

#include "Dessin.h"
#include "Objet.h"
#include "StringExt.h"
#include "Point.h"
#include "Rectangle.h"
#include "Cercle.h"
#include "Polyligne.h"
#include "ligne.h"
#include "Objet_agrege.h"
using namespace std;
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool Dessin::Delete ( string nom_objet )
// Algorithme :
//
{
    vector<string>* objets_names;
    bool to_erase = false;

    if( objet_set.find( nom_objet ) == objet_set.end() )
        return false;

    last_erased.push_back( make_pair( objet_set[nom_objet], vector<string>() ) );
    objet_set.erase( nom_objet );

    for( iter it = objet_set.begin(); it != objet_set.end(); it++)
    {
        if( ! it->second->Get_type().compare("OA") )
        {
            objets_names = ((Objet_agrege*)it->second)->Get_objets_names();
            for( unsigned int i=0; i < objets_names->size(); i++ )
            {
                if( ! (*objets_names)[i].compare(nom_objet) )
                {
                    to_erase = true;
                    objets_names->erase( objets_names->begin() + i-- );
                }
            }
            if( to_erase )
            // Ajout de l'OA à la liste des OA qui contenaient l'objet supprimé
                last_erased.back().second.push_back( it->first );
            if( objets_names->size() < 2 )
                objet_set.erase(it++);
            to_erase = false;
        }
    }

    return true;
}

bool Dessin::Add ( Objet* new_objet, string objet_name )
// Algorithme :
//
{
    if( objet_set.size() != 0 && objet_set.find(objet_name) != objet_set.end() )
        return false;

    objet_set[objet_name] = new_objet;
    return true;
}


bool Dessin::Load ( string file_name, string cmd)
// Algorithme :
//
{
    vector <string> cmd_split;
    Objet* new_obj;
    ifstream file;
    file.open( file_name );

    if( file.is_open() )
    {
        while( getline(file,cmd) )
        {
            cmd_split = split(cmd, ' ');
            new_obj = Create_objet(cmd_split);
            Add(new_obj, cmd_split[1]);
        }
        cout << "OK" << endl;
        return true;
    }

    cout << "# Impossible d'ouvrir le fichier !" << endl;
    return false;
}

bool Dessin::Save( string file_name )
{
    ofstream fichier(file_name, ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert
    if(fichier)
    {
        for(iter it = objet_set.begin(); it != objet_set.end(); it++)
            fichier<<it->second->Get_cmd(it->second,it->first)<<endl;
        fichier.close();
        cout<<"OK"<<endl;
        return true;
    }

    cout << "# Impossible d'ouvrir le fichier !" << endl;
    return false;
}

bool Dessin::Clear( )
{
    old_objet_set=objet_set;
    objet_set.clear();
    cout << "OK" << endl;
    cout << "# Dessin réinitialisé" << endl;
    return true;
}

void Dessin::Display( )
{
    for(iter it = objet_set.begin(); it != objet_set.end(); it++)
        cout << it->second->Get_cmd( it->second,it->first ) << endl;
}

Objet* Dessin::Create_objet( vector<string> cmd )
{
        Objet* obj;
        Point* p;

        if(!cmd[0].compare("OA"))
        {
            obj=new Objet_agrege( cmd, this);
            obj->Set_type(cmd[0]);
            return obj;
        }

        else if( !cmd[0].compare("C") )
        {
            obj=new Cercle( cmd, atoi(cmd[4].c_str()) );
            obj->Set_type(cmd[0]);
            p=new Point( atoi(cmd[2].c_str()), atoi(cmd[3].c_str()) );
            ((Figure*)obj)->Add_point(*p);
            return obj;
        }

        else if(!cmd[0].compare("R"))
            obj=new Rectangle();

        else if(!cmd[0].compare("L"))
            obj=new Ligne();

        else if(!cmd[0].compare("PL"))
            obj=new Polyligne();

        else
            return NULL;

        obj->Set_type(cmd[0]);
        for( unsigned int i=2; i < cmd.size(); i+=2 )
        {   //cout<<"da ";
            p=new Point( atoi(cmd[i].c_str()), atoi(cmd[i+1].c_str()) );
            ((Figure*)obj)->Add_point(*p);
        }

        return obj;
}

bool Dessin::Move(string objet_name, int dx, int dy )
{
    if( objet_set.find(objet_name) != objet_set.end() )
        objet_set[objet_name]->Move(dx, dy);
    else
        return false;
    return true;
}

void Dessin::Set_last_cmd(vector<string> cmd)
{
    if( last_cmd.size() > 19 )
        last_cmd.erase( last_cmd.begin() );
    last_cmd.push_back(cmd);
}

//vector<string> Dessin::Get_last_cmd() { return last_cmd.back(); }

void Dessin::Undo()
{
        Objet* new_obj;
        vector<string> undo_cmd;

        if( ++cpt_undo > 1 )
            last_cmd.pop_back();

        //if( last_cmd.size() == 1 )
        undo_cmd = last_cmd.back();
        //else
           // undo_cmd = last_cmd[last_cmd.size()-2];


        if( !undo_cmd[0].compare("LOAD") )
        {
            ifstream file;
            file.open(last_cmd.back()[1]);
            if( file.is_open() )
            {
                string cmd;
                vector<string> cmd_split;
                while( getline(file,cmd) )
                {
                    cmd_split = split(cmd, ' ');
                    Delete(cmd_split[1]);
                    cout << "# Object " << cmd_split[1] << " deleted" << endl;
                }
             }
        }

        else if( !undo_cmd[0].compare("MOVE") )
        {
            Move(undo_cmd[1], atoi(last_cmd[0][2].c_str())*(-1), atoi(last_cmd[0][3].c_str())*(-1));
        }

        else if( !undo_cmd[0].compare("DELETE") )
        {
            for( int i=1; i<(int)last_cmd.back().size(); i++ )
            {
                cout << last_erased.back().first->Get_cmd( last_erased.back().first, last_cmd.back()[1] ) << endl;
                new_obj = Create_objet( split( last_erased.back().first->Get_cmd( last_erased.back().first, last_cmd.back()[1] ), ' ') );
                Add(new_obj, undo_cmd[i]);//TODO ecraser reellement en memoire pas juste pointeur
            }
        }

        else if( !undo_cmd[0].compare("CLEAR") )
        {
            objet_set=old_objet_set;

        }

        else
            Delete( undo_cmd[1] );
}

vector<string> Dessin::Redo()
{
    cpt_undo--;
    return last_cmd.back();
}

//int gs() { return (int)objet_set.size(); }
//-------------------------------------------- Constructeurs - destructeur
Dessin::Dessin ( )
{
    cpt_undo = 0;
#ifdef MAP
    cout << "Appel au constructeur de <Dessin>" << endl;
#endif
} //----- Fin de Dessin


Dessin::~Dessin ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Dessin>" << endl;
#endif
} //----- Fin de ~Dessin


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

