/*************************************************************************
                           Dessin  -  description
                             -------------------
    début                : 15 nov. 2013
    copyright            : (C) 2013 par hhannetel
*************************************************************************/

//---------- Réalisation de la classe <Dessin> (fichier Dessin.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <string>
#include <iostream>
#include <fstream>

//------------------------------------------------------ Include personnel

#include "Dessin.h"
#include "Figure.h"
#include "StringExt.h"
#include "Point.h"
#include "Rectangle.h"
#include "Cercle.h"
#include "Polyligne.h"
#include "ligne.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
bool Dessin::Delete ( string nom_figure )
// Algorithme :
//
{
    if( figure_set.find(nom_figure) == figure_set.end() )
        { figure_set.erase( nom_figure ); }
    else
        { return false; }
    return true;
}

bool Dessin::Add ( Figure new_figure, string figure_name )
// Algorithme :
//
{
    if( figure_set.find(figure_name) == figure_set.end() )
        { return false; }
    else
        { figure_set[figure_name] = new_figure; }
    return true;
}

bool Dessin::Load ( string file_name, string cmd, Dessin dessin )
// Algorithme :
//
{
    vector <string> cmd_split;
    Figure* new_fig;
    ifstream file;
    file.open( file_name );
    if( file.is_open() )
    {
        while( getline(file,cmd) )
        {
            cmd_split = split(cmd, ' ');
            new_fig = new Figure(cmd_split);
            dessin.Add(*new_fig, cmd_split[1]);
        }
        return true;
    }
    return false;
}

bool Dessin::Save( string file_name )
    {

    }

bool Dessin::Clear( )
    {
        figure_set.clear();
    }

void Dessin::Display( )
    {

        for(iter it = figure_set.begin();it!=figure_set.end();it++)
        {
            cout<<it->second.Get_cmd(it->first)<<endl;
        }
    }
Figure Dessin::Create_figure( vector<string> cmd )
{
        Figure* fig = new Figure();

        if(cmd[0].compare("C"))
        {
           fig=new Cercle(cmd, atoi(cmd[4].c_str()));
        }
        else if(cmd[0].compare("R"))
        {
            Rectangle* fig=new Rectangle();
        }
        else if(cmd[0].compare("L"))
        {
            Ligne* fig=new Ligne();
        }
        else if(cmd[0].compare("PL"))
        {
            Polyligne* fig=new Polyligne();
        }
        else
        {
            return *fig;
        }
         fig->Set_type(cmd[0]);
         Point* p;
         for(int i=2;i<cmd.size();)
            {
                p=new Point(atoi(cmd[i++].c_str()),atoi(cmd[i++].c_str()));
                fig->Add_point(*p);
            }
          return *fig;
}

//-------------------------------------------- Constructeurs - destructeur
Dessin::Dessin ( )
{
#ifdef MAP
    cout << "Appel au constructeur de <Dessin>" << endl;
#endif
} //----- Fin de Dessin


Dessin::~Dessin ( )
{
#ifdef MAP
    cout << "Appel au destructeur de <Dessin>" << endl;
#endif
} //----- Fin de ~Dessin


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

