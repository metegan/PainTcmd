/*************************************************************************
                           Objet  -  description
                             -------------------
    début                :  3 jan. 2014
    copyright            :
*************************************************************************/

//---------- Réalisation de la classe Objet (fichier Objet.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

//------------------------------------------------------ Include personnel
#include "Objet.h"
#include <iostream>
using namespace std;
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques



    void Objet::Set_type( string t ) { type = t; }

    string Objet::Get_type() { return type; }

    Objet::Objet ( ) { }

    Objet::~Objet ( ) {
#ifdef MAP
    cout << "Appel au destructeur de <Objet>" << endl;
#endif
}
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


