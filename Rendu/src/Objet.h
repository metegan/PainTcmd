/*************************************************************************
                           Objet  -  description
                             -------------------
    début                : 11 oct. 2013
    copyright            : (C) 2013 par hhannetel
*************************************************************************/

//---------- Interface de la classe <Objet> (fichier Objet.h) ------
#if ! defined ( OBJET_H_ )
#define OBJET_H_

//--------------------------------------------------- Interfaces utilisées
#include <string>
#include <vector>
using namespace std;






//------------------------------------------------------------------------
// Rôle de la classe <Objet>
//
//------------------------------------------------------------------------

class Objet
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    virtual bool Move ( int x, int y ) = 0;
    // Mode d'emploi :
    //  déplace la objet de x en abscisse et y en ordonnée
    //  retourne 0 si le déplacement est impossible

    virtual string Get_cmd( Objet* obj, string name ) = 0;
    // Mode d'emploi :
    //  génère la commande qui a permis la création la objet


    void Set_type( string t );

    string Get_type();


//-------------------------------------------- Constructeurs - destructeur

    Objet ();

    virtual ~Objet ( );


//------------------------------------------------------------------ PRIVE
protected:
//----------------------------------------------------- Attributs protégés
   	string type; // type de l'objet


};

//--------------------------- Autres définitions dépendantes de <Objet>

#endif // OBJET_H_



