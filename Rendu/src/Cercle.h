/*************************************************************************
                           Cercle  -  description
                             -------------------
    début                : 11 oct. 2013
    copyright            : (C) 2013 par hhannetel
*************************************************************************/

//---------- Interface de la classe <Cercle> (fichier Cercle.h) ------
#if ! defined ( CERCLE_H_ )
#define CERCLE_H_

//--------------------------------------------------- Interfaces utilisées
#include "Point.h"
#include "Figure.h"

//------------------------------------------------------------------------
// Rôle de la classe <Cercle>
//
//------------------------------------------------------------------------

class Cercle : public Figure
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    string Get_radius();

//-------------------------------------------- Constructeurs - destructeur
    Cercle ( vector<string> cmd, int r );

    virtual ~Cercle ( );

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes publiques

//----------------------------------------------------- Attributs protégés

    int radius; // rayon du cercle


};

//--------------------------- Autres définitions dépendantes de <Cercle>

#endif // CERCLE_H_




