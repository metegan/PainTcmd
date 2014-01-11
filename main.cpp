#include <string>
#include "Dessin.h"
#include "Figure.h"
#include "StringExt.h"
#include <iostream>

using namespace std;

int main()
{
    Dessin* dessin = new Dessin();
    string cmd;
    string figure_name;
    vector<string> cmd_split;



    for( ;; )
    {
        cin >> cmd;
        cmd_split = split(cmd, ' ');

        if( cmd_split[0].compare("EXIT") )
            { break; }
        if(  cmd_split[0].compare("LOAD") )
                  { dessin->Load( cmd_split[1], cmd, *dessin ); }
        else
            { dessin->Create_figure(cmd_split); }
    }

    return 0;
}
