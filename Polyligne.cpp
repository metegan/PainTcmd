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
    Polyligne::Polyligne ( ) {}

    bool Polyligne::Move ( int x, int y )
    {
        for(int i=0; i<set_of_points.size();i++)
            return Move(set_of_points(i));
    }

    void Polyligne::Display( )
    {
        cout<<name<<" ";
    }

    string Polyligne::Get_cmd( )
    {
        string affichage = "PL " + name + " ";
        for(int i = 0; i < set_of_points.size(); i++)
        {
            affichage+= to_string(set_of_points[i].getX()) + to_string(set_of_points[i].getY());
        }

        return affichage + to_string(radius);

    }

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

