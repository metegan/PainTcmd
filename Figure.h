/*************************************************************************
                           Figure  -  description
                             -------------------
    début                : 11 oct. 2013
    copyright            : (C) 2013 par hhannetel
*************************************************************************/

//---------- Interface de la classe <Figure> (fichier Figure.h) ------
#if ! defined ( FIGURE_H_ )
#define FIGURE_H_

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <vector>
#include "Point.h"
using namespace std;

typedef vector<Point>::iterator itv;





//------------------------------------------------------------------------
// Rôle de la classe <Figure>
//
//------------------------------------------------------------------------

class Figure
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    bool Move ( string nom, int x, int y );
    // Mode d'emploi :
    //  déplace la figure de x en abscisse et y en ordonnée
    //  retourne 0 si le déplacement est impossible

    string Get_cmd( string name );
    // Mode d'emploi :
    //  génère la commande qui a permis la création la figure


    virtual void Display( );
    // Mode d'emploi :
    //  affiche le nom de la figure

    void Add_point( Point& p );

    void Set_type( string t );


//-------------------------------------------- Constructeurs - destructeur
    Figure ( vector<string> cmd );

    Figure ();

    virtual ~Figure ( );


//------------------------------------------------------------------ PRIVE
protected:
//----------------------------------------------------- Attributs protégés


   	string type; // type de la figure
	vector<Point> set_of_points; // points qui définissent la figure


};

//--------------------------- Autres définitions dépendantes de <Figure>

#endif // FIGURE_H_


