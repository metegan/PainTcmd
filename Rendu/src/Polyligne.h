/*************************************************************************
                           Polyligne  -  description
                             -------------------
    début                :  3 jan. 2014
    copyright            :
*************************************************************************/

//---------- Interface de la classe <Polyligne> (fichier Polyligne.h) ------
#if ! defined ( Polyligne_H_ )
#define Polyligne_H_

//--------------------------------------------------- Interfaces utilisées
#include "Point.h"
#include "Figure.h"
#include <string>

//------------------------------------------------------------------------
// Rôle de la classe <Polyligne>
//
//------------------------------------------------------------------------

class Polyligne : public Figure
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    bool Move ( int x, int y );


//-------------------------------------------- Constructeurs - destructeur
    Polyligne ( ) ;

    virtual ~Polyligne ( );

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes publiques

//----------------------------------------------------- Attributs protégés


};

//--------------------------- Autres définitions dépendantes de <Polyligne>

#endif // Polyligne_H_




