/*************************************************************************
                           Point  -  description
                             -------------------
    début                :  3 jan. 2014
    copyright            :
*************************************************************************/

//---------- Réalisation de la classe Point (fichier Point.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Point.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
    Point::Point ( int x, int y ) : x(x), y(y) {}
    Point::~Point ( )  {}

    int Point::getX()
    {
        return x;
    }

    int Point::getY()
    {
        return y;
    }

    bool Point::Move ( int deltaX, int deltaY )
    {
      x+=deltaX;
      y+=deltaY;
      return true;
    }



//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

