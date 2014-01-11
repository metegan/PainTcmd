/*************************************************************************
                           Polyligne  -  description
                             -------------------
    début                :  3 jan. 2014
    copyright            :
*************************************************************************/

//---------- Réalisation de la classe Polyligne (fichier Polyligne.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Polyligne.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques


    bool Polyligne::Move ( int x, int y )
    {
        for(itv it = set_of_points.begin(); it != set_of_points.end(); it++)

            if(!(it->Move(x,y))) return false;

        return true;
    }

    Polyligne::Polyligne ( ) {}
    Polyligne::~Polyligne ( ) {}
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

