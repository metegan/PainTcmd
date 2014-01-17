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
    if( figure_set.find(nom_figure) != figure_set.end() )
        {
            last_erased = figure_set[nom_figure];
            figure_set.erase( nom_figure );
            }
    else
        { return false; }
    return true;
}

bool Dessin::Add ( Figure* new_figure, string figure_name )
// Algorithme :
//
{
    if( figure_set.size() == 0)
        { figure_set[figure_name] = new_figure; }
    else
    {
       if( figure_set.find(figure_name) != figure_set.end() )
        { return false; }
        else
        { figure_set[figure_name] = new_figure; }
    }
    return true;
}

bool Dessin::Load ( string file_name, string cmd)
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
            new_fig = Create_figure(cmd_split);
            Add(new_fig, cmd_split[1]);

        }
        cout<<"ok"<<endl;
        return true;
    }
    cout<<"fichier non ouvert \n";
    return false;
}

bool Dessin::Save( string file_name )
{
    ofstream fichier(file_name, ios::out | ios::trunc);  // ouverture en écriture avec effacement du fichier ouvert
    if(fichier)
        {
            for(iter it = figure_set.begin(); it != figure_set.end(); it++)
            {
                fichier<<it->second->Get_cmd(it->second,it->first)<<endl;
            }
            fichier.close();
        }
    else
    {
        cerr << "Impossible d'ouvrir le fichier !" << endl;
        return false;
    }
    cout<<"ok"<<endl;
    return true;

}

bool Dessin::Clear( )
    {
        old_figure_set=figure_set;
        figure_set.clear();
        return true;
    }

void Dessin::Display( )
{

    for(iter it = figure_set.begin(); it != figure_set.end(); it++)
    {
        cout << it->second->Get_cmd(it->second,it->first) << endl;
    }
}

Figure* Dessin::Create_figure( vector<string> cmd )
{
        Figure* fig;
        Point* p;

        if(!cmd[0].compare("C"))
        {
            fig=new Cercle(cmd, atoi(cmd[4].c_str()));
            p=new Point( atoi(cmd[2].c_str()), atoi(cmd[3].c_str()) );
            fig->Add_point(*p);
            fig->Set_type(cmd[0]);
            return fig;

        }
        else if(!cmd[0].compare("R"))
        {
            fig=new Rectangle();
        }
        else if(!cmd[0].compare("L"))
        {
            fig=new Ligne();
        }
        else if(!cmd[0].compare("PL"))
        {
            fig=new Polyligne();
        }
        else
        {
            return fig;
        }
         fig->Set_type(cmd[0]);
         for(int i=2;i<cmd.size();i++)
            {
                p=new Point( atoi(cmd[i].c_str()), atoi(cmd[i+1].c_str()) );
                i++;
                fig->Add_point(*p);
            }
          return fig;
}

bool Dessin::Move(string figure_name, int dx, int dy )
{
    if ( figure_set.find(figure_name) == figure_set.end() )
        { return false; }
    else
        { figure_set[figure_name]->Move(dx, dy); }
    return true;
}

void Dessin::Set_last_cmd(vector<string> cmd)
{
    last_cmd=cmd;
}

vector<string> Dessin::Get_last_cmd()
{
    return last_cmd;
}
void Dessin::Undo()
{
        if( !last_cmd[0].compare("LOAD") )
        {
            ifstream file;
            file.open(last_cmd[1]);
            if( file.is_open() )
            {
                string cmd;
                vector<string> cmd_split;
                while( getline(file,cmd) )
                {
                    cmd_split = split(cmd, ' ');
                    Delete(cmd_split[1]);
                }
             }
        }
        if( !last_cmd[0].compare("MOVE") )
        {
            Move(last_cmd[1], atoi(last_cmd[2].c_str())*(-1), atoi(last_cmd[3].c_str())*(-1));
        }
        if( !last_cmd[0].compare("DELETE") )
        {
            Add(last_erased, last_cmd[1]);//TODO ecraser reellement en memoire pas juste pointeur
        }
        if( !last_cmd[0].compare("CLEAR") )
        {
            figure_set=old_figure_set;
        }
        else
        {
            Delete(last_cmd[1]);
        }

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

