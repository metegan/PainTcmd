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
#include <set>
#include <string>
#include <vector>
#include "Objet.h"
//--------------------------------------------------- Types personnels
typedef unordered_map<string,Objet*>::iterator iter;
typedef vector<string>::iterator itvstr;
typedef set<string>::iterator iterset;

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

    bool Add ( Objet* new_objet, string objet_name );
    // Mode d'emploi :
    //  Ajoute la objet passé en paramètre au dessin
    //  Retourne Faux si l'ajout a échoué

    bool Save( string file_name ); //TODO save only modifications
    // Mode d'emploi :
    //  Enregistre le dessin dans le fichier passé en paramètre
    //  Retourne Faux si l'enregistrement a échoué

    bool Load( string file_name, string & cmd); //TODO save only modifications
    // Mode d'emploi :
    //  Charge les objets contenues dans le fichier passé en paramètre
    //  Retourne Faux si le chargement a échoué

    bool Delete( vector<string> objet_name );
    // Mode d'emploi :
    //  Supprime du dessin la objet passée en paramètre
    //  Retourne Faux si la suppression a échoué
    // Contrat :
    //  La méthode se charge de vérifier si la igure existe ou non.

    bool Clear( );
    // Mode d'emploi :
    //  Supprime toutes les objets du dessin courant
    //  Retourne Faux si la suppression a échoué

    void Display( );
    // Mode d'emploi :
    //  Affiche les commandes qui ont généré le dessin

    Objet* Create_objet( vector<string> cmd );
    // Mode d'emploi :
    //  Crée la objet correspondante et la retourne

    bool Move(string objet_name, int dx, int dy );
    // Mode d'emploi :
    //  Supprime toutes les objets du dessin courant
    //  Retourne Faux si la suppression a échoué
    void Set_last_cmd(vector<string> cmd);
    // Mode d'emploi :
    //  Met à jour la dernière commande qui a modifié le dessin
    //vector<string> Get_last_cmd();
    // Mode d'emploi :
    //  Retourne la dernière commande qui a modifié le dessin
    int Get_last_cmd_len();
    int Get_cmd_redo_len();
    int Get_size();
    void Undo();
    void Clear_move( );


    vector<string> Redo();

    vector<string> Get_already_moved();

    void Add_already_moved(string nom);

   // int gs();

//-------------------------------------------- Constructeurs - destructeur
    Dessin ( );

    virtual ~Dessin ( );

//------------------------------------------------------------------ PRIVE

private:
//----------------------------------------------------- Attributs protégés

    int cpt_undo;
    vector< vector<string> > last_cmd;
    vector< vector<string> > cmd_redo;
    vector< pair<Objet*, vector<string>> > last_erased;
    unordered_map<string, Objet*> objet_set; // ensemble des objets
                                                  // qui constituent les dessin
    vector<unordered_map<string, Objet*>> old_objet_set; // ancien ensemble des objets
    vector<string> already_moved;

};

//--------------------------- Autres définitions dépendantes de <Dessin>

#endif // DESSIN_H_





