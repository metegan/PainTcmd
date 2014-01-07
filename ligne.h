/*************************************************************************
                           Ligne  -  description
                             -------------------
    début                :  3 jan. 2014
    copyright            :
*************************************************************************/

//---------- Interface de la classe <Ligne> (fichier Ligne.h) ------
#if ! defined ( Ligne_H_ )
#define Ligne_H_

//--------------------------------------------------- Interfaces utilisées
#include "Point.h"
#include "Figure.h"
#include <string>

//------------------------------------------------------------------------
// Rôle de la classe <Ligne>
//
//------------------------------------------------------------------------

class Ligne : public Figure
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    bool Move ( int x, int y );

    string Get_cmd( );

    void Display();

//-------------------------------------------- Constructeurs - destructeur
    Ligne (Point debut, Point fin ) ;

    virtual ~Ligne ( );

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes publiques

//----------------------------------------------------- Attributs protégés


};

//--------------------------- Autres définitions dépendantes de <Ligne>

#endif // Ligne_H_




