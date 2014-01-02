/*************************************************************************
                           Dessin  -  description
                             -------------------
    début                : 15 nov. 2013
    copyright            : (C) 2013 par hhannetel
*************************************************************************/

//---------- Réalisation de la classe <Dessin> (fichier Dessin.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Figure.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool Dessin::Delete ( string nom_figure)
// Algorithme :
//
{
    if( figure_set.find(nom_figure) )
        { figure_set.erase( nom_figure ); }
    else
        { return false; }
    return true;
}

bool Dessin::Add ( Figure new_figure, string figure_name )
// Algorithme :
//
{
    if( figure_set.find(nom_figure) )
        { return false; }
    else
        { figure_set[figure_name] = new_figure; }
    return true;
}


//-------------------------------------------- Constructeurs - destructeur
Dessin::Dessin ( )
{
    nb_nodes = 0;
#ifdef MAP
    cout << "Appel au constructeur de <Dessin>" << endl;
#endif
} //----- Fin de Dessin


Dessin::~Dessin ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Dessin>" << endl;
#endif
} //----- Fin de ~Dessin


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

