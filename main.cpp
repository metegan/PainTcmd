#include <iostream>
#include "Dessin.h"
#include "Figure.h"
#include "StringExt.h"
#include <string>
using namespace std;

int main()
{
    Dessin* dessin = new Dessin();
    string commande;



    for( ;; )
    {
        cin>>commande;
        if(commande.compare("EXIT"))
            { break; }
        else
        {
            Figure* figure = new Figure( split(commande, ' ') );
            dessin->Add(figure);
        }
    }

    return 0;
}
