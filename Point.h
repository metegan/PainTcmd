/*************************************************************************
                           Point  -  description
                             -------------------
    début                : 11 oct. 2013
    copyright            : (C) 2013 par hhannetel
*************************************************************************/

//---------- Interface de la classe <Point> (fichier Point.h) ------
#if ! defined ( POINT_H_ )
#define POINT_H_

//--------------------------------------------------- Interfaces utilisées


//------------------------------------------------------------------------
// Rôle de la classe <Point>
//
//------------------------------------------------------------------------

class Point
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    bool Move ( int x, int y );
    // Mode d'emploi :
    //  déplace le point de x en abscisse et y en ordonnée

//-------------------------------------------- Constructeurs - destructeur
    Point ( int x, int y );

    virtual ~Point ( );

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes publiques

//----------------------------------------------------- Attributs protégés

    int x; // abscisse du poit
	int y; // ordonnée du point


};

//--------------------------- Autres définitions dépendantes de <Point>

#endif // POINT_H_



