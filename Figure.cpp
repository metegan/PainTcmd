/*************************************************************************
                           Figure  -  description
                             -------------------
    début                :  3 jan. 2014
    copyright            :
*************************************************************************/

//---------- Réalisation de la classe Figure (fichier Figure.cpp) -------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "Figure.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
    Figure::Figure ( vector<string> cmd )
    {
        name=cmd(1);
        if(cmd(0)=='C')
        {
            type="Cercle";
            Point p=new Point(cmd(2),cmd(3));
            Cercle c=new Cercle(p, cmd(4));
            Dessin.add(c);
        }
        else if(cmd(0)=='R')
        {
            type="Rectangle";
            Point bas=new Point(cmd(2),cmd(3));
            Point haut=new Point(cmd(4),cmd(5));
            Rectangle r=new Rectangle(bas,haut);
            Dessin.add(r);
        }
        else if(cmd(0)=='L')
        {
            type="Ligne";
            Point debut=new Point(cmd(2),cmd(3));
            Point fin=new Point(cmd(4),cmd(5));
            Ligne l=new Ligne(debut,fin);
            Dessin.add(l);
        }
        else if(cmd(0)=='PL')
        {
            type="Polyligne";
            //int nbPoints = cmd.size()/2 - 1;
            Polyligne pl=new Polyligne();
            for(int i=2;i<cmd.size();)
            {
                Point p=new Point(cmd(i++),cmd(i++));
                pl.set_of_points.push_back(p);
            }

        }


    }
//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

