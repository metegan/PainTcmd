/*************************************************************************
                           Objet_agrege  -  description
                             -------------------
    début                :  3 jan. 2014
    copyright            :
*************************************************************************/

//---------- Réalisation de la classe Objet_agrege (fichier Objet_agrege.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système

using namespace std;
#include <iostream>
#include <stdlib.h>
//------------------------------------------------------ Include personnel
#include "Objet_agrege.h"


//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

    string Objet_agrege::Get_cmd( Objet* obj, string name )
    {
        string cmd = type + " " + name;
        for(iterset it = objets.begin(); it != objets.end(); it++)
            cmd += " " + *it;

        return cmd;
    }

    bool Objet_agrege::Move ( int x, int y )
    {
        for(iterset it = objets.begin(); it != objets.end(); it++)
            if( !dessin_pere->Move(*it,x,y) ) return false;

        return true;

    }

    bool Objet_agrege::Move ( int x, int y, string name )
    {
        vector<string> already_moved = dessin_pere->Get_already_moved();
        dessin_pere->Add_already_moved(name);
        if( already_moved.size() < 1 )
        {
            for(iterset it = objets.begin(); it != objets.end(); it++)
            {
                if( already_moved.size() > 0 )
                {
                    for(unsigned int j=0; j<already_moved.size(); j++ )
                    {
                        if( !it->compare(already_moved[j]) )
                            break;
                        if( j == already_moved.size()-1 )
                            if( !dessin_pere->Move(*it,x,y) ) return false;
                        already_moved = dessin_pere->Get_already_moved();
                    }
                }
                else
                    if( !dessin_pere->Move(*it,x,y) ) return false;
                already_moved = dessin_pere->Get_already_moved();
            }
        }
        else
        {
            for(iterset it = objets.begin(); it != objets.end(); it++)
            {
                for(unsigned int j=0; j<already_moved.size(); j++ )
                {
                    if( !name.compare(already_moved[j]) )
                        return false;
                    if( !it->compare(already_moved[j]) )
                        break;
                    if( j == already_moved.size()-1 )
                    {
                        if( !dessin_pere->Move(*it,x,y) )
                            return false;
                    }
                }
            }
        }
        return true;

    }

    bool Objet_agrege::Add( string name )
    {
        objets.insert(name);
        return true;
    }

    set<string>* Objet_agrege::Get_objets_names( ) { return &objets; }

//-------------------------------------------- Constructeurs - destructeur
    Objet_agrege::Objet_agrege ( vector<string> cmd, Dessin* pere )
    {
        dessin_pere = pere;
        for( unsigned int i=2; i < cmd.size(); i++ )
            objets.insert( cmd[i] );
    }

    Objet_agrege::Objet_agrege ( ) { }

    Objet_agrege::~Objet_agrege ( ) {
#ifdef MAP
    cout << "Appel au destructeur de <Objet_agrege>" << endl;
#endif
}

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées


