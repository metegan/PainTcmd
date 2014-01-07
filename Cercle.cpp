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
    Cercle::Cercle ( Point center, int radius ) : radius(radius)
    {
        set_of_points[0]=center;
    }

    bool Cercle::Move ( string nom, int x, int y )
    {
        return set_of_points[0].Move(x,y);
    }

    void Cercle::Display( )
    {
        cout<<name<<" ";
    }

    string Cercle::Get_cmd( )
    {

        //return "C " + name + " " + to_string(set_of_points[0].getX()) + to_string(set_of_points[0].getY()) + to_string(radius);

    }

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

