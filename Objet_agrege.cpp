/*************************************************************************
                           Objet_agrege  -  description
                             -------------------
    début                :  3 jan. 2014
    copyright            :
*************************************************************************/

//---------- Réalisation de la classe Objet_agrege (fichier Objet_agrege.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <stdlib.h>
//------------------------------------------------------ Include personnel
#include "Objet_agrege.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

    string Objet_agrege::Get_cmd( Objet* obj, string name )
    {
        string cmd = type + " " + name;
        for(unsigned int i = 0; i < objets.size(); i++)
            cmd += " " + objets[i];

        return cmd;
    }

    bool Objet_agrege::Move ( int x, int y )
    {
        for(unsigned int i = 0; i < objets.size(); i++)
            if( !dessin_pere->Move(objets[i],x,y) ) return false;

        return true;

    }

    bool Objet_agrege::Move ( int x, int y, string name )
    {
        vector<string> already_moved = dessin_pere->Get_already_moved();
        dessin_pere->Add_already_moved(name);
                cout << "Add " << name << endl;
        if( already_moved.size() < 1 )
        {
            for(unsigned int i = 0; i < objets.size(); i++)
            {
                if( !dessin_pere->Move(objets[i],x,y) ) return false;
            }
        }
        else
        {
            for(unsigned int i = 0; i < objets.size(); i++)
            {
                for( int j=0; j<already_moved.size(); j++ )
                {
                    cout <<"j " << j << endl;
                    cout <<"already_moved.size() " << already_moved.size()-1 << endl;
                    cout << "passé " << already_moved[j] << endl;
                    if( !name.compare(already_moved[j]) )
                        return false;
                    cout << "passé0" << already_moved[j] << endl;
                    if( !objets[i].compare(already_moved[j]) )
                        break;
                    if( j == already_moved.size()-1 )
                    {
                        if( !dessin_pere->Move(objets[i],x,y) )
                            return false;
                    }
                }
            }
        }

        return true;

    }

    bool Objet_agrege::Add( string name )
    {
        objets.push_back(name);
        return true;
    }

    vector<string>* Objet_agrege::Get_objets_names( ) { return &objets; }

//-------------------------------------------- Constructeurs - destructeur
    Objet_agrege::Objet_agrege ( vector<string> cmd, Dessin* pere )
    {
        dessin_pere = pere;
        for( unsigned int i=2; i < cmd.size(); i++ )
            objets.push_back( cmd[i] );
    }

    Objet_agrege::Objet_agrege ( ) { }

    Objet_agrege::~Objet_agrege ( ) { }

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


