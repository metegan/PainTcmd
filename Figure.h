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
using namespace std;


//------------------------------------------------------------------------
// Rôle de la classe <Figure>
//
//------------------------------------------------------------------------

class Figure
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    virtual bool Move ( string nom, int x, int y );
    // Mode d'emploi :
    //  déplace la figure de x en abscisse et y en ordonnée
    //  retourne 0 si le déplacement est impossible

    virtual string Get_cmd( );
    // Mode d'emploi :
    //  génère la commande qui a permis la création la figure


    virtual void Display( );
    // Mode d'emploi :
    //  affiche le nom de la figure

//-------------------------------------------- Constructeurs - destructeur
    virtual Figure ( vector<string> cmd );

    virtual Figure ( );

    virtual ~Figure ( );

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes publiques

//----------------------------------------------------- Attributs protégés

    string name; // nom de la figure
	string type; // type de la figure
	vector<Point> set_of_points; // points qui définissent la figure


};

//--------------------------- Autres définitions dépendantes de <Figure>

#endif // FIGURE_H_


