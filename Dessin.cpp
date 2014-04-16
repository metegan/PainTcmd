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
bool Dessin::Delete ( vector<string> nom_objet)
// Algorithme :
//
{
    vector<string>* objets_names;
    string name;
    Objet* new_obj;
    Objet* old_objet;

    if( nom_objet.size() < 2 )
    {
        if( objet_set.find( nom_objet[0] ) == objet_set.end() )
            return false;

        old_objet = objet_set[nom_objet[0]];
        new_obj = Create_objet( split( old_objet->Get_cmd( old_objet, last_cmd.back()[1] ), ' ') );
        last_erased.push_back( make_pair( new_obj, vector<string>() ) );
        delete objet_set[nom_objet[0]];
        objet_set.erase( nom_objet[0] );
    }
    for( iter it = objet_set.begin(); it != objet_set.end(); it++ )
    {
        if( ! it->second->Get_type().compare("OA") )
        {
            objets_names = ((Objet_agrege*)it->second)->Get_objets_names();
            for( unsigned int i=0; i < objets_names->size(); i++ )
            {
                for( unsigned int j=0; j < nom_objet.size(); j++ )
                {
                    if( ! (*objets_names)[i].compare(nom_objet[j]) )
                    {
                        last_erased.back().second.push_back( nom_objet[j] );
                        objets_names->erase( objets_names->begin() + i );
                    }
                }
            }
            if( objets_names->size() < 2 )
            // Ajout de l'OA à la liste des OA qui contenaient l'objet supprimé
            {
                last_erased.back().second.push_back( (*objets_names)[0] );
                //delete objets_names;
                last_erased.back().second.push_back( it->first+" OA" );
                name = it->first;
                delete it->second;
                objet_set.erase( it );
                for( unsigned int p=0; p<nom_objet.size(); p++ )
                {
                    if( !nom_objet[p].compare(name) )
                    {
                        break;
                    }
                    if( p == nom_objet.size()-1 )
                    {
                        nom_objet.push_back(name);
                        Delete(nom_objet);
                    }
                }
                break;
            }
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


bool Dessin::Load ( string file_name, string  &cmd)
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
    ofstream fichier( file_name, ios::out | ios::trunc );  // ouverture en écriture avec effacement du fichier ouvert
    if( fichier.is_open() )
    {
        for(iter it = objet_set.begin(); it != objet_set.end(); it++)
            fichier << it->second->Get_cmd(it->second,it->first) << endl;
        fichier.close();
        cout<<"OK"<<endl;
        return true;
    }

    cout << "# Impossible d'ouvrir le fichier !" << endl;
    return false;
}

bool Dessin::Clear( )
{
    unordered_map<string, Objet*> new_objet_set;
    old_objet_set.push_back(objet_set);
    objet_set = new_objet_set;
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
            obj = new Objet_agrege( cmd, this);
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
    {
        if( !split( objet_set[objet_name]->Get_cmd( objet_set[objet_name], objet_name ), ' ')[0].compare("OA") )
            ((Objet_agrege*)objet_set[objet_name])->Move(dx, dy, objet_name);
        else
        {
            objet_set[objet_name]->Move(dx, dy);
            Add_already_moved(objet_name);
        }
    }
    else
        return false;
    return true;
}

void Dessin::Set_last_cmd(vector<string> cmd)
{
    if( last_cmd.size() > 2 )
    {//TODO supprimer les objets/dessin
        if( !last_cmd.front()[0].compare("DELETE") )
        {
            if( !last_erased.front().first->Get_type().compare("OA") )
                ((Objet_agrege*)last_erased.front().first)->~Objet_agrege();
            else
                ((Figure*)last_erased.front().first)->~Figure();
            last_erased.erase( last_erased.begin() );
        }
        else if( !last_cmd.front()[0].compare("CLEAR") )
        {
            for( iter it = old_objet_set[0].begin(); it != old_objet_set[0].end(); it++ )
            {
                    delete (it->second);
            }
            old_objet_set[0].clear();
            old_objet_set.erase( old_objet_set.begin() );
        }
        last_cmd.erase( last_cmd.begin() );
    }
    last_cmd.push_back(cmd);
}

//vector<string> Dessin::Get_last_cmd() { return last_cmd.back(); }

void Dessin::Undo()
{
        pair<Objet*, vector<string>> new_obj;
        vector<string> undo_cmd;
        vector<string> new_oa;
        vector<string> o_to_delete;

        if( ++cpt_undo > 1 && last_cmd.size() > 1 )
        {
            last_cmd.pop_back();
            cpt_undo--;
        }

        undo_cmd = last_cmd.back();

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
                    o_to_delete.push_back(cmd_split[1]);
                    Delete(o_to_delete);
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

                new_obj = last_erased.back();
                Add(new_obj.first, undo_cmd[i]);
                while( new_obj.second.size() > 0 )
                {
                    new_oa = vector<string>();
                    if( split( new_obj.second.back(), ' ').size() > 1 )
                    {
                        new_oa.push_back( split( new_obj.second.back(), ' ')[1] );
                        new_oa.push_back( split( new_obj.second.back(), ' ')[0] );
                        new_obj.second.pop_back();
                        while( new_obj.second.size() > 0 && split( new_obj.second.back(), ' ').size() < 2  )
                        {
                            new_oa.push_back( new_obj.second.back() );
                            new_obj.second.pop_back();
                        }
                        Add( Create_objet(new_oa), new_oa[1] );
                    }
                    else
                    {
                        ((Objet_agrege*)objet_set[new_obj.second.back()])->Add( last_cmd.back()[i] );
                        new_obj.second.pop_back();
                    }
                }
                last_erased.pop_back();
            }
        }

        else if( !undo_cmd[0].compare("CLEAR") )
        {
            objet_set = old_objet_set.back();
        }

        else
        {
            o_to_delete.push_back(undo_cmd[1]);
            Delete( o_to_delete );
        }
}

vector<string> Dessin::Redo()
{
    vector<string> last = last_cmd.back();
    last_cmd.pop_back();
    cpt_undo--;
    return last;
}

vector<string> Dessin::Get_already_moved() { return already_moved; };

void Dessin::Add_already_moved(string nom) { already_moved.push_back(nom); }

int Dessin::Get_last_cmd_len() { return last_cmd.size(); }

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

