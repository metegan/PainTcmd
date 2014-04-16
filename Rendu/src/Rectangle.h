/*************************************************************************
                           Rectangle  -  description
                             -------------------
    début                :  3 jan. 2014
    copyright            :
*************************************************************************/

//---------- Interface de la classe <Rectangle> (fichier Rectangle.h) ------
#if ! defined ( Rectangle_H_ )
#define Rectangle_H_

//--------------------------------------------------- Interfaces utilisées
#include "Point.h"
#include "Figure.h"
#include <string>

//------------------------------------------------------------------------
// Rôle de la classe <Rectangle>
//
//------------------------------------------------------------------------

class Rectangle : public Figure
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    bool Move ( int x, int y );



//-------------------------------------------- Constructeurs - destructeur
    Rectangle ( ) ;

    virtual ~Rectangle ( );

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes publiques

//----------------------------------------------------- Attributs protégés


};

//--------------------------- Autres définitions dépendantes de <Rectangle>

#endif // Rectangle_H_




