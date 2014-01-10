/*************************************************************************
                           Figure  -  description
                             -------------------
    début                :  3 jan. 2014
    copyright            :
*************************************************************************/

//---------- Réalisation de la classe Figure (fichier Figure.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>
#include <stdlib.h>
//------------------------------------------------------ Include personnel
#include "Figure.h"

#include "Point.h"
#include "Rectangle.h"
#include "Cercle.h"
#include "Polyligne.h"
#include "ligne.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
    Figure::Figure ( vector<string> cmd ) { }

    void Figure::Add_point( Point& p )
    {
        set_of_points.push_back(p);
    }

    void Figure::Set_type( string t )
    {
        type=t;
    }

    string Figure::Get_cmd( string name )
    {
        string cmd = type + " " + name;
        for(itv i = set_of_points.begin(); i < set_of_points.end(); i++)
        {
            cmd+= " " + to_string(i->getX()) + " " + to_string(i->getY());
        }

        return cmd;
    }
    bool Figure::Move ( int x, int y )
    {
        for(itv it = set_of_points.begin(); it != set_of_points.end(); it++)

            if(!(it->Move(x,y))) return false;

        return true;

    }

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

