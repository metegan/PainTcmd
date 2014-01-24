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


