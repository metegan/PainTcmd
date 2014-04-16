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
#include "Objet.h"
#include "Point.h"
using namespace std;

typedef vector<Point>::iterator itv;





//------------------------------------------------------------------------
// Rôle de la classe <Figure>
//
//------------------------------------------------------------------------

class Figure : public Objet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    bool Move ( int x, int y );
    // Mode d'emploi :
    //  déplace la figure de x en abscisse et y en ordonnée
    //  retourne 0 si le déplacement est impossible

    string Get_cmd( Objet* obj, string name );
    // Mode d'emploi :
    //  génère la commande qui a permis la création la figure


    void Add_point( Point& p );

    void Set_type( string t );


//-------------------------------------------- Constructeurs - destructeur
    Figure ( vector<string> cmd );

    Figure ();

    virtual ~Figure ( );


//------------------------------------------------------------------ PRIVE
protected:
//----------------------------------------------------- Attributs protégés


	vector<Point> set_of_points; // points qui définissent la figure


};

//--------------------------- Autres définitions dépendantes de <Figure>

#endif // FIGURE_H_


