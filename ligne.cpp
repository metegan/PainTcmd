/*************************************************************************
                           Ligne  -  description
                             -------------------
    début                :  3 jan. 2014
    copyright            :
*************************************************************************/

//---------- Réalisation de la classe Ligne (fichier Ligne.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Ligne.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
    Ligne::Ligne ( Point debut, Point fin )
    {
        set_of_points[0]=debut;
        set_of_points[1]=fin;
    }

    bool Ligne::Move ( int x, int y )
    {
        for(int i=0; i<set_of_points.size();i++)
            return Move(set_of_points(i));
    }

    void Ligne::Display( )
    {
        cout<<name;
    }

    string Ligne::Get_cmd( )
    {

        return "L " + name + " " + to_string(set_of_points[0].getX()) + to_string(set_of_points[0].getY()) +
            to_string(set_of_points[1].getX()) + to_string(set_of_points[1].getY()) + to_string(radius);

    }

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

