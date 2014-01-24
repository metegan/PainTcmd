/*************************************************************************
                           Objet_agrege  -  description
                             -------------------
    début                : 11 oct. 2013
    copyright            : (C) 2013 par hhannetel
*************************************************************************/

//---------- Interface de la classe <Objet_agrege> (fichier Objet_agrege.h) ------
#if ! defined ( OBJET_AGREGE_H_ )
#define OBJET_AGREGE_H_

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <vector>

#include "Objet.h"
#include "Dessin.h"
using namespace std;





//------------------------------------------------------------------------
// Rôle de la classe <Objet_agrege>
//
//------------------------------------------------------------------------

class Objet_agrege : public Objet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    bool Move ( int x, int y );
    // Mode d'emploi :
    //  déplace la objet_agrege de x en abscisse et y en ordonnée
    //  retourne 0 si le déplacement est impossible

    string Get_cmd( Objet* obj, string name );
    // Mode d'emploi :
    //  génère la commande qui a permis la création la objet_agrege

    vector<string>* Get_objets_names( );


//-------------------------------------------- Constructeurs - destructeur

    Objet_agrege ( vector<string> cmd, Dessin* pere );

    Objet_agrege ( );

    virtual ~Objet_agrege ( );


//------------------------------------------------------------------ PRIVE
protected:
//----------------------------------------------------- Attributs protégés


   	vector<string> objets; // liste des objets qui composent l'OA
   	Dessin* dessin_pere;


};

//--------------------------- Autres définitions dépendantes de <Objet_agrege>

#endif // OBJET_AGREGE_H_



