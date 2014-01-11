/*************************************************************************
                           Dessin  -  description
                             -------------------
    début                : 11 oct. 2013
    copyright            : (C) 2013 par hhannetel
*************************************************************************/

//---------- Interface de la classe <Dessin> (fichier Dessin.h) ------
#if ! defined ( DESSIN_H_ )
#define DESSIN_H_

//--------------------------------------------------- Interfaces utilisées
#include <unordered_map>
#include <string>
#include "Figure.h"
//--------------------------------------------------- Types personnels
typedef unordered_map<string,Figure*>::iterator iter;

using namespace std;
//------------------------------------------------------------------------
// Rôle de la classe <Dessin>
//
//------------------------------------------------------------------------

class Dessin
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques

    bool Add ( Figure* new_figure, string figure_name );
    // Mode d'emploi :
    //  Ajoute la figure passé en paramètre au dessin
    //  Retourne Faux si l'ajout a échoué

    //bool Load( string file_name ); //TODO load only new figures
    // Mode d'emploi :
    //  Charge le dessin contenu dans le fichier passé en paramètre
    //  Retourne Faux si le chargement a échoué

    bool Save( string file_name ); //TODO save only modifications
    // Mode d'emploi :
    //  Enregistre le dessin dans le fichier passé en paramètre
    //  Retourne Faux si l'enregistrement a échoué

    bool Load( string file_name, string cmd, Dessin dessin ); //TODO save only modifications
    // Mode d'emploi :
    //  Charge les figures contenues dans le fichier passé en paramètre
    //  Retourne Faux si le chargement a échoué

    bool Delete( string figure_name );
    // Mode d'emploi :
    //  Supprime du dessin la figure passée en paramètre
    //  Retourne Faux si la suppression a échoué
    // Contrat :
    //  La méthode se charge de vérifier si la igure existe ou non.

    bool Clear( );
    // Mode d'emploi :
    //  Supprime toutes les figures du dessin courant
    //  Retourne Faux si la suppression a échoué

    void Display( );
    // Mode d'emploi :
    //  Affiche les commandes qui ont généré le dessin

    Figure* Create_figure( vector<string> cmd );
    // Mode d'emploi :
    //  Crée la figure correspondante et la retourne

    bool Move(string figure_name, int dx, int dy );
    // Mode d'emploi :
    //  Supprime toutes les figures du dessin courant
    //  Retourne Faux si la suppression a échoué


//-------------------------------------------- Constructeurs - destructeur
    Dessin ( );

    virtual ~Dessin ( );

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Méthodes publiques

//----------------------------------------------------- Attributs protégés

    unordered_map<string, Figure*> figure_set; // ensemble des figures
                                                  // qui constituent les dessin

};

//--------------------------- Autres définitions dépendantes de <Dessin>

#endif // DESSIN_H_





