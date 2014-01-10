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

    bool Move ( string nom, int x, int y );
    // Mode d'emploi :
    //  déplace le point de x en abscisse et y en ordonnée

    string Get_cmd( string name );
    // Mode d'emploi :
    //  génère la commande qui a permis la création la figure


//-------------------------------------------- Constructeurs - destructeur
    Cercle ( vector<string> cmd, int radius );

    virtual ~Cercle ( );

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes publiques

//----------------------------------------------------- Attributs protégés

    int radius; // rayon du cercle


};

//--------------------------- Autres définitions dépendantes de <Cercle>

#endif // CERCLE_H_




