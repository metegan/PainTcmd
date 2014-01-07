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
    Rectangle::Rectangle ( Point bas, Point haut )
    {
        set_of_points[0]=bas;
        set_of_points[1]=haut;
    }

    bool Rectangle::Move ( int x, int y )
    {
        return set_of_points[0].Move(x,y);
        return set_of_points[1].Move(x,y);
    }

    void Rectangle::Display( )
    {
        cout<<name<<" ";
    }

    string Rectangle::Get_cmd( )
    {
        return "R" + name + " " + to_string(set_of_points[0].getX()) + to_string(set_of_points[0].getY()) +
            to_string(set_of_points[1].getX()) + to_string(set_of_points[1].getY()) + to_string(radius);

    }

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

