/*************************************************************************
                           Cercle  -  description
                             -------------------
    début                :  3 jan. 2014
    copyright            :
*************************************************************************/

//---------- Réalisation de la classe Cercle (fichier Cercle.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>


//------------------------------------------------------ Include personnel
#include "Cercle.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
    Cercle::Cercle ( vector<string> cmd, int r ) : Figure( cmd )
        {
            radius=r;
        }

    bool Cercle::Move ( string nom, int x, int y )
    {
        return set_of_points[0].Move(x,y);
    }

    string Cercle::Get_cmd( string name )
    {

    }


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

