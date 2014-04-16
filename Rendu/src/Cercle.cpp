/*************************************************************************
                           Cercle  -  description
                             -------------------
    début                :  3 jan. 2014
    copyright            :
*************************************************************************/

//---------- Réalisation de la classe Cercle (fichier Cercle.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>


//------------------------------------------------------ Include personnel
#include "Cercle.h"
using namespace std;

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

string Cercle::Get_radius()
{
    return to_string(radius);
}



//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//-------------------------------------------- Constructeurs - destructeur

Cercle::Cercle ( vector<string> cmd, int r ) : Figure( cmd )
    {
        radius=r;
    }

Cercle::~Cercle ( ){}
