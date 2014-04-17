/*************************************************************************
                           Rectangle  -  description
                             -------------------
    début                :  3 jan. 2014
    copyright            :
*************************************************************************/

//---------- Réalisation de la classe Rectangle (fichier Rectangle.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Rectangle.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

    bool Rectangle::Move ( int x, int y )
    {
        set_of_points[0].Move(x,y);
        return set_of_points[1].Move(x,y);
    }


    Rectangle::Rectangle ( ) { }
    Rectangle::~Rectangle ( ) { }
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

