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
#include <vector>
#include "Figure.h"
//--------------------------------------------------- Types personnels
typedef unordered_map<string,Figure*>::iterator iter;
typedef unordered_map<string,vector<string>>::iterator itoa;
typedef vector<string>::iterator itvstr;

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

    bool Add_oa( vector<string> cmd_split );
    //Mode d'emploi:
    //

    bool Save( string file_name ); //TODO save only modifications
    // Mode d'emploi :
    //  Enregistre le dessin dans le fichier passé en paramètre
    //  Retourne Faux si l'enregistrement a échoué

    bool Load( string file_name, string cmd); //TODO save only modifications
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
    void Set_last_cmd(vector<string> cmd);
    // Mode d'emploi :
    //  Met à jour la dernière commande qui a modifié le dessin
    vector<string> Get_last_cmd();
    // Mode d'emploi :
    //  Retourne la dernière commande qui a modifié le dessin
    void Undo();

//-------------------------------------------- Constructeurs - destructeur
    Dessin ( );

    virtual ~Dessin ( );

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Attributs protégés

    vector<string> last_cmd;
    Figure* last_erased;
    unordered_map<string, Figure*> figure_set; // ensemble des figures
                                                  // qui constituent les dessin
    unordered_map<string, Figure*> old_figure_set; // ensemble des figures
                                                  // qui constituent les dessin
    unordered_map<string, vector<string>> oa_set; //ensemble des objets agrégés

};

//--------------------------- Autres définitions dépendantes de <Dessin>

#endif // DESSIN_H_





